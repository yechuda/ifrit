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
#include "NTypeAlphaAux.h"

template <>
InputParameters
validParams<NTypeAlphaAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("temperature", "Temperature variable.");
  return params;
}

NTypeAlphaAux::NTypeAlphaAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _temperature(coupledValue("temperature"))
{
}

Real NTypeAlphaAux::computeValue()
{
  Real T0 = 300.0;
  Real alpha0 = -2.23e-04;
  Real C1 = 5.62e-04;
  Real C2 = -4.65e-06;
  return alpha0 * (1.0 + C1 * (_temperature[_qp] - T0) + C2 * std::pow(_temperature[_qp] - T0, 2.0));
}
