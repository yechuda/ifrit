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

#ifndef CURRENTBC_H
#define CURRENTBC_H

#include "IntegratedBC.h"

class CurrentBC;

template<>
InputParameters validParams<CurrentBC>();

class CurrentBC : public IntegratedBC
{
public:

  CurrentBC(const InputParameters & parameters);

protected:

  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

private:

  const Real _z_dim;
  const Real _current;
  const VariableGradient & _grad_temperature;
  unsigned int _temperature_var;
  const MaterialProperty<Real> & _sigma;
  const MaterialProperty<Real> & _alpha;

};

#endif //CURRENTBC_H
