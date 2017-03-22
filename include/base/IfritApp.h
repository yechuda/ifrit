#ifndef IFRITAPP_H
#define IFRITAPP_H

#include "MooseApp.h"

class IfritApp;

template<>
InputParameters validParams<IfritApp>();

class IfritApp : public MooseApp
{
public:
  IfritApp(InputParameters parameters);
  virtual ~IfritApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* IFRITAPP_H */
