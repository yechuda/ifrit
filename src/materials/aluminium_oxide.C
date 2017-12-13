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

#include "aluminium_oxide.h"

template<>
InputParameters validParams<aluminium_oxide>()
{
  InputParameters params = validParams<Material>();

  return params;
}

aluminium_oxide::aluminium_oxide(const InputParameters & parameters) :
    Material(parameters),

    _sigma(declareProperty<Real>("sigma")),
    _lambda(declareProperty<Real>("lambda")),
    _alpha(declareProperty<Real>("alpha")),
    _grad_alpha(declareProperty<RealGradient>("grad_alpha")),
    _d_alpha_d_T(declareProperty<Real>("d_alpha_d_T")),

    _zero_gradient(_grad_zero)

{}

void
aluminium_oxide::computeQpProperties()
{
  _sigma[_qp] = 0.0;

  _lambda[_qp] = 30.0;

  _alpha[_qp] = 0.0;

  _grad_alpha[_qp] = _zero_gradient[_qp];

  _d_alpha_d_T[_qp] = 0.0;
}