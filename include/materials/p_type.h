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

#ifndef P_TYPE_H
#define P_TYPE_H

#include "Material.h"

//Forward Declarations
class p_type;

template<>
InputParameters validParams<p_type>();

/**
 * Material class that computes thermoelectric properties sigma (electrical conductivity),
 * lambda (thermal conductivity) and alpha (Seebeck coefficient) for (Bi0.25Sb0.75)Te3
 * p-type semiconductor vs temperature based on Wang X.-D., Huang Y.-X., Cheng C.-H.,
 * Lin D.T.-W., Kang C.-H.: A three-dimensional numerical modeling of thermoelectric
 * device with consideration of coupling of temperature field and electric potential field
 */

class p_type : public Material
{
public:
  p_type(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

private:
  MaterialProperty<Real> & _sigma;
  MaterialProperty<Real> & _lambda;
  MaterialProperty<Real> & _alpha;
  MaterialProperty<RealGradient> & _grad_alpha;

  const VariableValue & _temperature;
  const VariableGradient & _grad_temperature;
};

#endif //P_TYPE_H
