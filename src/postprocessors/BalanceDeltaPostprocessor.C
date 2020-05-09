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
#include "BalanceDeltaPostprocessor.h"
registerMooseObject("IfritApp", BalanceDeltaPostprocessor);

template <>
InputParameters
validParams<BalanceDeltaPostprocessor>()
{
  InputParameters params = validParams<GeneralPostprocessor>();
  params.addRequiredParam<PostprocessorName>("cold_flux_postprocessor", "Cold flux postprocessor");
  params.addRequiredParam<PostprocessorName>("hot_flux_postprocessor", "Hot flux postprocessor");
  params.addRequiredParam<PostprocessorName>("electric_power_postprocessor", "Electric power postprocessor");

  return params;
}

BalanceDeltaPostprocessor::BalanceDeltaPostprocessor(const InputParameters & parameters)
  : GeneralPostprocessor(parameters),
    _cold_flux(getPostprocessorValue("cold_flux_postprocessor")),
    _hot_flux(getPostprocessorValue("hot_flux_postprocessor")),
    _electric_power(getPostprocessorValue("electric_power_postprocessor"))
{
}

void
BalanceDeltaPostprocessor::initialize()
{
}

void
BalanceDeltaPostprocessor::execute()
{
}

PostprocessorValue
BalanceDeltaPostprocessor::getValue()
{
  return std::abs(_hot_flux) - (std::abs(_cold_flux) + std::abs(_electric_power));
}
