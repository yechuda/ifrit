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

#include "ElectricPowerPostprocessor.h"

template<>
InputParameters validParams<ElectricPowerPostprocessor>()
{
  InputParameters params = validParams<SideIntegralVariablePostprocessor>();
  params.addRequiredParam<Real>("z_dim", "Perpendicular dimension.");
  params.addRequiredParam<Real>("voltage_drop", "The value of voltage drop on single TE pair.");
  params.addRequiredParam<Real>("pair_number", "The number of thermoelectric pairs in TE module.");
  params.addRequiredCoupledVar("temperature", "The coupled variable of temperature");
  return params;
}

ElectricPowerPostprocessor::ElectricPowerPostprocessor(const InputParameters & parameters) :
    SideIntegralVariablePostprocessor(parameters),
    _z_dim(getParam<Real>("z_dim")),
    _voltage_drop(getParam<Real>("voltage_drop")),
    _pair_number(getParam<Real>("pair_number")),
    _grad_temperature(coupledGradient("temperature")),
    _sigma(getMaterialProperty<Real>("sigma")),
    _alpha(getMaterialProperty<Real>("alpha"))
{}

Real
ElectricPowerPostprocessor::computeQpIntegral()
{
  return _pair_number * _voltage_drop * std::abs(_z_dim * _sigma[_qp] * (_grad_u[_qp] + _alpha[_qp] * _grad_temperature[_qp]) * _normals[_qp]);
}
