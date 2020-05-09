#include "IfritApp.h"
#include "Factory.h"
#include "ActionFactory.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

// #include "Moose.h"
// #include "ModulesApp.h"

// Kernels
#include "ElectricalConduction.h"
#include "SeebeckEffect.h"
#include "HeatDiffusion.h"
#include "PeltierThomsonEffect.h"
#include "JouleHeating.h"

// BCs
#include "CurrentBC.h"

// Materials
#include "p_type.h"
#include "n_type.h"
#include "copper.h"
#include "air.h"
#include "aluminium_oxide.h"
#include "p_type_fit.h"
#include "n_type_fit.h"

// Postprocessors
#include "CurrentPostprocessor.h"
#include "HeatFluxPostprocessor.h"
#include "ElectricPowerPostprocessor.h"
#include "BalanceDeltaPostprocessor.h"

InputParameters
IfritApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  params.set<bool>("automatic_automatic_scaling") = false;

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

registerKnownLabel("IfritApp");

IfritApp::IfritApp(const InputParameters & parameters) : MooseApp(parameters)
{
  IfritApp::registerAll(_factory, _action_factory, _syntax);
}

IfritApp::~IfritApp()
{
}

void
IfritApp::registerApps()
{
  registerApp(IfritApp);
}

void
IfritApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Registry::registerObjectsTo(f, {"IfritApp"});
  Registry::registerActionsTo(af, {"IfritApp"});
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
IfritApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  IfritApp::registerAll(f, af, s);
}

extern "C" void
IfritApp__registerApps()
{
  IfritApp::registerApps();
}
