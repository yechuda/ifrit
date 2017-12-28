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

template <>
InputParameters
validParams<ElectricPowerPostprocessor>()
{
  InputParameters params = validParams<GeneralPostprocessor>();
  params.addRequiredParam<Real>("pair_number", "The number of thermoelectric pairs in TE module.");
  params.addRequiredParam<PostprocessorName>("voltage_drop", "The name of the postprocessor that calculates voltage drop.");
  params.addRequiredParam<PostprocessorName>("current", "The name of the postprocessor that calculates electric current.");

  return params;
}

ElectricPowerPostprocessor::ElectricPowerPostprocessor(const InputParameters & parameters)
  : GeneralPostprocessor(parameters),
    _pair_number(getParam<Real>("pair_number")),
    _voltage_drop(getPostprocessorValue("voltage_drop")),
    _current(getPostprocessorValue("current"))
{
}

void
ElectricPowerPostprocessor::initialize()
{
}

void
ElectricPowerPostprocessor::execute()
{
}

PostprocessorValue
ElectricPowerPostprocessor::getValue()
{
  return _pair_number * _voltage_drop * std::abs(_current);
}
