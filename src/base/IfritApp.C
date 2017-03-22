#include "IfritApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<IfritApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

IfritApp::IfritApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  IfritApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  IfritApp::associateSyntax(_syntax, _action_factory);
}

IfritApp::~IfritApp()
{
}

// External entry point for dynamic application loading
extern "C" void IfritApp__registerApps() { IfritApp::registerApps(); }
void
IfritApp::registerApps()
{
  registerApp(IfritApp);
}

// External entry point for dynamic object registration
extern "C" void IfritApp__registerObjects(Factory & factory) { IfritApp::registerObjects(factory); }
void
IfritApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void IfritApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { IfritApp::associateSyntax(syntax, action_factory); }
void
IfritApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
