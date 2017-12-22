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

#include "copper.h"

template<>
InputParameters validParams<copper>()
{
  InputParameters params = validParams<Material>();

  return params;
}

copper::copper(const InputParameters & parameters) :
    Material(parameters),

    _sigma(declareProperty<Real>("sigma")),
    _lambda(declareProperty<Real>("lambda")),
    _alpha(declareProperty<Real>("alpha"))
{}

void
copper::computeQpProperties()
{
  Real rho = 1.7e-08;
  _sigma[_qp] = 1.0 / rho;

  _lambda[_qp] = 400.0;

  _alpha[_qp] = 6.5e-06;
}
