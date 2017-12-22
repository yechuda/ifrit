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

#ifndef AIR_H
#define AIR_H

#include "Material.h"

//Forward Declarations
class air;

template<>
InputParameters validParams<air>();

class air : public Material
{
public:
  air(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

private:
  MaterialProperty<Real> & _sigma;
  MaterialProperty<Real> & _lambda;
  MaterialProperty<Real> & _alpha;
};

#endif //AIR_H
