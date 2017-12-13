/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "PeltierThomsonEffectExplicit.h"

template<>
InputParameters validParams<PeltierThomsonEffectExplicit>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("voltage", "Voltage value");
  params.addRequiredCoupledVar("alpha", "Seebeck coefficient");
  params.addRequiredCoupledVar("grad_alpha_x", "x component of Seebeck coefficient gradient");
  params.addCoupledVar("grad_alpha_y", 0, "y component of Seebeck coefficient gradient"); // only required in 2D and 3D
  params.addCoupledVar("grad_alpha_z", 0, "z component of Seebeck coefficient gradient"); // only required in 3D
  return params;
}

PeltierThomsonEffectExplicit::PeltierThomsonEffectExplicit(const InputParameters & parameters) :
    Kernel(parameters),

    _grad_voltage(coupledGradient("voltage")),
    _voltage_var(coupled("voltage")),
    _sigma(getMaterialProperty<Real>("sigma")),
    _alpha(coupledValue("alpha")),
    _grad_alpha_x(coupledValue("grad_alpha_x")),
    _grad_alpha_y(coupledValue("grad_alpha_y")),
    _grad_alpha_z(coupledValue("grad_alpha_z")),
    _alpha_var(coupled("alpha")),
    _grad_alpha_x_var(coupled("grad_alpha_x")),
    _grad_alpha_y_var(coupled("grad_alpha_y")),
    _grad_alpha_z_var(coupled("grad_alpha_z"))
{
}

Real
PeltierThomsonEffectExplicit::computeQpResidual()
{
  RealVectorValue _grad_alpha(_grad_alpha_x[_qp], _grad_alpha_y[_qp], _grad_alpha_z[_qp]);
  return _sigma[_qp] * _u[_qp] * _grad_voltage[_qp] * _grad_alpha * _test[_i][_qp] +
         _sigma[_qp] * _alpha[_qp] * _u[_qp] * _grad_u[_qp] * _grad_alpha * _test[_i][_qp];
}

Real
PeltierThomsonEffectExplicit::computeQpJacobian()
{
  RealVectorValue _grad_alpha(_grad_alpha_x[_qp], _grad_alpha_y[_qp], _grad_alpha_z[_qp]);
  return _sigma[_qp] * _phi[_j][_qp] * _grad_voltage[_qp] * _grad_alpha * _test[_i][_qp] +
         _sigma[_qp] * _alpha[_qp] * _phi[_j][_qp] * _grad_u[_qp] * _grad_alpha * _test[_i][_qp]+
         _sigma[_qp] * _alpha[_qp] * _u[_qp] * _grad_phi[_j][_qp] * _grad_alpha * _test[_i][_qp];
}

Real
PeltierThomsonEffectExplicit::computeQpOffDiagJacobian(unsigned jvar)
{
  if (jvar == _voltage_var)
  {
    RealVectorValue _grad_alpha(_grad_alpha_x[_qp], _grad_alpha_y[_qp], _grad_alpha_z[_qp]);
    return _sigma[_qp] * _u[_qp] * _grad_phi[_j][_qp] * _grad_alpha * _test[_i][_qp];
  }
  else if (jvar == _alpha_var)
  {
    RealVectorValue _grad_alpha(_grad_alpha_x[_qp], _grad_alpha_y[_qp], _grad_alpha_z[_qp]);
    return _sigma[_qp] * _phi[_j][_qp] * _u[_qp] * _grad_u[_qp] * _grad_alpha * _test[_i][_qp];
  }
  else if (jvar == _grad_alpha_x_var)
  {
    return _sigma[_qp] * _u[_qp] * _grad_voltage[_qp](0) * _phi[_j][_qp] * _test[_i][_qp] +
           _sigma[_qp] * _alpha[_qp] * _u[_qp] * _grad_u[_qp](0) * _phi[_j][_qp] * _test[_i][_qp];
  }
  else if (jvar == _grad_alpha_y_var)
  {
    return _sigma[_qp] * _u[_qp] * _grad_voltage[_qp](1) * _phi[_j][_qp] * _test[_i][_qp] +
           _sigma[_qp] * _alpha[_qp] * _u[_qp] * _grad_u[_qp](1) * _phi[_j][_qp] * _test[_i][_qp];
  }
  else if (jvar == _grad_alpha_z_var)
  {
    return _sigma[_qp] * _u[_qp] * _grad_voltage[_qp](2) * _phi[_j][_qp] * _test[_i][_qp] +
           _sigma[_qp] * _alpha[_qp] * _u[_qp] * _grad_u[_qp](2) * _phi[_j][_qp] * _test[_i][_qp];
  }
  else
    return 0.0;
}
