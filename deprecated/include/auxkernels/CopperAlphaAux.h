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
#ifndef COPPERALPHAAUX_H
#define COPPERALPHAAUX_H

#include "AuxKernel.h"

class CopperAlphaAux;

template <>
InputParameters validParams<CopperAlphaAux>();

class CopperAlphaAux : public AuxKernel
{
public:
  CopperAlphaAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

private:

};

#endif // COPPERALPHAAUX_H
