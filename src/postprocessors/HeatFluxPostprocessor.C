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

#include "HeatFluxPostprocessor.h"
registerMooseObject("IfritApp", HeatFluxPostprocessor);

template <>
InputParameters
validParams<HeatFluxPostprocessor>()
{
  InputParameters params = validParams<SideIntegralVariablePostprocessor>();
  params.addRequiredParam<std::string>("thermal_conductivity", "The name of the thermal conductivity material property that will be used in the flux computation.");
  params.addRequiredParam<Real>("pair_number", "The number of thermoelectric pairs in TE module.");
  params.addRequiredParam<Real>("z_dim", "Perpendicular dimension");
  return params;
}

HeatFluxPostprocessor::HeatFluxPostprocessor(const InputParameters & parameters)
  : SideIntegralVariablePostprocessor(parameters),
    _conductivity(parameters.get<std::string>("thermal_conductivity")),
    _cond_coef(getMaterialProperty<Real>(_conductivity)),
    _pair_number(getParam<Real>("pair_number")),
    _z_dim(getParam<Real>("z_dim"))
{
}

Real
HeatFluxPostprocessor::computeQpIntegral()
{
  return -_pair_number * _z_dim * _cond_coef[_qp] * _grad_u[_qp] * _normals[_qp];
}
