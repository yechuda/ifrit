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

#ifndef HEATTRANSFER_H
#define HEATTRANSFER_H

#include "Kernel.h"

class HeatTransfer;

template<>
InputParameters validParams<HeatTransfer>();

class HeatTransfer : public Kernel
{
public:
  HeatTransfer(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned jvar);

  const VariableGradient & _grad_voltage;
  unsigned _voltage_var;
  const MaterialProperty<Real> & _sigma;
  const MaterialProperty<Real> & _alpha;
  const MaterialProperty<Real> & _lambda;
};

#endif //HEATTRANSFER_H
