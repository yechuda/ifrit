#ifndef IFRITAPP_H
#define IFRITAPP_H

#include "MooseApp.h"

class IfritApp : public MooseApp
{
public:
  static InputParameters validParams();

  IfritApp(const InputParameters & parameters);
  virtual ~IfritApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* IFRITAPP_H */
