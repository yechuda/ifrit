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
#include "CopperAlphaAux.h"

template <>
InputParameters
validParams<CopperAlphaAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

CopperAlphaAux::CopperAlphaAux(const InputParameters & parameters)
  : AuxKernel(parameters)
{
}

Real CopperAlphaAux::computeValue()
{
  return 6.5e-06;
}
