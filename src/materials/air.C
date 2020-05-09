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

#include "air.h"
registerMooseObject("IfritApp", air);

template<>
InputParameters validParams<air>()
{
  InputParameters params = validParams<Material>();

  return params;
}

air::air(const InputParameters & parameters) :
    Material(parameters),

    _sigma(declareProperty<Real>("sigma")),
    _lambda(declareProperty<Real>("lambda")),
    _alpha(declareProperty<Real>("alpha"))

{}

void
air::computeQpProperties()
{
  _sigma[_qp] = 0.0;

  _lambda[_qp] = 0.0262;

  _alpha[_qp] = 0.0;
}
