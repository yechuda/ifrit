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

#include "CurrentPostprocessor.h"

template<>
InputParameters validParams<CurrentPostprocessor>()
{
  InputParameters params = validParams<SideIntegralVariablePostprocessor>();
  params.addRequiredCoupledVar("temperature", "The coupled variable of temperature");
  return params;
}

CurrentPostprocessor::CurrentPostprocessor(const InputParameters & parameters) :
    SideIntegralVariablePostprocessor(parameters),
    _grad_temperature(coupledGradient("temperature")),
    _sigma(getMaterialProperty<Real>("sigma")),
    _alpha(getMaterialProperty<Real>("alpha"))
{}

Real
CurrentPostprocessor::computeQpIntegral()
{
  return -_sigma[_qp] * (_grad_u[_qp] + _alpha[_qp] * _grad_temperature[_qp]) * _normals[_qp];
}
