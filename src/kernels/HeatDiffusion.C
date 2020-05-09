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

#include "HeatDiffusion.h"
registerMooseObject("IfritApp", HeatDiffusion);

template<>
InputParameters validParams<HeatDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

HeatDiffusion::HeatDiffusion(const InputParameters & parameters) :
    Kernel(parameters),

    _lambda(getMaterialProperty<Real>("lambda"))
{
}

Real
HeatDiffusion::computeQpResidual()
{
  return _lambda[_qp] * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
HeatDiffusion::computeQpJacobian()
{
  return _lambda[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}
