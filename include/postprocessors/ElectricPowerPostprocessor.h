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
#ifndef ELECTRICPOWERPOSTPROCESSOR_H
#define ELECTRICPOWERPOSTPROCESSOR_H

#include "GeneralPostprocessor.h"

class ElectricPowerPostprocessor;

template <>
InputParameters validParams<ElectricPowerPostprocessor>();

class ElectricPowerPostprocessor : public GeneralPostprocessor
{
public:
  ElectricPowerPostprocessor(const InputParameters & parameters);

  virtual void initialize() override;
  virtual void execute() override;
  virtual PostprocessorValue getValue() override;

protected:
  const Real _pair_number;
  const PostprocessorValue & _voltage_drop;
  const PostprocessorValue & _current;
};

#endif /* ELECTRICPOWERPOSTPROCESSOR_H */
