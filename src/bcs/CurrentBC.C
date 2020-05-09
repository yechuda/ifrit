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

#include "CurrentBC.h"
registerMooseObject("IfritApp", CurrentBC);

template <>
InputParameters
validParams<CurrentBC>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredParam<Real>("z_dim", "Out-of-plane depth");
  params.addRequiredParam<Real>("length", "Length of the boundary");
  params.addRequiredParam<Real>("current", "Electric current value");
  params.addRequiredCoupledVar("temperature", "The coupled variable of temperature");
  return params;
}

CurrentBC::CurrentBC(const InputParameters & parameters)
  : IntegratedBC(parameters),

  _z_dim(getParam<Real>("z_dim")),
  _length(getParam<Real>("length")),
  _current(getParam<Real>("current")),
  _grad_temperature(coupledGradient("temperature")),
  _temperature_var(coupled("temperature")),
  _sigma(getMaterialProperty<Real>("sigma")),
  _alpha(getMaterialProperty<Real>("alpha"))
{
}

Real
CurrentBC::computeQpResidual()
{
  return -_test[_i][_qp] * (-_current / (_z_dim * _length) - _alpha[_qp] * _grad_temperature[_qp] * _normals[_qp]);
}

Real
CurrentBC::computeQpJacobian()
{
  return 0.0;
}

Real
CurrentBC::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _temperature_var)
    return -_test[_i][_qp] * (-_alpha[_qp] * _grad_phi[_j][_qp] * _normals[_qp]);
  else
    return 0.0;
}
