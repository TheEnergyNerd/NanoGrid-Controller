/*
 * LPDs_single_agent_tech_types.h
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

#ifndef RTW_HEADER_LPDs_single_agent_tech_types_h_
#define RTW_HEADER_LPDs_single_agent_tech_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

typedef enum {
  MSG_QUEUE_UNUSED = -1,               /* Default value */
  MSG_FIFO_QUEUE,
  MSG_LIFO_QUEUE,
  MSG_PRIORITY_QUEUE
} QueuePolicy_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_real_T_
#define DEFINED_TYPEDEF_FOR_Msg_real_T_

typedef struct {
  real_T fData;
} Msg_real_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Queue_real_T_
#define DEFINED_TYPEDEF_FOR_Queue_real_T_

typedef struct {
  QueuePolicy_T fPolicy;
  int32_T fHead;
  int32_T fTail;
  int32_T fCapacity;
  Msg_real_T *fArray;
} Queue_real_T;

#endif

/* Parameters for system: '<S1>/Subsystem' */
typedef struct P_Subsystem_LPDs_single_agent_T_ P_Subsystem_LPDs_single_agent_T;

/* Parameters for system: '<S30>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_LPDs_singl_T_ P_EnabledSubsystem_LPDs_singl_T;

/* Parameters for system: '<S36>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_LPDs_sin_b_T_ P_EnabledSubsystem_LPDs_sin_b_T;

/* Parameters (default storage) */
typedef struct P_LPDs_single_agent_tech_T_ P_LPDs_single_agent_tech_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_LPDs_single_agent_tec_T RT_MODEL_LPDs_single_agent_te_T;

#endif                          /* RTW_HEADER_LPDs_single_agent_tech_types_h_ */
