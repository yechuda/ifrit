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

#ifndef SEEBECKEFFECT_H
#define SEEBECKEFFECT_H

#include "Kernel.h"

class SeebeckEffect;

template<>
InputParameters validParams<SeebeckEffect>();

class SeebeckEffect : public Kernel
{
public:
  SeebeckEffect(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned jvar);

  const VariableGradient & _grad_temperature;
  unsigned _temperature_var;
  const MaterialProperty<Real> & _sigma;
  const MaterialProperty<Real> & _alpha;
};

#endif //SEEBECKEFFECT_H
