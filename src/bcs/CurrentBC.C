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

template<>
InputParameters validParams<CurrentBC>()
{
  InputParameters params = validParams<IntegratedBC>();

  params.addRequiredParam<Real>("z_dim", "Perpendicular dimension");
  params.addRequiredParam<Real>("current", "Electric current value");
  params.addRequiredCoupledVar("temperature", "The coupled variable of temperature");
  return params;
}

CurrentBC::CurrentBC(const InputParameters & parameters) :
    IntegratedBC(parameters),
    _z_dim(getParam<Real>("z_dim")),
    _current(getParam<Real>("current")),
    _grad_temperature(coupledGradient("temperature")),
    _temperature_var(coupled("temperature")),
    _sigma(getMaterialProperty<Real>("sigma")),
    _alpha(getMaterialProperty<Real>("alpha"))
{}

Real CurrentBC::computeQpResidual()
{
  return -_z_dim * _sigma[_qp] * (_grad_u[_qp] + _alpha[_qp] * _grad_temperature[_qp]) * _normals[_qp] + _current;
}

Real CurrentBC::computeQpJacobian()
{
  return -_z_dim * _sigma[_qp] * _grad_phi[_j][_qp] * _normals[_qp];
}

Real CurrentBC::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _temperature_var)
    return -_z_dim * _sigma[_qp] * _alpha[_qp] * _grad_phi[_j][_qp] * _normals[_qp];
  return 0.0;
}
