[Mesh]
  file = /home/yechuda/projects/ifrit/problems/TE-127-1.0-0.8/TE-127-1.0-0.8.e
[]

[Variables]
  [./voltage]
    order = FIRST
    family = LAGRANGE
    initial_condition = 0.0
  [../]

  [./temperature]
    order = FIRST
    family = LAGRANGE
    initial_condition = 283.15
  [../]
[]

[Kernels]
  [./electrical_conduction]
    type = ElectricalConduction
    variable = voltage
  [../]

  [./Seebeck_effect]
    type = SeebeckEffect
    variable = voltage
    temperature = temperature
  [../]

  [./heat_diffusion]
    type = HeatDiffusion
    variable = temperature
  [../]

  [./Peltier_Thomson_effect]
    type = PeltierThomsonEffect
    variable = temperature
    voltage = voltage
  [../]

  [./Joule_heating]
    type = JouleHeating
    variable = temperature
    voltage = voltage
  [../]
[]

[Materials]
  [./n_type]
    type = n_type
    block = 'n_type'
    temperature = temperature
  [../]

  [./p_type]
    type = p_type
    block = 'p_type'
    temperature = temperature
  [../]

  [./copper]
    type = copper
    block = 'copper'
  [../]
[]

[BCs]
  [./supply_terminal_voltage]
    type = DirichletBC
    variable = voltage
    boundary = 'supply_terminal'
    value = 0.094488
  [../]

  [./ground_terminal_voltage]
    type = DirichletBC
    variable = voltage
    boundary = 'ground_terminal'
    value = 0.0
  [../]

  [./top_temperature]
    type = DirichletBC
    variable = temperature
    boundary = 'top'
    value = 283.15
  [../]

  [./bottom_temperature]
    type = DirichletBC
    variable = temperature
    boundary = 'bottom_left bottom_right'
    value = 303.15
  [../]
[]

[Problem]
  type = FEProblem
  coord_type = XYZ
[]

[Preconditioning]
  [./smp]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  solve_type = 'PJFNK'
  type = Steady
  petsc_options = '-snes_converged_reason -ksp_converged_reason'

  #petsc_options_iname = '-pc_type -pc_factor_mat_solver_package -pc_factor_shift_type -pc_factor_shift_amount -ksp_type'
  #petsc_options_value = 'lu       mumps NONZERO 1.e-10 preonly'

  petsc_options_iname = '-pc_type -pc_factor_mat_solver_package -pc_factor_shift_type -pc_factor_shift_amount -ksp_type'
  petsc_options_value = 'lu       mumps NONZERO 1.e-10 gmres'

  line_search = bt
  nl_rel_tol = 1.0e-07
  nl_max_its = 50
  l_tol = 1.0e-09
  l_max_its = 500
[]

[Postprocessors]
  [./hot_flux_left]
    type = SideFluxIntegral
    variable = temperature
    boundary = 'bottom_left'
    diffusivity = lambda
  [../]

  [./hot_flux_right]
    type = SideFluxIntegral
    variable = temperature
    boundary = 'bottom_right'
    diffusivity = lambda
  [../]

  [./cold_flux]
    type = SideFluxIntegral
    variable = temperature
    boundary = 'top'
    diffusivity = lambda
  [../]

  [./current]
    type = CurrentPostprocessor
    variable = voltage
    boundary = 'supply_terminal'
    temperature =  temperature
  [../]
[]

[Outputs]
  [./Exodus]
    type = Exodus
  [../]
[]

[Debug]
  show_var_residual_norms = true
  show_var_residual = 'voltage temperature'
[]
