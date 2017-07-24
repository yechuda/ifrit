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

#ifndef HEATFLUXPOSTPROCESSOR_H
#define HEATFLUXPOSTPROCESSOR_H

// MOOSE includes
#include "SideIntegralVariablePostprocessor.h"

// Forward Declarations
class HeatFluxPostprocessor;

template <>
InputParameters validParams<HeatFluxPostprocessor>();

class HeatFluxPostprocessor : public SideIntegralVariablePostprocessor
{
public:
  HeatFluxPostprocessor(const InputParameters & parameters);

protected:
  virtual Real computeQpIntegral() override;

  std::string _conductivity;
  const MaterialProperty<Real> & _cond_coef;
  const Real _pair_number;
  const Real _z_dim;
};

#endif // HEATFLUXPOSTPROCESSOR_H
