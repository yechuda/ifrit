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

#include "ElectricalConduction.h"

template<>
InputParameters validParams<ElectricalConduction>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

ElectricalConduction::ElectricalConduction(const InputParameters & parameters) :
    Kernel(parameters),

    _sigma(getMaterialProperty<Real>("sigma"))
{
}

Real
ElectricalConduction::computeQpResidual()
{
  return _sigma[_qp] * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
ElectricalConduction::computeQpJacobian()
{
  return _sigma[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}
