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

#include "p_type.h"

template<>
InputParameters validParams<p_type>()
{
  InputParameters params = validParams<Material>();

  params.addRequiredCoupledVar("temperature", "Temperature value");

  return params;
}

p_type::p_type(const InputParameters & parameters) :
    Material(parameters),

    _sigma(declareProperty<Real>("sigma")),
    _lambda(declareProperty<Real>("lambda")),
    _alpha(declareProperty<Real>("alpha")),
    _grad_alpha(declareProperty<RealGradient>("grad_alpha")),

    _temperature(coupledValue("temperature")),
    _grad_temperature(coupledGradient("temperature"))
{}

void
p_type::computeQpProperties()
{
  Real T0 = 300;

  Real rho0 = 8.826e-06;
  Real B1 = 5.88e-03;
  Real B2 = 8.93e-06;
  Real rho = rho0 * (1.0 + B1 * (_temperature[_qp] - T0) + B2 * std::pow(_temperature[_qp] - T0, 2.0));
  _sigma[_qp] = 1.0 / rho;

  Real lambda0 = 1.472;
  Real A1 = -1.29e-03;
  Real A2 = 1.35E-05;
  _lambda[_qp] = lambda0 * (1.0 + A1 * (_temperature[_qp] - T0) + A2 * std::pow(_temperature[_qp] - T0, 2.0));

  Real alpha0 = 2.207e-04;
  Real C1 = 1.55e-03;
  Real C2 = -3.15e-06;
  _alpha[_qp] = alpha0 * (1.0 + C1 * (_temperature[_qp] - T0) + C2 * std::pow(_temperature[_qp] - T0, 2.0));

  _grad_alpha[_qp] = (alpha0 * C1 + 2.0 * alpha0 * C2 * (_temperature[_qp] - T0)) * _grad_temperature[_qp];
}
