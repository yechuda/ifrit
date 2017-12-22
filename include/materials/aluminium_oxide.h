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

#ifndef ALUMINIUM_OXIDE_H
#define ALUMINIUM_OXIDE_H

#include "Material.h"

//Forward Declarations
class aluminium_oxide;

template<>
InputParameters validParams<aluminium_oxide>();

class aluminium_oxide : public Material
{
public:
  aluminium_oxide(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

private:
  MaterialProperty<Real> & _sigma;
  MaterialProperty<Real> & _lambda;
  MaterialProperty<Real> & _alpha;
};

#endif //ALUMINIUM_OXIDE_H
