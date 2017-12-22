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

#include "JouleHeating.h"

template<>
InputParameters validParams<JouleHeating>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("voltage", "Voltage value");
  return params;
}

JouleHeating::JouleHeating(const InputParameters & parameters) :
    Kernel(parameters),

    _grad_voltage(coupledGradient("voltage")),
    _voltage_var(coupled("voltage")),
    _sigma(getMaterialProperty<Real>("sigma")),
    _alpha(getMaterialProperty<Real>("alpha"))
{
}

Real
JouleHeating::computeQpResidual()
{
  return -_sigma[_qp] * _alpha[_qp] * _grad_u[_qp] * _grad_voltage[_qp] * _test[_i][_qp] -
          _sigma[_qp] * _grad_voltage[_qp] * _grad_voltage[_qp] * _test[_i][_qp];
}

Real
JouleHeating::computeQpJacobian()
{
  return -_sigma[_qp] * _alpha[_qp] * _grad_phi[_j][_qp] * _grad_voltage[_qp] * _test[_i][_qp];
}

Real
JouleHeating::computeQpOffDiagJacobian(unsigned jvar)
{
  if (jvar == _voltage_var)
    return -_sigma[_qp] * _alpha[_qp] * _grad_u[_qp] * _grad_phi[_j][_qp] * _test[_i][_qp] -
            2.0 * _sigma[_qp] * _grad_voltage[_qp] * _grad_phi[_j][_qp] * _test[_i][_qp];
  else
    return 0.0;
}
