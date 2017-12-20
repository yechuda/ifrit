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
#ifndef BALANCEDELTAPOSTPROCESSOR_H
#define BALANCEDELTAPOSTPROCESSOR_H

#include "GeneralPostprocessor.h"

class BalanceDeltaPostprocessor;

template <>
InputParameters validParams<BalanceDeltaPostprocessor>();

class BalanceDeltaPostprocessor : public GeneralPostprocessor
{
public:
  BalanceDeltaPostprocessor(const InputParameters & parameters);

  virtual void initialize() override;
  virtual void execute() override;
  virtual PostprocessorValue getValue() override;

protected:
  const PostprocessorValue & _cold_flux;
  const PostprocessorValue & _hot_flux;
  const PostprocessorValue & _electric_power;
};

#endif /* BALANCEDELTAPOSTPROCESSOR_H */
