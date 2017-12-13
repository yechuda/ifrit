#include "IfritApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

// Kernels
#include "ElectricalConduction.h"
#include "SeebeckEffect.h"
#include "HeatDiffusion.h"
#include "PeltierThomsonEffect.h"
#include "PeltierThomsonEffectExplicit.h"
#include "JouleHeating.h"

// BCs
#include "CurrentBC.h"

// AuxKernels
#include "HeatFluxAux.h"
#include "NTypeAlphaAux.h"
#include "PTypeAlphaAux.h"
#include "CopperAlphaAux.h"

// Materials
#include "p_type.h"
#include "n_type.h"
#include "copper.h"
#include "air.h"
#include "aluminium_oxide.h"

// Postprocessors
#include "CurrentPostprocessor.h"
#include "HeatFluxPostprocessor.h"

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
  // Kernels
  registerKernel(ElectricalConduction);
  registerKernel(SeebeckEffect);
  registerKernel(HeatDiffusion);
  registerKernel(PeltierThomsonEffect);
  registerKernel(JouleHeating);
  registerKernel(PeltierThomsonEffectExplicit);

  //BCs
  registerBoundaryCondition(CurrentBC);

  // AuxKernels
  registerAux(HeatFluxAux);
  registerAux(NTypeAlphaAux);
  registerAux(PTypeAlphaAux);
  registerAux(CopperAlphaAux);

  // Materials
  registerMaterial(p_type);
  registerMaterial(n_type);
  registerMaterial(copper);
  registerMaterial(air);
  registerMaterial(aluminium_oxide);

  // Postprocessors
  registerPostprocessor(CurrentPostprocessor);
  registerPostprocessor(HeatFluxPostprocessor);
}

// External entry point for dynamic syntax association
extern "C" void IfritApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { IfritApp::associateSyntax(syntax, action_factory); }
void
IfritApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
