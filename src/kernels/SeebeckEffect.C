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

#include "SeebeckEffect.h"

template<>
InputParameters validParams<SeebeckEffect>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("temperature", "Temperature value");
  return params;
}

SeebeckEffect::SeebeckEffect(const InputParameters & parameters) :
    Kernel(parameters),

    _grad_temperature(coupledGradient("temperature")),
    _temperature_var(coupled("temperature")),
    _sigma(getMaterialProperty<Real>("sigma")),
    _alpha(getMaterialProperty<Real>("alpha"))
{
}

Real
SeebeckEffect::computeQpResidual()
{
  return _sigma[_qp] * _alpha[_qp] * _grad_temperature[_qp] * _grad_test[_i][_qp];
}

Real
SeebeckEffect::computeQpJacobian()
{
  return 0.0;
}

Real
SeebeckEffect::computeQpOffDiagJacobian(unsigned jvar)
{
  if (jvar == _temperature_var)
    return _sigma[_qp] * _alpha[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
  else
    return 0.0;
}
