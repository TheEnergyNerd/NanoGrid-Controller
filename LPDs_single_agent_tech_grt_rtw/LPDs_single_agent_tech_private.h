/*
 * LPDs_single_agent_tech_private.h
 *
 * Code generation for model "LPDs_single_agent_tech".
 *
 * Model version              : 1.1016
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Aug 27 10:44:54 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LPDs_single_agent_tech_private_h_
#define RTW_HEADER_LPDs_single_agent_tech_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "LPDs_single_agent_tech.h"
#include "LPDs_single_agent_tech_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Exported functions */
extern void LPDs_single_agent_tech_initQueue(Queue_real_T *q, QueuePolicy_T
  policy, int32_T capacity, Msg_real_T *qPool);
extern void LPDs_single_agen_Subsystem_Init(B_Subsystem_LPDs_single_agent_T
  *localB, P_Subsystem_LPDs_single_agent_T *localP);
extern void LPDs_single_a_Subsystem_Disable(DW_Subsystem_LPDs_single_agen_T
  *localDW);
extern void LPDs_single_agent_tec_Subsystem(RT_MODEL_LPDs_single_agent_te_T *
  const LPDs_single_agent_tech_M, boolean_T rtu_Enable, real_T rtu_In1,
  B_Subsystem_LPDs_single_agent_T *localB, DW_Subsystem_LPDs_single_agen_T
  *localDW);
extern void LPDs_s_EnabledSubsystem_Disable(DW_EnabledSubsystem_LPDs_sing_T
  *localDW);
extern void LPDs_single_ag_EnabledSubsystem(RT_MODEL_LPDs_single_agent_te_T *
  const LPDs_single_agent_tech_M, boolean_T rtu_Enable,
  DW_EnabledSubsystem_LPDs_sing_T *localDW);
extern void LPDs_EnabledSubsystem_n_Disable(DW_EnabledSubsystem_LPDs_si_b_T
  *localDW);
extern void LPDs_single__EnabledSubsystem_g(RT_MODEL_LPDs_single_agent_te_T *
  const LPDs_single_agent_tech_M, boolean_T rtu_Enable,
  DW_EnabledSubsystem_LPDs_si_b_T *localDW);

/* private model entry point functions */
extern void LPDs_single_agent_tech_derivatives(void);

#endif                        /* RTW_HEADER_LPDs_single_agent_tech_private_h_ */
