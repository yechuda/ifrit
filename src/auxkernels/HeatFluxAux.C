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
#include "HeatFluxAux.h"

template <>
InputParameters
validParams<HeatFluxAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("temperature", "Temperature variable.");
  params.addRequiredParam<std::string>("heat_conductivity", "The name of the heat conductivity material property that will be used in the flux computation.");
  params.addParam<int>("component", 0, "The flux component you want to see.");
  return params;
}

HeatFluxAux::HeatFluxAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _grad_T(coupledGradient("temperature")),
    _heat_conductivity(parameters.get<std::string>("heat_conductivity")),
    _conductivity_coef(getMaterialProperty<Real>(_heat_conductivity)),
    _component(getParam<int>("component"))
{
}

Real HeatFluxAux::computeValue()
{
  return -_conductivity_coef[_qp] * _grad_T[_qp](_component);
}
