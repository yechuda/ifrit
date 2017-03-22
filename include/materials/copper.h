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

#ifndef COPPER_H
#define COPPER_H

#include "Material.h"

//Forward Declarations
class copper;

template<>
InputParameters validParams<copper>();

/**
 * Material class that stores thermoelectric properties sigma (electrical conductivity),
 * lambda (thermal conductivity) and alpha (Seebeck coefficient) for copper
 */

class copper : public Material
{
public:
  copper(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

private:
  MaterialProperty<Real> & _sigma;
  MaterialProperty<Real> & _lambda;
  MaterialProperty<Real> & _alpha;
  MaterialProperty<RealGradient> & _grad_alpha;

  const VariableGradient & _zero_gradient;
};

#endif //COPPER_H
