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

#include "PeltierThomsonEffect.h"
registerMooseObject("IfritApp", PeltierThomsonEffect);

template<>
InputParameters validParams<PeltierThomsonEffect>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("voltage", "Voltage value");
  return params;
}

PeltierThomsonEffect::PeltierThomsonEffect(const InputParameters & parameters) :
    Kernel(parameters),

    _grad_voltage(coupledGradient("voltage")),
    _voltage_var(coupled("voltage")),
    _sigma(getMaterialProperty<Real>("sigma")),
    _alpha(getMaterialProperty<Real>("alpha"))
{
}

Real
PeltierThomsonEffect::computeQpResidual()
{
  return _sigma[_qp] * _alpha[_qp] * _u[_qp] * _grad_voltage[_qp] * _grad_test[_i][_qp] +
         _sigma[_qp] * std::pow(_alpha[_qp], 2.0) * _u[_qp] * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
PeltierThomsonEffect::computeQpJacobian()
{
  return _sigma[_qp] * _alpha[_qp] * _phi[_j][_qp] * _grad_voltage[_qp] * _grad_test[_i][_qp] +
         _sigma[_qp] * std::pow(_alpha[_qp], 2.0) * _phi[_j][_qp] * _grad_u[_qp] * _grad_test[_i][_qp] +
         _sigma[_qp] * std::pow(_alpha[_qp], 2.0) * _u[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}

Real
PeltierThomsonEffect::computeQpOffDiagJacobian(unsigned jvar)
{
  if (jvar == _voltage_var)
    return _sigma[_qp] * _alpha[_qp] * _u[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
  else
    return 0.0;
}
