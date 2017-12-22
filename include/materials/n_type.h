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

#ifndef N_TYPE_H
#define N_TYPE_H

#include "Material.h"

//Forward Declarations
class n_type;

template<>
InputParameters validParams<n_type>();

/**
 * Material class that computes thermoelectric properties sigma (electrical conductivity),
 * lambda (thermal conductivity) and alpha (Seebeck coefficient) for Bi2(Te0.94Se0.06)3
 * n-type semiconductor vs temperature based on Wang X.-D., Huang Y.-X., Cheng C.-H.,
 * Lin D.T.-W., Kang C.-H.: A three-dimensional numerical modeling of thermoelectric
 * device with consideration of coupling of temperature field and electric potential field
 */

class n_type : public Material
{
public:
  n_type(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

private:
  MaterialProperty<Real> & _sigma;
  MaterialProperty<Real> & _lambda;
  MaterialProperty<Real> & _alpha;

  const VariableValue & _temperature;
};

#endif //N_TYPE_H
