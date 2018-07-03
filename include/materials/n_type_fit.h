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

#ifndef N_TYPE_FIT_H
#define N_TYPE_FIT_H

#include "Material.h"

//Forward Declarations
class n_type_fit;

template<>
InputParameters validParams<n_type_fit>();

/**
 * Material class that computes thermoelectric properties lambda (thermal conductivity)
 * and alpha (Seebeck coefficient) for Bi2(Te0.94Se0.06)3 n-type semiconductor vs
 * temperature based on Wang X.-D., Huang Y.-X., Cheng C.-H., Lin D.T.-W., Kang C.-H.:
 * A three-dimensional numerical modeling of thermoelectric device with consideration
 * of coupling of temperature field and electric potential field. Sigma (electrical conductivity)
 * is taken from data fit of I-V curve of TM-127-1.4-3.7 TE module.
 */

class n_type_fit : public Material
{
public:
  n_type_fit(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

private:
  MaterialProperty<Real> & _sigma;
  MaterialProperty<Real> & _lambda;
  MaterialProperty<Real> & _alpha;

  const VariableValue & _temperature;
};

#endif //N_TYPE_FIT_H
