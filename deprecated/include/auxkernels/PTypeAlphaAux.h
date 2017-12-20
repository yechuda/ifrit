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
#ifndef PTYPEALPHAAUX_H
#define PTYPEALPHAAUX_H

#include "AuxKernel.h"

class PTypeAlphaAux;

template <>
InputParameters validParams<PTypeAlphaAux>();

class PTypeAlphaAux : public AuxKernel
{
public:
  PTypeAlphaAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

private:
  const VariableValue & _temperature;
};

#endif // PTYPEALPHAAUX_H
