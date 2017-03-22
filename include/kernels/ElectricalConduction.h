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

#ifndef ELECTRICALCONDUCTION_H
#define ELECTRICALCONDUCTION_H

#include "Kernel.h"

class ElectricalConduction;

template<>
InputParameters validParams<ElectricalConduction>();

class ElectricalConduction : public Kernel
{
public:
  ElectricalConduction(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  const MaterialProperty<Real> & _sigma;
};

#endif //ELECTRICALCONDUCTION_H
