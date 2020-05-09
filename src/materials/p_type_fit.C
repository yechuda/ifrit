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

#include "p_type_fit.h"
registerMooseObject("IfritApp", p_type_fit);

template<>
InputParameters validParams<p_type_fit>()
{
  InputParameters params = validParams<Material>();

  params.addRequiredCoupledVar("temperature", "Temperature value");

  return params;
}

p_type_fit::p_type_fit(const InputParameters & parameters) :
    Material(parameters),

    _sigma(declareProperty<Real>("sigma")),
    _lambda(declareProperty<Real>("lambda")),
    _alpha(declareProperty<Real>("alpha")),

    _temperature(coupledValue("temperature"))
{}

void
p_type_fit::computeQpProperties()
{
  Real T0 = 300.0;

  Real rho = 10.315651e-06;
  _sigma[_qp] = 1.0 / rho;

  Real lambda0 = 1.472;
  Real A1 = -1.29e-03;
  Real A2 = 1.35E-05;
  _lambda[_qp] = lambda0 * (1.0 + A1 * (_temperature[_qp] - T0) + A2 * std::pow(_temperature[_qp] - T0, 2.0));

  Real alpha0 = 2.207e-04;
  Real C1 = 1.55e-03;
  Real C2 = -3.15e-06;
  _alpha[_qp] = alpha0 * (1.0 + C1 * (_temperature[_qp] - T0) + C2 * std::pow(_temperature[_qp] - T0, 2.0));
}
