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
#ifndef HEATFLUXAUX_H
#define HEATFLUXAUX_H

#include "AuxKernel.h"

class HeatFluxAux;

template <>
InputParameters validParams<HeatFluxAux>();

class HeatFluxAux : public AuxKernel
{
public:
  HeatFluxAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

private:
  const VariableGradient & _grad_T;
  std::string _heat_conductivity;
  const MaterialProperty<Real> & _conductivity_coef;
  const int _component;
};

#endif // HEATFLUXAUX_H
