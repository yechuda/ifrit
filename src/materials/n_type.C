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

#include "n_type.h"

template<>
InputParameters validParams<n_type>()
{
  InputParameters params = validParams<Material>();

  params.addRequiredCoupledVar("temperature", "Temperature value");

  return params;
}

n_type::n_type(const InputParameters & parameters) :
    Material(parameters),

    _sigma(declareProperty<Real>("sigma")),
    _lambda(declareProperty<Real>("lambda")),
    _alpha(declareProperty<Real>("alpha")),
    _grad_alpha(declareProperty<RealGradient>("grad_alpha")),

    _temperature(coupledValue("temperature")),
    _grad_temperature(coupledGradient("temperature"))
{}

void
n_type::computeQpProperties()
{
  Real T0 = 300;

  Real rho0 = 8.239e-06;
  Real B1 = 4.7e-03;
  Real B2 = 2.67e-06;
  Real rho = rho0 * (1.0 + B1 * (_temperature[_qp] - T0) + B2 * std::pow(_temperature[_qp] - T0, 2.0));
  _sigma[_qp] = 1.0 / rho;

  Real lambda0 = 1.643;
  Real A1 = -9.8e-04;
  Real A2 = 1.56e-05;
  _lambda[_qp] = lambda0 * (1.0 + A1 * (_temperature[_qp] - T0) + A2 * std::pow(_temperature[_qp] - T0, 2.0));

  Real alpha0 = -2.23e-04;
  Real C1 = 5.62e-04;
  Real C2 = -4.65e-06;
  _alpha[_qp] = alpha0 * (1.0 + C1 * (_temperature[_qp] - T0) + C2 * std::pow(_temperature[_qp] - T0, 2.0));

  _grad_alpha[_qp] = (alpha0 * C1 + 2.0 * alpha0 * C2 * (_temperature[_qp] - T0)) * _grad_temperature[_qp];
}
