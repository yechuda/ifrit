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
#ifndef NTYPEALPHAAUX_H
#define NTYPEALPHAAUX_H

#include "AuxKernel.h"

class NTypeAlphaAux;

template <>
InputParameters validParams<NTypeAlphaAux>();

class NTypeAlphaAux : public AuxKernel
{
public:
  NTypeAlphaAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

private:
  const VariableValue & _temperature;
};

#endif // NTYPEALPHAAUX_H
