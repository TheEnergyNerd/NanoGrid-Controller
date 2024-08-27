/*
 * LPDs_single_agent_tech.c
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

#include "LPDs_single_agent_tech.h"
#include "rtwtypes.h"
#include "LPDs_single_agent_tech_types.h"
#include "LPDs_single_agent_tech_private.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
#define LPDs_single_IN_Battery_SOC_max1 ((uint8_T)5U)
#define LPDs_single__IN_Battery_SOC_max ((uint8_T)4U)
#define LPDs_single_agen_IN_BatteryHigh ((uint8_T)1U)
#define LPDs_single_agent_IN_BatteryLow ((uint8_T)2U)
#define LPDs_single_agent_IN_BatteryMin ((uint8_T)3U)
#define LPDs_single_agent_tec_IN_Normal ((uint8_T)6U)
#define LPDs_single_agent_tech_IN_state ((uint8_T)7U)
#define LPDs_single_agent_tech_SOC_high (0.8)
#define LPDs_single_agent_tech_SOC_low (0.3)
#define LPDs_single_agent_tech_SOC_max (0.95)
#define LPDs_single_agent_tech_SOC_min (0.15)

/* Named constants for Chart: '<S5>/Chart' */
#define IN_PV_Wind_Battery_Power_Mode_k ((uint8_T)11U)
#define IN_PV_Wind_Battery_Power_Mode_l ((uint8_T)10U)
#define LPD_IN_Nano_Grid_Initiliazation ((uint8_T)3U)
#define LPDs_si_IN_PV_Wind_Power_Mode_1 ((uint8_T)12U)
#define LPDs_si_IN_PV_Wind_Power_Mode_2 ((uint8_T)13U)
#define LPDs_singl_IN_Output_parameters ((uint8_T)4U)
#define LPDs_single_IN_load_flexibility ((uint8_T)29U)
#define LPDs_single__IN_Initialization1 ((uint8_T)1U)
#define LPDs_single__IN_Initialization2 ((uint8_T)2U)
#define LPDs_single__IN_PV_Power_Mode_1 ((uint8_T)6U)
#define LPDs_single__IN_PV_Power_Mode_2 ((uint8_T)7U)
#define LPDs_single__IN_PV_Power_Mode_3 ((uint8_T)8U)
#define LPDs_single_ag_IN_Use_microgrid ((uint8_T)16U)
#define LPDs_single_age_IN_use_nanogrid ((uint8_T)30U)
#define LPDs_single_agen_IN_Use_Battery ((uint8_T)14U)
#define LPDs_single_agent_IN_category_1 ((uint8_T)17U)
#define LPDs_single_agent_IN_category_2 ((uint8_T)18U)
#define LPDs_single_agent_IN_category_3 ((uint8_T)19U)
#define LPDs_single_agent_IN_category_4 ((uint8_T)20U)
#define LPDs_single_agent_IN_category_6 ((uint8_T)21U)
#define LPDs_single_agent_IN_category_7 ((uint8_T)22U)
#define LPDs_single_agent_t_IN_Use_Wind ((uint8_T)15U)
#define LPDs_single_agent_tech_IN_PV   ((uint8_T)5U)
#define LPDs_single_agent_tech_IN_ds   ((uint8_T)23U)
#define LPDs_single_agent_tech_IN_ds1  ((uint8_T)24U)
#define LPDs_single_agent_tech_IN_el   ((uint8_T)25U)
#define LPDs_single_agent_tech_IN_ell  ((uint8_T)26U)
#define LPDs_single_agent_tech_IN_ell1 ((uint8_T)27U)
#define LPDs_single_agent_tech_IN_fi   ((uint8_T)28U)
#define LPDs_single_agent_tech_kev_min (0.5)
#define LPDs_single_agent_tech_ksl_min (1.0)
#define LPDs_single_agent_tech_ktcl_min (0.5)
#define L_IN_PV_Wind_Battery_Power_Mode ((uint8_T)9U)

/* Block signals (default storage) */
B_LPDs_single_agent_tech_T LPDs_single_agent_tech_B;

/* Continuous states */
X_LPDs_single_agent_tech_T LPDs_single_agent_tech_X;

/* Disabled State Vector */
XDis_LPDs_single_agent_tech_T LPDs_single_agent_tech_XDis;

/* Block states (default storage) */
DW_LPDs_single_agent_tech_T LPDs_single_agent_tech_DW;

/* Real-time model */
static RT_MODEL_LPDs_single_agent_te_T LPDs_single_agent_tech_M_;
RT_MODEL_LPDs_single_agent_te_T *const LPDs_single_agent_tech_M =
  &LPDs_single_agent_tech_M_;

/* Forward declaration for local functions */
static void initialize_msg_local_queues_for(void);
static void LPDs_single_sf_msg_discard_HIGH(void);
static void LPDs_single__sf_msg_discard_LOW(void);
static void LPDs_single__sf_msg_discard_MAX(void);
static void LPDs_single__sf_msg_discard_MIN(void);
static void LPDs_sing_sf_msg_discard_NORMAL(void);
static void LPD_sf_msg_discard_batteryState(void);
static void LPDs_single_age_Initialization1(void);
static void LPDs_single_age_enter_atomic_PV(void);
static void LPDs_single_agent_tech_PV(void);
static void PV_Wind_Battery_Power_Mode_load(void);
static void LPDs_single_agent_te_category_1(void);
static void LPDs_single_agent_te_category_2(void);
static void LPDs_single_ag_load_flexibility(void);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  LPDs_single_agent_tech_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  LPDs_single_agent_tech_step();
  LPDs_single_agent_tech_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  LPDs_single_agent_tech_step();
  LPDs_single_agent_tech_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S1>/Subsystem'
 *    '<S1>/Subsystem1'
 */
void LPDs_single_agen_Subsystem_Init(B_Subsystem_LPDs_single_agent_T *localB,
  P_Subsystem_LPDs_single_agent_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
   *  Outport: '<S11>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S1>/Subsystem'
 *    '<S1>/Subsystem1'
 */
void LPDs_single_a_Subsystem_Disable(DW_Subsystem_LPDs_single_agen_T *localDW)
{
  localDW->Subsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S1>/Subsystem'
 *    '<S1>/Subsystem1'
 */
void LPDs_single_agent_tec_Subsystem(RT_MODEL_LPDs_single_agent_te_T * const
  LPDs_single_agent_tech_M, boolean_T rtu_Enable, real_T rtu_In1,
  B_Subsystem_LPDs_single_agent_T *localB, DW_Subsystem_LPDs_single_agen_T
  *localDW)
{
  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M) && rtsiIsModeUpdateTimeStep
      (&LPDs_single_agent_tech_M->solverInfo)) {
    if (rtu_Enable) {
      localDW->Subsystem_MODE = true;
    } else if (localDW->Subsystem_MODE) {
      LPDs_single_a_Subsystem_Disable(localDW);
    }
  }

  if (localDW->Subsystem_MODE) {
    /* SignalConversion generated from: '<S11>/In1' */
    localB->In1 = rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */
}

/*
 * Disable for enable system:
 *    '<S30>/Enabled Subsystem'
 *    '<S31>/Enabled Subsystem'
 */
void LPDs_s_EnabledSubsystem_Disable(DW_EnabledSubsystem_LPDs_sing_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S30>/Enabled Subsystem'
 *    '<S31>/Enabled Subsystem'
 */
void LPDs_single_ag_EnabledSubsystem(RT_MODEL_LPDs_single_agent_te_T * const
  LPDs_single_agent_tech_M, boolean_T rtu_Enable,
  DW_EnabledSubsystem_LPDs_sing_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S42>/Enable'
   */
  if (rtsiIsModeUpdateTimeStep(&LPDs_single_agent_tech_M->solverInfo)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem_MODE = true;
    } else if (localDW->EnabledSubsystem_MODE) {
      LPDs_s_EnabledSubsystem_Disable(localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S30>/Enabled Subsystem' */
}

/*
 * Disable for enable system:
 *    '<S36>/Enabled Subsystem'
 *    '<S37>/Enabled Subsystem'
 */
void LPDs_EnabledSubsystem_n_Disable(DW_EnabledSubsystem_LPDs_si_b_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S36>/Enabled Subsystem'
 *    '<S37>/Enabled Subsystem'
 */
void LPDs_single__EnabledSubsystem_g(RT_MODEL_LPDs_single_agent_te_T * const
  LPDs_single_agent_tech_M, boolean_T rtu_Enable,
  DW_EnabledSubsystem_LPDs_si_b_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S44>/Enable'
   */
  if (rtsiIsModeUpdateTimeStep(&LPDs_single_agent_tech_M->solverInfo)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem_MODE = true;
    } else if (localDW->EnabledSubsystem_MODE) {
      LPDs_EnabledSubsystem_n_Disable(localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S36>/Enabled Subsystem' */
}

void LPDs_single_agent_tech_initQueue(Queue_real_T *q, QueuePolicy_T policy,
  int32_T capacity, Msg_real_T *qPool)
{
  q->fPolicy = policy;
  q->fCapacity = capacity;
  q->fHead = -1;
  q->fTail = -1;
  q->fArray = qPool;
}

/* Function for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
static void initialize_msg_local_queues_for(void)
{
  LPDs_single_agent_tech_initQueue(&LPDs_single_agent_tech_DW.Queue[0],
    MSG_FIFO_QUEUE, 10, &LPDs_single_agent_tech_DW.Msg[1]);
  LPDs_single_agent_tech_initQueue(&LPDs_single_agent_tech_DW.Queue[1],
    MSG_FIFO_QUEUE, 10, &LPDs_single_agent_tech_DW.Msg[11]);
  LPDs_single_agent_tech_initQueue(&LPDs_single_agent_tech_DW.Queue[2],
    MSG_FIFO_QUEUE, 10, &LPDs_single_agent_tech_DW.Msg[21]);
  LPDs_single_agent_tech_initQueue(&LPDs_single_agent_tech_DW.Queue[3],
    MSG_FIFO_QUEUE, 10, &LPDs_single_agent_tech_DW.Msg[31]);
  LPDs_single_agent_tech_initQueue(&LPDs_single_agent_tech_DW.Queue[4],
    MSG_FIFO_QUEUE, 10, &LPDs_single_agent_tech_DW.Msg[41]);
  LPDs_single_agent_tech_initQueue(&LPDs_single_agent_tech_DW.Queue[5],
    MSG_FIFO_QUEUE, 10, &LPDs_single_agent_tech_DW.Msg[51]);
}

/* Function for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
static void LPDs_single_sf_msg_discard_HIGH(void)
{
  LPDs_single_agent_tech_DW.HIGH_isValid = false;
}

/* Function for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
static void LPDs_single__sf_msg_discard_LOW(void)
{
  LPDs_single_agent_tech_DW.LOW_isValid = false;
}

/* Function for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
static void LPDs_single__sf_msg_discard_MAX(void)
{
  LPDs_single_agent_tech_DW.MAX_isValid = false;
}

/* Function for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
static void LPDs_single__sf_msg_discard_MIN(void)
{
  LPDs_single_agent_tech_DW.MIN_isValid = false;
}

/* Function for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
static void LPDs_sing_sf_msg_discard_NORMAL(void)
{
  LPDs_single_agent_tech_DW.NORMAL_isValid = false;
}

/* Function for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
static void LPD_sf_msg_discard_batteryState(void)
{
  LPDs_single_agent_tech_DW.batteryState_isValid = false;
}

/* Function for Chart: '<S5>/Chart' */
static void LPDs_single_age_Initialization1(void)
{
  LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
    LPDs_single__IN_Initialization2;
  LPDs_single_agent_tech_DW.load = (LPDs_single_agent_tech_B.Gain22 +
    LPDs_single_agent_tech_B.Gain23) + LPDs_single_agent_tech_B.Gain24;
  LPDs_single_agent_tech_DW.nano_grid_supply = 0.0;
  LPDs_single_agent_tech_DW.nano_grid_demand = 0.0;
  if (LPDs_single_agent_tech_B.Gain21 < 0.0) {
    LPDs_single_agent_tech_DW.nano_grid_demand = fabs
      (LPDs_single_agent_tech_B.Gain21);
  } else {
    LPDs_single_agent_tech_DW.nano_grid_supply = LPDs_single_agent_tech_B.Gain21;
  }

  LPDs_single_agent_tech_DW.nanogrid_usage = 0.0;
  LPDs_single_agent_tech_DW.nanogrid_remain =
    LPDs_single_agent_tech_DW.nano_grid_supply;
  LPDs_single_agent_tech_DW.mg_power_usage_load = 0.0;
  LPDs_single_agent_tech_DW.mg_power_usage_nanogrid = 0.0;
  LPDs_single_agent_tech_DW.mg_power_usage = 0.0;
}

/* Function for Chart: '<S5>/Chart' */
static void LPDs_single_age_enter_atomic_PV(void)
{
  LPDs_single_agent_tech_DW.PV_load_usage_percentage = 100.0 *
    LPDs_single_agent_tech_DW.PV_load_usage / LPDs_single_agent_tech_B.Gain_f;
  LPDs_single_agent_tech_DW.PV_nanogrid_usage_percentage = 100.0 *
    LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage /
    LPDs_single_agent_tech_B.Gain_f;
  LPDs_single_agent_tech_DW.PV_remain_percentage = 100.0 *
    LPDs_single_agent_tech_DW.PV_remain_ / LPDs_single_agent_tech_B.Gain_f;
  LPDs_single_agent_tech_DW.wind_load_usage_percentage = 100.0 *
    LPDs_single_agent_tech_DW.wind_load_usage / LPDs_single_agent_tech_B.Gain3;
  LPDs_single_agent_tech_DW.wind_nanogrid_usage_percentage = 100.0 *
    LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage /
    LPDs_single_agent_tech_B.Gain3;
  LPDs_single_agent_tech_DW.wind_remain_percentage = 100.0 *
    LPDs_single_agent_tech_DW.wind_remain_ / LPDs_single_agent_tech_B.Gain3;
  LPDs_single_agent_tech_DW.battery_charging_power_out_perc = 100.0 *
    LPDs_single_agent_tech_DW.battery_charging_power_out /
    LPDs_single_agent_tech_B.Gain16;
  LPDs_single_agent_tech_DW.battery_discharging_power_out_p = 100.0 *
    LPDs_single_agent_tech_DW.battery_discharging_power_out /
    LPDs_single_agent_tech_B.Gain5;
  LPDs_single_agent_tech_DW.static_load_usage_percentage = 100.0 *
    LPDs_single_agent_tech_DW.static_load_usage /
    LPDs_single_agent_tech_B.Gain22;
  LPDs_single_agent_tech_DW.TCL_load_usage_percentage = 100.0 *
    LPDs_single_agent_tech_DW.TCL_load_usage / LPDs_single_agent_tech_B.Gain23;
  LPDs_single_agent_tech_DW.EV_load_usage_percentage = 100.0 *
    LPDs_single_agent_tech_DW.EV_load_usage / LPDs_single_agent_tech_B.Gain24;
  LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage_perce = 100.0 *
    LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage /
    LPDs_single_agent_tech_DW.nano_grid_demand;
  LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage_per = 100.0 *
    LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage /
    LPDs_single_agent_tech_DW.nano_grid_demand;
  LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage_perce = 100.0 *
    LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage /
    LPDs_single_agent_tech_DW.nano_grid_demand;
  LPDs_single_agent_tech_DW.mg_power_usage =
    LPDs_single_agent_tech_DW.mg_power_usage_nanogrid +
    LPDs_single_agent_tech_DW.mg_power_usage_load;
  LPDs_single_agent_tech_DW.total_power_produced =
    (((LPDs_single_agent_tech_B.Gain_f + LPDs_single_agent_tech_B.Gain3) +
      LPDs_single_agent_tech_B.Gain5) +
     LPDs_single_agent_tech_DW.nano_grid_supply) +
    LPDs_single_agent_tech_DW.mg_power_usage;
  LPDs_single_agent_tech_DW.total_power_consumed =
    (((LPDs_single_agent_tech_DW.static_load_usage +
       LPDs_single_agent_tech_DW.TCL_load_usage) +
      LPDs_single_agent_tech_DW.EV_load_usage) +
     LPDs_single_agent_tech_DW.battery_charging_power_out) +
    LPDs_single_agent_tech_DW.nano_grid_demand;
  LPDs_single_agent_tech_DW.power_balance_error =
    LPDs_single_agent_tech_DW.total_power_produced -
    LPDs_single_agent_tech_DW.total_power_consumed;
}

/* Function for Chart: '<S5>/Chart' */
static void LPDs_single_agent_tech_PV(void)
{
  LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
    LPDs_singl_IN_Output_parameters;
}

/* Function for Chart: '<S5>/Chart' */
static void PV_Wind_Battery_Power_Mode_load(void)
{
  LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
    LPD_IN_Nano_Grid_Initiliazation;
  LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage = 0.0;
  LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage = 0.0;
  LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = 0.0;
  LPDs_single_agent_tech_DW.PV_nanogrid_usage = 0.0;
  LPDs_single_agent_tech_DW.wind_nanogrid_usage = 0.0;
  LPDs_single_agent_tech_DW.PV_remain = LPDs_single_agent_tech_B.Gain_f -
    LPDs_single_agent_tech_DW.PV_load_usage;
  LPDs_single_agent_tech_DW.wind_remain = LPDs_single_agent_tech_B.Gain3 -
    LPDs_single_agent_tech_DW.wind_load_usage;
  LPDs_single_agent_tech_DW.PV_remain_ = LPDs_single_agent_tech_DW.PV_remain;
  LPDs_single_agent_tech_DW.wind_remain_ = LPDs_single_agent_tech_DW.wind_remain;
}

/* Function for Chart: '<S5>/Chart' */
static void LPDs_single_agent_te_category_1(void)
{
  if (LPDs_single_agent_tech_DW.dPV >= LPDs_single_agent_tech_B.Gain16) {
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_single__IN_PV_Power_Mode_1;
    LPDs_single_agent_tech_DW.PV_load_usage = LPDs_single_agent_tech_DW.load +
      LPDs_single_agent_tech_B.Gain16;
    LPDs_single_agent_tech_DW.wind_load_usage = 0.0;
    LPDs_single_agent_tech_DW.battery_charging_power_out =
      LPDs_single_agent_tech_B.Gain16;
    LPDs_single_agent_tech_DW.battery_discharging_power_out = 0.0;
    LPDs_single_agent_tech_DW.battery_usage = 0.0;
    LPDs_single_agent_tech_DW.static_load_usage =
      LPDs_single_agent_tech_B.Gain22;
    LPDs_single_agent_tech_DW.TCL_load_usage = LPDs_single_agent_tech_B.Gain23;
    LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_B.Gain24;
  } else if (LPDs_single_agent_tech_DW.dPV + LPDs_single_agent_tech_B.Gain3 >=
             LPDs_single_agent_tech_B.Gain16) {
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_single__IN_PV_Power_Mode_2;
    LPDs_single_agent_tech_DW.PV_load_usage = LPDs_single_agent_tech_B.Gain_f;
    LPDs_single_agent_tech_DW.wind_load_usage = (LPDs_single_agent_tech_DW.load
      + LPDs_single_agent_tech_B.Gain16) - LPDs_single_agent_tech_B.Gain_f;
    LPDs_single_agent_tech_DW.battery_charging_power_out =
      LPDs_single_agent_tech_B.Gain16;
    LPDs_single_agent_tech_DW.battery_discharging_power_out = 0.0;
    LPDs_single_agent_tech_DW.battery_usage = 0.0;
    LPDs_single_agent_tech_DW.static_load_usage =
      LPDs_single_agent_tech_B.Gain22;
    LPDs_single_agent_tech_DW.TCL_load_usage = LPDs_single_agent_tech_B.Gain23;
    LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_B.Gain24;
  } else {
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_single__IN_PV_Power_Mode_3;
    LPDs_single_agent_tech_DW.PV_load_usage = LPDs_single_agent_tech_B.Gain_f;
    LPDs_single_agent_tech_DW.wind_load_usage = LPDs_single_agent_tech_B.Gain3;
    LPDs_single_agent_tech_DW.battery_charging_power_out =
      (LPDs_single_agent_tech_B.Gain_f + LPDs_single_agent_tech_B.Gain3) -
      LPDs_single_agent_tech_DW.load;
    LPDs_single_agent_tech_DW.battery_discharging_power_out = 0.0;
    LPDs_single_agent_tech_DW.battery_usage = 0.0;
    LPDs_single_agent_tech_DW.static_load_usage =
      LPDs_single_agent_tech_B.Gain22;
    LPDs_single_agent_tech_DW.TCL_load_usage = LPDs_single_agent_tech_B.Gain23;
    LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_B.Gain24;
  }
}

/* Function for Chart: '<S5>/Chart' */
static void LPDs_single_agent_te_category_2(void)
{
  if (LPDs_single_agent_tech_DW.dwind >= LPDs_single_agent_tech_B.Gain16) {
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_si_IN_PV_Wind_Power_Mode_1;
    LPDs_single_agent_tech_DW.PV_load_usage = LPDs_single_agent_tech_B.Gain_f;
    LPDs_single_agent_tech_DW.wind_load_usage = (LPDs_single_agent_tech_DW.load
      + LPDs_single_agent_tech_B.Gain16) - LPDs_single_agent_tech_B.Gain_f;
    LPDs_single_agent_tech_DW.battery_charging_power_out =
      LPDs_single_agent_tech_B.Gain16;
    LPDs_single_agent_tech_DW.battery_discharging_power_out = 0.0;
    LPDs_single_agent_tech_DW.battery_usage = 0.0;
    LPDs_single_agent_tech_DW.static_load_usage =
      LPDs_single_agent_tech_B.Gain22;
    LPDs_single_agent_tech_DW.TCL_load_usage = LPDs_single_agent_tech_B.Gain23;
    LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_B.Gain24;
  } else {
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_si_IN_PV_Wind_Power_Mode_2;
    LPDs_single_agent_tech_DW.PV_load_usage = LPDs_single_agent_tech_B.Gain_f;
    LPDs_single_agent_tech_DW.wind_load_usage = LPDs_single_agent_tech_B.Gain3;
    LPDs_single_agent_tech_DW.battery_charging_power_out =
      (LPDs_single_agent_tech_B.Gain_f + LPDs_single_agent_tech_B.Gain3) -
      LPDs_single_agent_tech_DW.load;
    LPDs_single_agent_tech_DW.battery_discharging_power_out = 0.0;
    LPDs_single_agent_tech_DW.battery_usage = 0.0;
    LPDs_single_agent_tech_DW.static_load_usage =
      LPDs_single_agent_tech_B.Gain22;
    LPDs_single_agent_tech_DW.TCL_load_usage = LPDs_single_agent_tech_B.Gain23;
    LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_B.Gain24;
  }
}

/* Function for Chart: '<S5>/Chart' */
static void LPDs_single_ag_load_flexibility(void)
{
  if (LPDs_single_agent_tech_DW.power_remain >= 0.0) {
    real_T error;
    real_T source_power;
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_single_agent_IN_category_4;
    source_power = (LPDs_single_agent_tech_B.Gain_f +
                    LPDs_single_agent_tech_B.Gain3) +
      LPDs_single_agent_tech_B.Gain5;
    LPDs_single_agent_tech_DW.ks = LPDs_single_agent_tech_ksl_min;
    LPDs_single_agent_tech_DW.kt = LPDs_single_agent_tech_ktcl_min;
    LPDs_single_agent_tech_DW.ke = LPDs_single_agent_tech_kev_min;
    LPDs_single_agent_tech_DW.load = (0.5 * LPDs_single_agent_tech_B.Gain23 +
      LPDs_single_agent_tech_B.Gain22) + 0.5 * LPDs_single_agent_tech_B.Gain24;
    error = source_power - LPDs_single_agent_tech_DW.load;
    while ((error > 1.0E-5) && (LPDs_single_agent_tech_DW.kt <= 1.0) &&
           (LPDs_single_agent_tech_DW.ke <= 1.0)) {
      if (LPDs_single_agent_tech_DW.kt < 1.0) {
        LPDs_single_agent_tech_DW.kt += 1.0E-5;
      }

      if (LPDs_single_agent_tech_DW.ke < 1.0) {
        LPDs_single_agent_tech_DW.ke += 1.0E-5;
      }

      LPDs_single_agent_tech_DW.load = (LPDs_single_agent_tech_DW.kt *
        LPDs_single_agent_tech_B.Gain23 + LPDs_single_agent_tech_B.Gain22) +
        LPDs_single_agent_tech_DW.ke * LPDs_single_agent_tech_B.Gain24;
      error = source_power - LPDs_single_agent_tech_DW.load;
    }
  } else {
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_single_age_IN_use_nanogrid;
    LPDs_single_agent_tech_DW.load_ = ((LPDs_single_agent_tech_DW.load_min -
      LPDs_single_agent_tech_B.Gain_f) - LPDs_single_agent_tech_B.Gain3) -
      LPDs_single_agent_tech_B.Gain5;
  }
}

/* Model step function */
void LPDs_single_agent_tech_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_nanogridpowerutilization;
  boolean_T rtb_nanogridpowerutilization_a;
  boolean_T rtb_microgridpowerutilization;
  boolean_T rtb_microgridpowerutilization_o;
  if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    /* set solver stop time */
    if (!(LPDs_single_agent_tech_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&LPDs_single_agent_tech_M->solverInfo,
                            ((LPDs_single_agent_tech_M->Timing.clockTickH0 + 1) *
        LPDs_single_agent_tech_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&LPDs_single_agent_tech_M->solverInfo,
                            ((LPDs_single_agent_tech_M->Timing.clockTick0 + 1) *
        LPDs_single_agent_tech_M->Timing.stepSize0 +
        LPDs_single_agent_tech_M->Timing.clockTickH0 *
        LPDs_single_agent_tech_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(LPDs_single_agent_tech_M)) {
    LPDs_single_agent_tech_M->Timing.t[0] = rtsiGetT
      (&LPDs_single_agent_tech_M->solverInfo);
  }

  {
    real_T EV_load_usage;
    real_T LookUpTable_tmp;
    real_T PV_remain;
    real_T TCL_load_usage;
    real_T battery_power;
    real_T error;
    real_T load;
    real_T load_min;
    real_T mg;
    real_T mg_power_usage;
    real_T mg_power_usage_load;
    real_T mg_power_usage_nanogrid;
    real_T nano_grid_demand;
    real_T nano_grid_demand_PV_usage;
    real_T nano_grid_demand_wind_usage;
    real_T nano_grid_supply;
    real_T nanogrid_usage;
    real_T rtb_Wind_power_forecast;
    real_T rtb_nano_grid_controller_power;
    real_T static_load_usage;
    real_T total_power_consumed;
    real_T total_power_produced;
    real_T wind_load_usage;
    real_T wind_remain;
    real_T *lastU;
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* Saturate: '<S1>/Saturation' incorporates:
       *  Constant: '<S5>/Constant6'
       */
      if (LPDs_single_agent_tech_P.Constant6_Value >
          LPDs_single_agent_tech_P.Saturation_UpperSat) {
        battery_power = LPDs_single_agent_tech_P.Saturation_UpperSat;
      } else if (LPDs_single_agent_tech_P.Constant6_Value <
                 LPDs_single_agent_tech_P.Saturation_LowerSat) {
        battery_power = LPDs_single_agent_tech_P.Saturation_LowerSat;
      } else {
        battery_power = LPDs_single_agent_tech_P.Constant6_Value;
      }

      /* Product: '<S1>/Divide1' incorporates:
       *  Constant: '<S1>/Constant2'
       *  Saturate: '<S1>/Saturation'
       */
      LPDs_single_agent_tech_B.initial_battery_capacity =
        LPDs_single_agent_tech_P.battery_capacity_state_upper_limit *
        battery_power;
    }

    /* Integrator: '<S1>/initial_battery_energy' */
    if (LPDs_single_agent_tech_DW.initial_battery_energy_IWORK != 0) {
      LPDs_single_agent_tech_X.initial_battery_energy_CSTATE =
        LPDs_single_agent_tech_B.initial_battery_capacity;
    }

    /* Gain: '<S1>/1 s ----> 1h' incorporates:
     *  Gain: '<S1>/s ----> h'
     *  Integrator: '<S1>/initial_battery_energy'
     */
    LPDs_single_agent_tech_B.kWh = LPDs_single_agent_tech_P.sh_Gain *
      LPDs_single_agent_tech_X.initial_battery_energy_CSTATE *
      LPDs_single_agent_tech_P.us1h_Gain;
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S1>/Gain' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Product: '<S1>/Divide'
     */
    LPDs_single_agent_tech_B.Gain = LPDs_single_agent_tech_B.kWh /
      LPDs_single_agent_tech_P.battery_capacity_state_upper_limit *
      LPDs_single_agent_tech_P.Gain_Gain;
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' incorporates:
       *  Constant: '<S1>/Constant10'
       *  Constant: '<S1>/Constant6'
       */
      switch (LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech) {
       case LPDs_single_agen_IN_BatteryHigh:
        LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
          LPDs_single_IN_Battery_SOC_max1;
        LPDs_single_agent_tech_B.battery_charging_power =
          LPDs_single_agent_tech_B.battery_charge_factor *
          LPDs_single_agent_tech_P.battery_charge_power_state_upper_limit;
        LPDs_single_agent_tech_B.battery_discharging_power =
          LPDs_single_agent_tech_B.battery_discharge_factor *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;
        break;

       case LPDs_single_agent_IN_BatteryLow:
        LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
          LPDs_single_IN_Battery_SOC_max1;
        LPDs_single_agent_tech_B.battery_charging_power =
          LPDs_single_agent_tech_B.battery_charge_factor *
          LPDs_single_agent_tech_P.battery_charge_power_state_upper_limit;
        LPDs_single_agent_tech_B.battery_discharging_power =
          LPDs_single_agent_tech_B.battery_discharge_factor *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;
        break;

       case LPDs_single_agent_IN_BatteryMin:
        LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
          LPDs_single_IN_Battery_SOC_max1;
        LPDs_single_agent_tech_B.battery_charging_power =
          LPDs_single_agent_tech_B.battery_charge_factor *
          LPDs_single_agent_tech_P.battery_charge_power_state_upper_limit;
        LPDs_single_agent_tech_B.battery_discharging_power =
          LPDs_single_agent_tech_B.battery_discharge_factor *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;
        break;

       case LPDs_single__IN_Battery_SOC_max:
        LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
          LPDs_single_IN_Battery_SOC_max1;
        LPDs_single_agent_tech_B.battery_charging_power =
          LPDs_single_agent_tech_B.battery_charge_factor *
          LPDs_single_agent_tech_P.battery_charge_power_state_upper_limit;
        LPDs_single_agent_tech_B.battery_discharging_power =
          LPDs_single_agent_tech_B.battery_discharge_factor *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;
        break;

       case LPDs_single_IN_Battery_SOC_max1:
        LPDs_single_agent_tech_B.battery_charging_power =
          LPDs_single_agent_tech_B.battery_charge_factor *
          LPDs_single_agent_tech_P.battery_charge_power_state_upper_limit;
        LPDs_single_agent_tech_B.battery_discharging_power =
          LPDs_single_agent_tech_B.battery_discharge_factor *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;
        break;

       case LPDs_single_agent_tec_IN_Normal:
        LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
          LPDs_single_IN_Battery_SOC_max1;
        LPDs_single_agent_tech_B.battery_charging_power =
          LPDs_single_agent_tech_B.battery_charge_factor *
          LPDs_single_agent_tech_P.battery_charge_power_state_upper_limit;
        LPDs_single_agent_tech_B.battery_discharging_power =
          LPDs_single_agent_tech_B.battery_discharge_factor *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;
        break;

       default:
        /* case IN_state: */
        if (LPDs_single_agent_tech_B.Gain >= LPDs_single_agent_tech_SOC_max) {
          LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
            LPDs_single__IN_Battery_SOC_max;
          LPDs_single_agent_tech_B.battery_charge_factor =
            LPDs_single_agent_tech_DW.charge_min;
          LPDs_single_agent_tech_B.battery_discharge_factor =
            LPDs_single_agent_tech_DW.discharge_max;
        } else if (LPDs_single_agent_tech_B.Gain >=
                   LPDs_single_agent_tech_SOC_high) {
          LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
            LPDs_single_agen_IN_BatteryHigh;
          LPDs_single_agent_tech_B.battery_charge_factor =
            LPDs_single_agent_tech_DW.charge_low;
          LPDs_single_agent_tech_B.battery_discharge_factor =
            LPDs_single_agent_tech_DW.discharge_high;
        } else if (LPDs_single_agent_tech_B.Gain >=
                   LPDs_single_agent_tech_SOC_low) {
          LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
            LPDs_single_agent_tec_IN_Normal;
          LPDs_single_agent_tech_B.battery_charge_factor =
            LPDs_single_agent_tech_DW.charge_medium;
          LPDs_single_agent_tech_B.battery_discharge_factor =
            LPDs_single_agent_tech_DW.discharge_medium;
        } else if (LPDs_single_agent_tech_B.Gain >=
                   LPDs_single_agent_tech_SOC_min) {
          LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
            LPDs_single_agent_IN_BatteryLow;
          LPDs_single_agent_tech_B.battery_charge_factor =
            LPDs_single_agent_tech_DW.charge_high;
          LPDs_single_agent_tech_B.battery_discharge_factor =
            LPDs_single_agent_tech_DW.discharge_low;
        } else {
          LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
            LPDs_single_agent_IN_BatteryMin;
          LPDs_single_agent_tech_B.battery_charge_factor =
            LPDs_single_agent_tech_DW.charge_max;
          LPDs_single_agent_tech_B.battery_discharge_factor =
            LPDs_single_agent_tech_DW.discharge_min;
        }
        break;
      }

      LPDs_single_sf_msg_discard_HIGH();
      LPDs_single__sf_msg_discard_LOW();
      LPDs_single__sf_msg_discard_MAX();
      LPDs_single__sf_msg_discard_MIN();
      LPDs_sing_sf_msg_discard_NORMAL();
      LPD_sf_msg_discard_batteryState();

      /* End of Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */

      /* Gain: '<S4>/Gain' incorporates:
       *  Constant: '<S4>/micro_grid_controller_power_state'
       */
      LPDs_single_agent_tech_B.micro_grid_power =
        LPDs_single_agent_tech_P.Gain_Gain_a *
        LPDs_single_agent_tech_P.micro_grid_controller_power_sta;
    }

    /* Clock: '<S51>/Clock' incorporates:
     *  Clock: '<S17>/Clock'
     *  Clock: '<S18>/Clock'
     *  Clock: '<S19>/Clock'
     *  Clock: '<S23>/Clock'
     *  Clock: '<S24>/Clock'
     *  Clock: '<S25>/Clock'
     *  Clock: '<S47>/Clock'
     *  Clock: '<S50>/Clock'
     *  Clock: '<S54>/Clock'
     *  Clock: '<S55>/Clock'
     *  Clock: '<S58>/Clock'
     *  Clock: '<S59>/Clock'
     *  Derivative: '<S17>/Derivative'
     *  Derivative: '<S18>/Derivative'
     *  Derivative: '<S19>/Derivative'
     *  Derivative: '<S23>/Derivative'
     *  Derivative: '<S24>/Derivative'
     *  Derivative: '<S25>/Derivative'
     *  Derivative: '<S47>/Derivative'
     *  Derivative: '<S50>/Derivative'
     *  Derivative: '<S51>/Derivative'
     *  Derivative: '<S54>/Derivative'
     *  Derivative: '<S55>/Derivative'
     *  Derivative: '<S58>/Derivative'
     *  Derivative: '<S59>/Derivative'
     */
    LookUpTable_tmp = LPDs_single_agent_tech_M->Timing.t[0];

    /* Lookup: '<S51>/Look-Up Table' incorporates:
     *  Clock: '<S51>/Clock'
     */
    LPDs_single_agent_tech_B.LookUpTable = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData[0]);

    /* Gain: '<S7>/Gain2' incorporates:
     *  Gain: '<S7>/Gain'
     */
    LPDs_single_agent_tech_B.PV1_power_state =
      LPDs_single_agent_tech_P.Gain_Gain_m *
      LPDs_single_agent_tech_B.LookUpTable *
      LPDs_single_agent_tech_P.PV_power_rating;

    /* Lookup: '<S59>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_i = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_o[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_b[0]);

    /* Gain: '<S9>/Gain1' incorporates:
     *  Gain: '<S9>/Gain3'
     */
    rtb_Wind_power_forecast = LPDs_single_agent_tech_P.Gain3_Gain *
      LPDs_single_agent_tech_B.LookUpTable_i *
      LPDs_single_agent_tech_P.Wind_power_rating;

    /* Lookup: '<S47>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_o = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_b[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_e[0]);

    /* Gain: '<S6>/Gain' */
    rtb_nano_grid_controller_power =
      LPDs_single_agent_tech_P.nano_grid_controller_power_rating *
      LPDs_single_agent_tech_B.LookUpTable_o;
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* Gain: '<S3>/Gain' incorporates:
       *  Constant: '<S3>/Static_Load_demand'
       */
      LPDs_single_agent_tech_B.Static_Load_demand =
        LPDs_single_agent_tech_P.static_load_rating *
        LPDs_single_agent_tech_P.Static_Load_demand_Value;

      /* Gain: '<S3>/Gain1' incorporates:
       *  Constant: '<S3>/TCL_Load_demand'
       */
      LPDs_single_agent_tech_B.TCL_Load_demand =
        LPDs_single_agent_tech_P.TCL_load_rating *
        LPDs_single_agent_tech_P.TCL_Load_demand_Value;

      /* Gain: '<S3>/Gain2' incorporates:
       *  Constant: '<S3>/EV_Load_demand'
       */
      LPDs_single_agent_tech_B.EV_Load_demand =
        LPDs_single_agent_tech_P.EV_load_rating *
        LPDs_single_agent_tech_P.EV_Load_demand_Value;
    }

    /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
     *  Constant: '<S5>/Constant18'
     *  Constant: '<S5>/Constant19'
     *  Constant: '<S5>/Constant20'
     *  SignalConversion generated from: '<S29>/ SFunction '
     */
    error = (rtNaN);
    load = (LPDs_single_agent_tech_B.Static_Load_demand +
            LPDs_single_agent_tech_B.TCL_Load_demand) +
      LPDs_single_agent_tech_B.EV_Load_demand;
    static_load_usage = LPDs_single_agent_tech_B.Static_Load_demand *
      LPDs_single_agent_tech_P.static_load_priority_factor;
    TCL_load_usage = LPDs_single_agent_tech_B.TCL_Load_demand *
      LPDs_single_agent_tech_P.TCL_load_priority_factor;
    EV_load_usage = LPDs_single_agent_tech_B.EV_Load_demand *
      LPDs_single_agent_tech_P.EV_load_priority_factor;
    load_min = (static_load_usage + TCL_load_usage) + EV_load_usage;
    nano_grid_supply = 0.0;
    nano_grid_demand = 0.0;
    if (rtb_nano_grid_controller_power < 0.0) {
      nano_grid_demand = fabs(rtb_nano_grid_controller_power);
    } else {
      nano_grid_supply = rtb_nano_grid_controller_power;
    }

    nanogrid_usage = 0.0;
    LPDs_single_agent_tech_B.y[32] = nano_grid_supply;
    mg_power_usage_load = 0.0;
    mg_power_usage_nanogrid = 0.0;
    if (load <= LPDs_single_agent_tech_B.PV1_power_state) {
      load_min = LPDs_single_agent_tech_B.PV1_power_state - load;
      if (load_min >= LPDs_single_agent_tech_B.battery_charging_power) {
        load_min = load + LPDs_single_agent_tech_B.battery_charging_power;
        wind_load_usage = 0.0;
        load = LPDs_single_agent_tech_B.battery_charging_power;
        battery_power = 0.0;
        LPDs_single_agent_tech_B.y[20] = 0.0;
        static_load_usage = LPDs_single_agent_tech_B.Static_Load_demand;
        TCL_load_usage = LPDs_single_agent_tech_B.TCL_Load_demand;
        EV_load_usage = LPDs_single_agent_tech_B.EV_Load_demand;
      } else if (load_min + rtb_Wind_power_forecast >=
                 LPDs_single_agent_tech_B.battery_charging_power) {
        load_min = LPDs_single_agent_tech_B.PV1_power_state;
        wind_load_usage = (load +
                           LPDs_single_agent_tech_B.battery_charging_power) -
          LPDs_single_agent_tech_B.PV1_power_state;
        load = LPDs_single_agent_tech_B.battery_charging_power;
        battery_power = 0.0;
        LPDs_single_agent_tech_B.y[20] = 0.0;
        static_load_usage = LPDs_single_agent_tech_B.Static_Load_demand;
        TCL_load_usage = LPDs_single_agent_tech_B.TCL_Load_demand;
        EV_load_usage = LPDs_single_agent_tech_B.EV_Load_demand;
      } else {
        load_min = LPDs_single_agent_tech_B.PV1_power_state;
        wind_load_usage = rtb_Wind_power_forecast;
        load = (LPDs_single_agent_tech_B.PV1_power_state +
                rtb_Wind_power_forecast) - load;
        battery_power = 0.0;
        LPDs_single_agent_tech_B.y[20] = 0.0;
        static_load_usage = LPDs_single_agent_tech_B.Static_Load_demand;
        TCL_load_usage = LPDs_single_agent_tech_B.TCL_Load_demand;
        EV_load_usage = LPDs_single_agent_tech_B.EV_Load_demand;
      }
    } else {
      battery_power = LPDs_single_agent_tech_B.PV1_power_state +
        rtb_Wind_power_forecast;
      if (load <= battery_power) {
        battery_power -= load;
        if (battery_power >= LPDs_single_agent_tech_B.battery_charging_power) {
          load_min = LPDs_single_agent_tech_B.PV1_power_state;
          wind_load_usage = (load +
                             LPDs_single_agent_tech_B.battery_charging_power) -
            LPDs_single_agent_tech_B.PV1_power_state;
          load = LPDs_single_agent_tech_B.battery_charging_power;
          battery_power = 0.0;
          LPDs_single_agent_tech_B.y[20] = 0.0;
          static_load_usage = LPDs_single_agent_tech_B.Static_Load_demand;
          TCL_load_usage = LPDs_single_agent_tech_B.TCL_Load_demand;
          EV_load_usage = LPDs_single_agent_tech_B.EV_Load_demand;
        } else {
          load_min = LPDs_single_agent_tech_B.PV1_power_state;
          wind_load_usage = rtb_Wind_power_forecast;
          load = battery_power;
          battery_power = 0.0;
          LPDs_single_agent_tech_B.y[20] = 0.0;
          static_load_usage = LPDs_single_agent_tech_B.Static_Load_demand;
          TCL_load_usage = LPDs_single_agent_tech_B.TCL_Load_demand;
          EV_load_usage = LPDs_single_agent_tech_B.EV_Load_demand;
        }
      } else {
        battery_power += LPDs_single_agent_tech_B.battery_discharging_power;
        if (load <= battery_power) {
          load_min = LPDs_single_agent_tech_B.PV1_power_state;
          wind_load_usage = rtb_Wind_power_forecast;
          battery_power = (load - LPDs_single_agent_tech_B.PV1_power_state) -
            rtb_Wind_power_forecast;
          load = 0.0;
          LPDs_single_agent_tech_B.y[20] = battery_power;
          static_load_usage = LPDs_single_agent_tech_B.Static_Load_demand;
          TCL_load_usage = LPDs_single_agent_tech_B.TCL_Load_demand;
          EV_load_usage = LPDs_single_agent_tech_B.EV_Load_demand;
        } else if (load_min <= battery_power) {
          static_load_usage =
            LPDs_single_agent_tech_P.static_load_priority_factor;
          TCL_load_usage = LPDs_single_agent_tech_P.TCL_load_priority_factor;
          EV_load_usage = LPDs_single_agent_tech_P.EV_load_priority_factor;
          error = battery_power - load_min;
          while ((error > 1.0E-5) && (static_load_usage <= 1.0) &&
                 (TCL_load_usage <= 1.0) && (EV_load_usage <= 1.0)) {
            if (static_load_usage < 1.0) {
              static_load_usage += 1.0E-5;
            }

            if (TCL_load_usage < 1.0) {
              TCL_load_usage += 1.0E-5;
            }

            if (EV_load_usage < 1.0) {
              EV_load_usage += 1.0E-5;
            }

            error = battery_power - ((static_load_usage *
              LPDs_single_agent_tech_B.Static_Load_demand + TCL_load_usage *
              LPDs_single_agent_tech_B.TCL_Load_demand) + EV_load_usage *
              LPDs_single_agent_tech_B.EV_Load_demand);
          }

          load_min = LPDs_single_agent_tech_B.PV1_power_state;
          wind_load_usage = rtb_Wind_power_forecast;
          load = 0.0;
          battery_power = LPDs_single_agent_tech_B.battery_discharging_power;
          LPDs_single_agent_tech_B.y[20] =
            LPDs_single_agent_tech_B.battery_discharging_power;
          static_load_usage *= LPDs_single_agent_tech_B.Static_Load_demand;
          TCL_load_usage *= LPDs_single_agent_tech_B.TCL_Load_demand;
          EV_load_usage *= LPDs_single_agent_tech_B.EV_Load_demand;
        } else if (load_min <= battery_power + nano_grid_supply) {
          nanogrid_usage = ((load_min - LPDs_single_agent_tech_B.PV1_power_state)
                            - rtb_Wind_power_forecast) -
            LPDs_single_agent_tech_B.battery_discharging_power;
          load_min = LPDs_single_agent_tech_B.PV1_power_state;
          wind_load_usage = rtb_Wind_power_forecast;
          load = 0.0;
          battery_power = LPDs_single_agent_tech_B.battery_discharging_power;
          LPDs_single_agent_tech_B.y[20] =
            LPDs_single_agent_tech_B.battery_discharging_power;
          LPDs_single_agent_tech_B.y[32] = nano_grid_supply - nanogrid_usage;
        } else {
          mg_power_usage_load = (((load_min -
            LPDs_single_agent_tech_B.PV1_power_state) - rtb_Wind_power_forecast)
            - LPDs_single_agent_tech_B.battery_discharging_power) -
            nano_grid_supply;
          nanogrid_usage = nano_grid_supply;
          load_min = LPDs_single_agent_tech_B.PV1_power_state;
          wind_load_usage = rtb_Wind_power_forecast;
          load = 0.0;
          battery_power = LPDs_single_agent_tech_B.battery_discharging_power;
          LPDs_single_agent_tech_B.y[20] =
            LPDs_single_agent_tech_B.battery_discharging_power;
          LPDs_single_agent_tech_B.y[32] = nano_grid_supply - nano_grid_supply;
        }
      }
    }

    nano_grid_demand_wind_usage = 0.0;
    mg = 0.0;
    PV_remain = LPDs_single_agent_tech_B.PV1_power_state - load_min;
    wind_remain = rtb_Wind_power_forecast - wind_load_usage;
    if (PV_remain - nano_grid_demand > 0.0) {
      nano_grid_demand_PV_usage = nano_grid_demand;
    } else {
      nano_grid_demand_PV_usage = PV_remain;
      if ((PV_remain + wind_remain) - nano_grid_demand >= 0.0) {
        nano_grid_demand_wind_usage = nano_grid_demand - PV_remain;
      } else {
        nano_grid_demand_wind_usage = wind_remain;
        mg = (nano_grid_demand - PV_remain) - wind_remain;
        mg_power_usage_nanogrid = mg;
      }
    }

    PV_remain -= nano_grid_demand_PV_usage;
    wind_remain -= nano_grid_demand_wind_usage;
    mg_power_usage = mg_power_usage_nanogrid + mg_power_usage_load;
    total_power_produced = (((LPDs_single_agent_tech_B.PV1_power_state +
      rtb_Wind_power_forecast) +
      LPDs_single_agent_tech_B.battery_discharging_power) + nano_grid_supply) +
      mg_power_usage;
    total_power_consumed = (((static_load_usage + TCL_load_usage) +
      EV_load_usage) + load) + nano_grid_demand;
    LPDs_single_agent_tech_B.y[0] = LPDs_single_agent_tech_B.PV1_power_state;
    LPDs_single_agent_tech_B.y[1] = load_min;
    LPDs_single_agent_tech_B.y[2] = nano_grid_demand_PV_usage;
    LPDs_single_agent_tech_B.y[3] = PV_remain;
    LPDs_single_agent_tech_B.y[4] = 100.0 * load_min /
      LPDs_single_agent_tech_B.PV1_power_state;
    LPDs_single_agent_tech_B.y[5] = 100.0 * nano_grid_demand_PV_usage /
      LPDs_single_agent_tech_B.PV1_power_state;
    LPDs_single_agent_tech_B.y[6] = 100.0 * PV_remain /
      LPDs_single_agent_tech_B.PV1_power_state;
    LPDs_single_agent_tech_B.y[7] = rtb_Wind_power_forecast;
    LPDs_single_agent_tech_B.y[8] = wind_load_usage;
    LPDs_single_agent_tech_B.y[9] = nano_grid_demand_wind_usage;
    LPDs_single_agent_tech_B.y[10] = wind_remain;
    LPDs_single_agent_tech_B.y[11] = 100.0 * wind_load_usage /
      rtb_Wind_power_forecast;
    LPDs_single_agent_tech_B.y[12] = 100.0 * nano_grid_demand_wind_usage /
      rtb_Wind_power_forecast;
    LPDs_single_agent_tech_B.y[13] = 100.0 * wind_remain /
      rtb_Wind_power_forecast;
    LPDs_single_agent_tech_B.y[14] =
      LPDs_single_agent_tech_B.battery_charging_power;
    LPDs_single_agent_tech_B.y[15] = load;
    LPDs_single_agent_tech_B.y[16] = 100.0 * load /
      LPDs_single_agent_tech_B.battery_charging_power;
    LPDs_single_agent_tech_B.y[17] =
      LPDs_single_agent_tech_B.battery_discharging_power;
    LPDs_single_agent_tech_B.y[18] = battery_power;
    LPDs_single_agent_tech_B.y[19] = 100.0 * battery_power /
      LPDs_single_agent_tech_B.battery_discharging_power;
    LPDs_single_agent_tech_B.y[21] = LPDs_single_agent_tech_B.Static_Load_demand;
    LPDs_single_agent_tech_B.y[22] = static_load_usage;
    LPDs_single_agent_tech_B.y[23] = 100.0 * static_load_usage /
      LPDs_single_agent_tech_B.Static_Load_demand;
    LPDs_single_agent_tech_B.y[24] = LPDs_single_agent_tech_B.TCL_Load_demand;
    LPDs_single_agent_tech_B.y[25] = TCL_load_usage;
    LPDs_single_agent_tech_B.y[26] = 100.0 * TCL_load_usage /
      LPDs_single_agent_tech_B.TCL_Load_demand;
    LPDs_single_agent_tech_B.y[27] = LPDs_single_agent_tech_B.EV_Load_demand;
    LPDs_single_agent_tech_B.y[28] = EV_load_usage;
    LPDs_single_agent_tech_B.y[29] = 100.0 * EV_load_usage /
      LPDs_single_agent_tech_B.EV_Load_demand;
    LPDs_single_agent_tech_B.y[30] = nano_grid_supply;
    LPDs_single_agent_tech_B.y[31] = nanogrid_usage;
    LPDs_single_agent_tech_B.y[33] = nano_grid_demand;
    LPDs_single_agent_tech_B.y[34] = nano_grid_demand_PV_usage;
    LPDs_single_agent_tech_B.y[35] = 100.0 * nano_grid_demand_PV_usage /
      nano_grid_demand;
    LPDs_single_agent_tech_B.y[36] = nano_grid_demand_wind_usage;
    LPDs_single_agent_tech_B.y[37] = 100.0 * nano_grid_demand_wind_usage /
      nano_grid_demand;
    LPDs_single_agent_tech_B.y[38] = mg;
    LPDs_single_agent_tech_B.y[39] = 100.0 * mg / nano_grid_demand;
    LPDs_single_agent_tech_B.y[40] = LPDs_single_agent_tech_B.micro_grid_power;
    LPDs_single_agent_tech_B.y[41] = mg_power_usage;
    LPDs_single_agent_tech_B.y[42] = mg_power_usage_load;
    LPDs_single_agent_tech_B.y[43] = mg_power_usage_nanogrid;
    LPDs_single_agent_tech_B.y[44] = total_power_produced;
    LPDs_single_agent_tech_B.y[45] = total_power_consumed;
    LPDs_single_agent_tech_B.y[46] = total_power_produced - total_power_consumed;
    LPDs_single_agent_tech_B.y[47] = LPDs_single_agent_tech_B.PV1_power_state;
    LPDs_single_agent_tech_B.y[48] = rtb_Wind_power_forecast;
    LPDs_single_agent_tech_B.y[49] =
      LPDs_single_agent_tech_B.battery_discharging_power;
    LPDs_single_agent_tech_B.y[50] = nano_grid_supply;
    LPDs_single_agent_tech_B.y[51] = mg_power_usage;
    LPDs_single_agent_tech_B.y[52] = static_load_usage;
    LPDs_single_agent_tech_B.y[53] = TCL_load_usage;
    LPDs_single_agent_tech_B.y[54] = EV_load_usage;
    LPDs_single_agent_tech_B.y[55] = load;
    LPDs_single_agent_tech_B.y[56] = nano_grid_demand;
    LPDs_single_agent_tech_B.y[57] = error;

    /* End of MATLAB Function: '<S5>/MATLAB Function' */

    /* Sum: '<S5>/Sum' */
    LPDs_single_agent_tech_B.Sum = LPDs_single_agent_tech_B.y[15] -
      LPDs_single_agent_tech_B.y[18];

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    LPDs_single_agent_tech_B.Compare = (LPDs_single_agent_tech_B.Sum >
      LPDs_single_agent_tech_P.Constant_Value_j);

    /* Logic: '<S1>/discharge' */
    LPDs_single_agent_tech_B.discharging = !LPDs_single_agent_tech_B.Compare;
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* SignalConversion generated from: '<S12>/Enable' */
      LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_Subsystem =
        LPDs_single_agent_tech_B.discharging;

      /* SignalConversion generated from: '<S11>/Enable' */
      LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_Subsyst_i =
        LPDs_single_agent_tech_B.Compare;
    }

    /* Outputs for Enabled SubSystem: '<S1>/Subsystem' */
    LPDs_single_agent_tec_Subsystem(LPDs_single_agent_tech_M,
      LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_Subsyst_i,
      LPDs_single_agent_tech_B.Sum, &LPDs_single_agent_tech_B.Subsystem,
      &LPDs_single_agent_tech_DW.Subsystem);

    /* End of Outputs for SubSystem: '<S1>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S1>/Subsystem1' */
    LPDs_single_agent_tec_Subsystem(LPDs_single_agent_tech_M,
      LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_Subsystem,
      LPDs_single_agent_tech_B.Sum, &LPDs_single_agent_tech_B.Subsystem1,
      &LPDs_single_agent_tech_DW.Subsystem1);

    /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

    /* Lookup: '<S17>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_b = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_ba[0], 2, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_i[0]);

    /* Derivative: '<S17>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB >= LookUpTable_tmp)) {
      /* Derivative: '<S17>/Derivative' */
      LPDs_single_agent_tech_B.Derivative = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA;
      if (LPDs_single_agent_tech_DW.TimeStampA <
          LPDs_single_agent_tech_DW.TimeStampB) {
        if (LPDs_single_agent_tech_DW.TimeStampB < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB;
      }

      /* Derivative: '<S17>/Derivative' */
      LPDs_single_agent_tech_B.Derivative =
        (LPDs_single_agent_tech_B.LookUpTable_b - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S18>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_l = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_d[0], 2, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_p[0]);

    /* Derivative: '<S18>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_o >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_e >= LookUpTable_tmp)) {
      /* Derivative: '<S18>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_f = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_o;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_h;
      if (LPDs_single_agent_tech_DW.TimeStampA_o <
          LPDs_single_agent_tech_DW.TimeStampB_e) {
        if (LPDs_single_agent_tech_DW.TimeStampB_e < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_e;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_k;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_o >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_e;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_k;
      }

      /* Derivative: '<S18>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_f =
        (LPDs_single_agent_tech_B.LookUpTable_l - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S19>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_om = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_a[0], 2, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_pj[0]);

    /* Derivative: '<S19>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_o2 >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_p >= LookUpTable_tmp)) {
      /* Derivative: '<S19>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_j = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_o2;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_e;
      if (LPDs_single_agent_tech_DW.TimeStampA_o2 <
          LPDs_single_agent_tech_DW.TimeStampB_p) {
        if (LPDs_single_agent_tech_DW.TimeStampB_p < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_p;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_b;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_o2 >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_p;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_b;
      }

      /* Derivative: '<S19>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_j =
        (LPDs_single_agent_tech_B.LookUpTable_om - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S23>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_m = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_c[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_g[0]);

    /* Derivative: '<S23>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_m >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_d >= LookUpTable_tmp)) {
      /* Derivative: '<S23>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_i = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_m;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_i;
      if (LPDs_single_agent_tech_DW.TimeStampA_m <
          LPDs_single_agent_tech_DW.TimeStampB_d) {
        if (LPDs_single_agent_tech_DW.TimeStampB_d < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_d;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_c;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_m >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_d;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<S23>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_i =
        (LPDs_single_agent_tech_B.LookUpTable_m - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S24>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_f = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_k[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_po[0]);

    /* Derivative: '<S24>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_i >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_dc >= LookUpTable_tmp)) {
      /* Derivative: '<S24>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_p = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_i;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_g;
      if (LPDs_single_agent_tech_DW.TimeStampA_i <
          LPDs_single_agent_tech_DW.TimeStampB_dc) {
        if (LPDs_single_agent_tech_DW.TimeStampB_dc < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_dc;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_j;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_i >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_dc;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_j;
      }

      /* Derivative: '<S24>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_p =
        (LPDs_single_agent_tech_B.LookUpTable_f - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S25>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_p = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_kl[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_m[0]);

    /* Derivative: '<S25>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_j >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_o >= LookUpTable_tmp)) {
      /* Derivative: '<S25>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_a = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_j;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_d;
      if (LPDs_single_agent_tech_DW.TimeStampA_j <
          LPDs_single_agent_tech_DW.TimeStampB_o) {
        if (LPDs_single_agent_tech_DW.TimeStampB_o < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_o;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_kb;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_j >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_o;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_kb;
      }

      /* Derivative: '<S25>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_a =
        (LPDs_single_agent_tech_B.LookUpTable_p - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Gain: '<S5>/Gain66' */
    LPDs_single_agent_tech_B.EV_loadskW = LPDs_single_agent_tech_P.Gain66_Gain *
      LPDs_single_agent_tech_B.y[27];

    /* Gain: '<S5>/Gain67' */
    LPDs_single_agent_tech_B.EV_load_usagekW =
      LPDs_single_agent_tech_P.Gain67_Gain * LPDs_single_agent_tech_B.y[28];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain68' */
    LPDs_single_agent_tech_B.nano_grid_supplykW =
      LPDs_single_agent_tech_P.Gain68_Gain * LPDs_single_agent_tech_B.y[30];

    /* Gain: '<S5>/Gain69' */
    LPDs_single_agent_tech_B.nano_grid_usagekW =
      LPDs_single_agent_tech_P.Gain69_Gain * LPDs_single_agent_tech_B.y[31];

    /* Gain: '<S5>/Gain70' */
    LPDs_single_agent_tech_B.nano_grid_remainkW =
      LPDs_single_agent_tech_P.Gain70_Gain * LPDs_single_agent_tech_B.y[32];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain75' */
    LPDs_single_agent_tech_B.mg_powerkW = LPDs_single_agent_tech_P.Gain75_Gain *
      LPDs_single_agent_tech_B.y[40];

    /* Gain: '<S5>/Gain76' */
    LPDs_single_agent_tech_B.mg_power_usagekW =
      LPDs_single_agent_tech_P.Gain76_Gain * LPDs_single_agent_tech_B.y[41];

    /* Gain: '<S5>/Gain77' */
    LPDs_single_agent_tech_B.mg_power_usage_loadkW =
      LPDs_single_agent_tech_P.Gain77_Gain * LPDs_single_agent_tech_B.y[42];

    /* Gain: '<S5>/Gain78' */
    LPDs_single_agent_tech_B.mg_power_usage_nanogridkW =
      LPDs_single_agent_tech_P.Gain78_Gain * LPDs_single_agent_tech_B.y[43];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain79' */
    LPDs_single_agent_tech_B.total_power_producedkW =
      LPDs_single_agent_tech_P.Gain79_Gain * LPDs_single_agent_tech_B.y[44];

    /* Gain: '<S5>/Gain80' */
    LPDs_single_agent_tech_B.total_power_consumedkW =
      LPDs_single_agent_tech_P.Gain80_Gain * LPDs_single_agent_tech_B.y[45];

    /* Gain: '<S5>/Gain81' */
    LPDs_single_agent_tech_B.power_balance_errorkW =
      LPDs_single_agent_tech_P.Gain81_Gain * LPDs_single_agent_tech_B.y[46];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain71' */
    LPDs_single_agent_tech_B.nano_grid_demandkW =
      LPDs_single_agent_tech_P.Gain71_Gain * LPDs_single_agent_tech_B.y[33];

    /* Gain: '<S5>/Gain72' */
    LPDs_single_agent_tech_B.nano_grid_demand_PV_usageskW =
      LPDs_single_agent_tech_P.Gain72_Gain * LPDs_single_agent_tech_B.y[34];

    /* Gain: '<S5>/Gain73' */
    LPDs_single_agent_tech_B.nano_grid_demand_wind_usageskW =
      LPDs_single_agent_tech_P.Gain73_Gain * LPDs_single_agent_tech_B.y[36];

    /* Gain: '<S5>/Gain74' */
    LPDs_single_agent_tech_B.nano_grid_demand_mg_usagekW =
      LPDs_single_agent_tech_P.Gain74_Gain * LPDs_single_agent_tech_B.y[38];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain82' */
    LPDs_single_agent_tech_B.PV1_power_kW = LPDs_single_agent_tech_P.Gain82_Gain
      * LPDs_single_agent_tech_B.y[47];

    /* Gain: '<S5>/Gain83' */
    LPDs_single_agent_tech_B.wind_power_kW =
      LPDs_single_agent_tech_P.Gain83_Gain * LPDs_single_agent_tech_B.y[48];

    /* Gain: '<S5>/Gain84' */
    LPDs_single_agent_tech_B.battery_discharging_power__kW =
      LPDs_single_agent_tech_P.Gain84_Gain * LPDs_single_agent_tech_B.y[49];

    /* Gain: '<S5>/Gain85' */
    LPDs_single_agent_tech_B.nano_grid_supply_kW =
      LPDs_single_agent_tech_P.Gain85_Gain * LPDs_single_agent_tech_B.y[50];

    /* Gain: '<S5>/Gain86' */
    LPDs_single_agent_tech_B.mg_power_usage_kW =
      LPDs_single_agent_tech_P.Gain86_Gain * LPDs_single_agent_tech_B.y[51];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain87' */
    LPDs_single_agent_tech_B.static_load_usage_kW =
      LPDs_single_agent_tech_P.Gain87_Gain * LPDs_single_agent_tech_B.y[52];

    /* Gain: '<S5>/Gain88' */
    LPDs_single_agent_tech_B.TCL_load_usage_kW =
      LPDs_single_agent_tech_P.Gain88_Gain * LPDs_single_agent_tech_B.y[53];

    /* Gain: '<S5>/Gain89' */
    LPDs_single_agent_tech_B.EV_load_usage_kW =
      LPDs_single_agent_tech_P.Gain89_Gain * LPDs_single_agent_tech_B.y[54];

    /* Gain: '<S5>/Gain90' */
    LPDs_single_agent_tech_B.battery_charging_power_out_kW =
      LPDs_single_agent_tech_P.Gain90_Gain * LPDs_single_agent_tech_B.y[55];

    /* Gain: '<S5>/Gain91' */
    LPDs_single_agent_tech_B.nano_grid_demand_kW =
      LPDs_single_agent_tech_P.Gain91_Gain * LPDs_single_agent_tech_B.y[56];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain12' */
    LPDs_single_agent_tech_B.PV1_powerskW = LPDs_single_agent_tech_P.Gain12_Gain
      * LPDs_single_agent_tech_B.y[0];

    /* Gain: '<S5>/Gain13' */
    LPDs_single_agent_tech_B.PV_load_usagekW =
      LPDs_single_agent_tech_P.Gain13_Gain * LPDs_single_agent_tech_B.y[1];

    /* Gain: '<S5>/Gain14' */
    LPDs_single_agent_tech_B.PV_nanogrid_usagekW =
      LPDs_single_agent_tech_P.Gain14_Gain * LPDs_single_agent_tech_B.y[2];

    /* Gain: '<S5>/Gain53' */
    LPDs_single_agent_tech_B.PV_remain_kW = LPDs_single_agent_tech_P.Gain53_Gain
      * LPDs_single_agent_tech_B.y[3];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain54' */
    LPDs_single_agent_tech_B.wind_powerskW =
      LPDs_single_agent_tech_P.Gain54_Gain * LPDs_single_agent_tech_B.y[7];

    /* Gain: '<S5>/Gain55' */
    LPDs_single_agent_tech_B.wind_load_usagekW =
      LPDs_single_agent_tech_P.Gain55_Gain * LPDs_single_agent_tech_B.y[8];

    /* Gain: '<S5>/Gain56' */
    LPDs_single_agent_tech_B.wind_nanogrid_usagekW =
      LPDs_single_agent_tech_P.Gain56_Gain * LPDs_single_agent_tech_B.y[9];

    /* Gain: '<S5>/Gain57' */
    LPDs_single_agent_tech_B.wind_remain_kW =
      LPDs_single_agent_tech_P.Gain57_Gain * LPDs_single_agent_tech_B.y[10];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain58' */
    LPDs_single_agent_tech_B.battery_charging_powerskW =
      LPDs_single_agent_tech_P.Gain58_Gain * LPDs_single_agent_tech_B.y[14];

    /* Gain: '<S5>/Gain59' */
    LPDs_single_agent_tech_B.battery_charging_power_outkW =
      LPDs_single_agent_tech_P.Gain59_Gain * LPDs_single_agent_tech_B.y[15];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain60' */
    LPDs_single_agent_tech_B.battery_discharging_powerskW =
      LPDs_single_agent_tech_P.Gain60_Gain * LPDs_single_agent_tech_B.y[17];

    /* Gain: '<S5>/Gain61' */
    LPDs_single_agent_tech_B.battery_discharging_power_outkW =
      LPDs_single_agent_tech_P.Gain61_Gain * LPDs_single_agent_tech_B.y[18];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain62' */
    LPDs_single_agent_tech_B.static_loadskW =
      LPDs_single_agent_tech_P.Gain62_Gain * LPDs_single_agent_tech_B.y[21];

    /* Gain: '<S5>/Gain63' */
    LPDs_single_agent_tech_B.static_load_usagekW =
      LPDs_single_agent_tech_P.Gain63_Gain * LPDs_single_agent_tech_B.y[22];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Gain: '<S5>/Gain64' */
    LPDs_single_agent_tech_B.TCL_loadskW = LPDs_single_agent_tech_P.Gain64_Gain *
      LPDs_single_agent_tech_B.y[24];

    /* Gain: '<S5>/Gain65' */
    LPDs_single_agent_tech_B.TCL_load_usagekW =
      LPDs_single_agent_tech_P.Gain65_Gain * LPDs_single_agent_tech_B.y[25];
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* Gain: '<S5>/Gain22' */
      LPDs_single_agent_tech_B.Gain22 = LPDs_single_agent_tech_P.Gain22_Gain *
        LPDs_single_agent_tech_B.Static_Load_demand;

      /* Gain: '<S5>/Gain23' */
      LPDs_single_agent_tech_B.Gain23 = LPDs_single_agent_tech_P.Gain23_Gain *
        LPDs_single_agent_tech_B.TCL_Load_demand;

      /* Gain: '<S5>/Gain24' */
      LPDs_single_agent_tech_B.Gain24 = LPDs_single_agent_tech_P.Gain24_Gain *
        LPDs_single_agent_tech_B.EV_Load_demand;
    }

    /* Gain: '<S5>/Gain21' */
    LPDs_single_agent_tech_B.Gain21 = LPDs_single_agent_tech_P.Gain21_Gain *
      rtb_nano_grid_controller_power;

    /* Gain: '<S5>/Gain3' */
    LPDs_single_agent_tech_B.Gain3 = LPDs_single_agent_tech_P.Gain3_Gain_n *
      rtb_Wind_power_forecast;

    /* Gain: '<S5>/Gain' */
    LPDs_single_agent_tech_B.Gain_f = LPDs_single_agent_tech_P.Gain_Gain_e *
      LPDs_single_agent_tech_B.PV1_power_state;
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* Gain: '<S5>/Gain5' */
      LPDs_single_agent_tech_B.Gain5 = LPDs_single_agent_tech_P.Gain5_Gain *
        LPDs_single_agent_tech_B.battery_discharging_power;

      /* Gain: '<S5>/Gain16' */
      LPDs_single_agent_tech_B.Gain16 = LPDs_single_agent_tech_P.Gain16_Gain *
        LPDs_single_agent_tech_B.battery_charging_power;

      /* Chart: '<S5>/Chart' */
      switch (LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech) {
       case LPDs_single__IN_Initialization1:
        LPDs_single_age_Initialization1();
        break;

       case LPDs_single__IN_Initialization2:
        if (LPDs_single_agent_tech_DW.load <= LPDs_single_agent_tech_B.Gain_f) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_IN_category_1;
          LPDs_single_agent_tech_DW.dPV = LPDs_single_agent_tech_B.Gain_f -
            LPDs_single_agent_tech_DW.load;
        } else {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_t_IN_Use_Wind;
          LPDs_single_agent_tech_DW.load_ = LPDs_single_agent_tech_DW.load -
            LPDs_single_agent_tech_B.Gain_f;
        }
        break;

       case LPD_IN_Nano_Grid_Initiliazation:
        if (LPDs_single_agent_tech_DW.nano_grid_demand > 0.0) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_tech_IN_el;
          LPDs_single_agent_tech_DW.dP = LPDs_single_agent_tech_DW.PV_remain -
            LPDs_single_agent_tech_DW.nano_grid_demand;
        } else {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_tech_IN_PV;
          LPDs_single_age_enter_atomic_PV();
        }
        break;

       case LPDs_singl_IN_Output_parameters:
        break;

       case LPDs_single_agent_tech_IN_PV:
        LPDs_single_agent_tech_PV();
        break;

       case LPDs_single__IN_PV_Power_Mode_1:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPD_IN_Nano_Grid_Initiliazation;
        LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_remain = LPDs_single_agent_tech_B.Gain_f -
          LPDs_single_agent_tech_DW.PV_load_usage;
        LPDs_single_agent_tech_DW.wind_remain = LPDs_single_agent_tech_B.Gain3 -
          LPDs_single_agent_tech_DW.wind_load_usage;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain;
        break;

       case LPDs_single__IN_PV_Power_Mode_2:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPD_IN_Nano_Grid_Initiliazation;
        LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_remain = LPDs_single_agent_tech_B.Gain_f -
          LPDs_single_agent_tech_DW.PV_load_usage;
        LPDs_single_agent_tech_DW.wind_remain = LPDs_single_agent_tech_B.Gain3 -
          LPDs_single_agent_tech_DW.wind_load_usage;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain;
        break;

       case LPDs_single__IN_PV_Power_Mode_3:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPD_IN_Nano_Grid_Initiliazation;
        LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_remain = LPDs_single_agent_tech_B.Gain_f -
          LPDs_single_agent_tech_DW.PV_load_usage;
        LPDs_single_agent_tech_DW.wind_remain = LPDs_single_agent_tech_B.Gain3 -
          LPDs_single_agent_tech_DW.wind_load_usage;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain;
        break;

       case L_IN_PV_Wind_Battery_Power_Mode:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPD_IN_Nano_Grid_Initiliazation;
        LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_remain = LPDs_single_agent_tech_B.Gain_f -
          LPDs_single_agent_tech_DW.PV_load_usage;
        LPDs_single_agent_tech_DW.wind_remain = LPDs_single_agent_tech_B.Gain3 -
          LPDs_single_agent_tech_DW.wind_load_usage;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain;
        break;

       case IN_PV_Wind_Battery_Power_Mode_l:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPD_IN_Nano_Grid_Initiliazation;
        LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage = 0.0;
        LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage = 0.0;
        LPDs_single_agent_tech_DW.PV_remain = LPDs_single_agent_tech_B.Gain_f -
          LPDs_single_agent_tech_DW.PV_load_usage;
        LPDs_single_agent_tech_DW.wind_remain = LPDs_single_agent_tech_B.Gain3 -
          LPDs_single_agent_tech_DW.wind_load_usage;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain;
        break;

       case IN_PV_Wind_Battery_Power_Mode_k:
        PV_Wind_Battery_Power_Mode_load();
        break;

       case LPDs_si_IN_PV_Wind_Power_Mode_1:
        PV_Wind_Battery_Power_Mode_load();
        break;

       case LPDs_si_IN_PV_Wind_Power_Mode_2:
        PV_Wind_Battery_Power_Mode_load();
        break;

       case LPDs_single_agen_IN_Use_Battery:
        if (LPDs_single_agent_tech_DW.load_ <= LPDs_single_agent_tech_B.Gain5) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_IN_category_3;
        } else {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_IN_load_flexibility;
          LPDs_single_agent_tech_DW.load_ = ((LPDs_single_agent_tech_DW.load -
            LPDs_single_agent_tech_B.Gain_f) - LPDs_single_agent_tech_B.Gain3) -
            LPDs_single_agent_tech_B.Gain5;
          LPDs_single_agent_tech_DW.load_min = (LPDs_single_agent_tech_ktcl_min *
            LPDs_single_agent_tech_B.Gain23 + LPDs_single_agent_tech_B.Gain22) +
            LPDs_single_agent_tech_kev_min * LPDs_single_agent_tech_B.Gain24;
          LPDs_single_agent_tech_DW.power_remain =
            ((LPDs_single_agent_tech_B.Gain_f + LPDs_single_agent_tech_B.Gain3)
             + LPDs_single_agent_tech_B.Gain5) -
            LPDs_single_agent_tech_DW.load_min;
        }
        break;

       case LPDs_single_agent_t_IN_Use_Wind:
        if (LPDs_single_agent_tech_DW.load_ <= LPDs_single_agent_tech_B.Gain3) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_IN_category_2;
          LPDs_single_agent_tech_DW.dwind = (LPDs_single_agent_tech_B.Gain_f +
            LPDs_single_agent_tech_B.Gain3) - LPDs_single_agent_tech_DW.load;
        } else if (LPDs_single_agent_tech_DW.load >
                   LPDs_single_agent_tech_B.Gain3) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agen_IN_Use_Battery;
          LPDs_single_agent_tech_DW.load_ = (LPDs_single_agent_tech_DW.load -
            LPDs_single_agent_tech_B.Gain_f) - LPDs_single_agent_tech_B.Gain3;
        }
        break;

       case LPDs_single_ag_IN_Use_microgrid:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPDs_single_agent_IN_category_7;
        LPDs_single_agent_tech_DW.nanogrid_usage =
          LPDs_single_agent_tech_DW.nano_grid_supply;
        LPDs_single_agent_tech_DW.mg_power_usage_load =
          LPDs_single_agent_tech_DW.load_;
        break;

       case LPDs_single_agent_IN_category_1:
        LPDs_single_agent_te_category_1();
        break;

       case LPDs_single_agent_IN_category_2:
        LPDs_single_agent_te_category_2();
        break;

       case LPDs_single_agent_IN_category_3:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          L_IN_PV_Wind_Battery_Power_Mode;
        LPDs_single_agent_tech_DW.PV_load_usage =
          LPDs_single_agent_tech_B.Gain_f;
        LPDs_single_agent_tech_DW.wind_load_usage =
          LPDs_single_agent_tech_B.Gain3;
        LPDs_single_agent_tech_DW.battery_charging_power_out = 0.0;
        LPDs_single_agent_tech_DW.battery_discharging_power_out =
          (LPDs_single_agent_tech_DW.load - LPDs_single_agent_tech_B.Gain_f) -
          LPDs_single_agent_tech_B.Gain3;
        LPDs_single_agent_tech_DW.battery_usage =
          LPDs_single_agent_tech_DW.battery_discharging_power_out;
        LPDs_single_agent_tech_DW.static_load_usage =
          LPDs_single_agent_tech_B.Gain22;
        LPDs_single_agent_tech_DW.TCL_load_usage =
          LPDs_single_agent_tech_B.Gain23;
        LPDs_single_agent_tech_DW.EV_load_usage =
          LPDs_single_agent_tech_B.Gain24;
        break;

       case LPDs_single_agent_IN_category_4:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          IN_PV_Wind_Battery_Power_Mode_l;
        LPDs_single_agent_tech_DW.PV_load_usage =
          LPDs_single_agent_tech_B.Gain_f;
        LPDs_single_agent_tech_DW.wind_load_usage =
          LPDs_single_agent_tech_B.Gain3;
        LPDs_single_agent_tech_DW.battery_charging_power_out = 0.0;
        LPDs_single_agent_tech_DW.battery_discharging_power_out =
          LPDs_single_agent_tech_B.Gain5;
        LPDs_single_agent_tech_DW.battery_usage =
          LPDs_single_agent_tech_DW.battery_discharging_power_out;
        LPDs_single_agent_tech_DW.static_load_usage =
          LPDs_single_agent_tech_DW.ks * LPDs_single_agent_tech_B.Gain22;
        LPDs_single_agent_tech_DW.TCL_load_usage = LPDs_single_agent_tech_DW.kt *
          LPDs_single_agent_tech_B.Gain23;
        LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_DW.ke *
          LPDs_single_agent_tech_B.Gain24;
        break;

       case LPDs_single_agent_IN_category_6:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          IN_PV_Wind_Battery_Power_Mode_k;
        LPDs_single_agent_tech_DW.PV_load_usage =
          LPDs_single_agent_tech_B.Gain_f;
        LPDs_single_agent_tech_DW.wind_load_usage =
          LPDs_single_agent_tech_B.Gain3;
        LPDs_single_agent_tech_DW.battery_charging_power_out = 0.0;
        LPDs_single_agent_tech_DW.battery_discharging_power_out =
          LPDs_single_agent_tech_B.Gain5;
        LPDs_single_agent_tech_DW.battery_usage =
          LPDs_single_agent_tech_DW.battery_discharging_power_out;
        LPDs_single_agent_tech_DW.static_load_usage =
          LPDs_single_agent_tech_B.Gain22;
        LPDs_single_agent_tech_DW.TCL_load_usage =
          LPDs_single_agent_tech_ktcl_min * LPDs_single_agent_tech_B.Gain23;
        LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_kev_min
          * LPDs_single_agent_tech_B.Gain24;
        LPDs_single_agent_tech_DW.nanogrid_remain =
          LPDs_single_agent_tech_DW.nano_grid_supply -
          LPDs_single_agent_tech_DW.nanogrid_usage;
        break;

       case LPDs_single_agent_IN_category_7:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          IN_PV_Wind_Battery_Power_Mode_k;
        LPDs_single_agent_tech_DW.PV_load_usage =
          LPDs_single_agent_tech_B.Gain_f;
        LPDs_single_agent_tech_DW.wind_load_usage =
          LPDs_single_agent_tech_B.Gain3;
        LPDs_single_agent_tech_DW.battery_charging_power_out = 0.0;
        LPDs_single_agent_tech_DW.battery_discharging_power_out =
          LPDs_single_agent_tech_B.Gain5;
        LPDs_single_agent_tech_DW.battery_usage =
          LPDs_single_agent_tech_DW.battery_discharging_power_out;
        LPDs_single_agent_tech_DW.static_load_usage =
          LPDs_single_agent_tech_B.Gain22;
        LPDs_single_agent_tech_DW.TCL_load_usage =
          LPDs_single_agent_tech_ktcl_min * LPDs_single_agent_tech_B.Gain23;
        LPDs_single_agent_tech_DW.EV_load_usage = LPDs_single_agent_tech_kev_min
          * LPDs_single_agent_tech_B.Gain24;
        LPDs_single_agent_tech_DW.nanogrid_remain =
          LPDs_single_agent_tech_DW.nano_grid_supply -
          LPDs_single_agent_tech_DW.nanogrid_usage;
        break;

       case LPDs_single_agent_tech_IN_ds:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPDs_single_agent_tech_IN_fi;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain -
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain -
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage =
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage =
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage;
        break;

       case LPDs_single_agent_tech_IN_ds1:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPDs_single_agent_tech_IN_fi;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain -
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain -
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage =
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage =
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage;
        break;

       case LPDs_single_agent_tech_IN_el:
        if (LPDs_single_agent_tech_DW.dP < 0.0) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_tech_IN_ell;
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage =
            LPDs_single_agent_tech_DW.PV_remain;
          LPDs_single_agent_tech_DW.dPw = (LPDs_single_agent_tech_DW.PV_remain +
            LPDs_single_agent_tech_DW.wind_remain) -
            LPDs_single_agent_tech_DW.nano_grid_demand;
        } else {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_tech_IN_ds;
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage =
            LPDs_single_agent_tech_DW.nano_grid_demand;
        }
        break;

       case LPDs_single_agent_tech_IN_ell:
        if (LPDs_single_agent_tech_DW.dPw < 0.0) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_tech_IN_ell1;
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage =
            LPDs_single_agent_tech_DW.wind_remain;
          mg = (LPDs_single_agent_tech_DW.nano_grid_demand -
                LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage) -
            LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage;
          LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = mg;
          LPDs_single_agent_tech_DW.mg_power_usage_nanogrid = mg;
        } else {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_tech_IN_ds1;
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage =
            LPDs_single_agent_tech_DW.nano_grid_demand -
            LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage;
        }
        break;

       case LPDs_single_agent_tech_IN_ell1:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPDs_single_agent_tech_IN_fi;
        LPDs_single_agent_tech_DW.PV_remain_ =
          LPDs_single_agent_tech_DW.PV_remain -
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage;
        LPDs_single_agent_tech_DW.wind_remain_ =
          LPDs_single_agent_tech_DW.wind_remain -
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage;
        LPDs_single_agent_tech_DW.PV_nanogrid_usage =
          LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage;
        LPDs_single_agent_tech_DW.wind_nanogrid_usage =
          LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage;
        break;

       case LPDs_single_agent_tech_IN_fi:
        LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
          LPDs_single_agent_tech_IN_PV;
        LPDs_single_age_enter_atomic_PV();
        break;

       case LPDs_single_IN_load_flexibility:
        LPDs_single_ag_load_flexibility();
        break;

       default:
        /* case IN_use_nanogrid: */
        if (LPDs_single_agent_tech_DW.load_ <=
            LPDs_single_agent_tech_DW.nano_grid_supply) {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_agent_IN_category_6;
          LPDs_single_agent_tech_DW.nanogrid_usage =
            ((LPDs_single_agent_tech_DW.load_min -
              LPDs_single_agent_tech_B.Gain_f) - LPDs_single_agent_tech_B.Gain3)
            - LPDs_single_agent_tech_B.Gain5;
        } else {
          LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
            LPDs_single_ag_IN_Use_microgrid;
          LPDs_single_agent_tech_DW.load_ =
            (((LPDs_single_agent_tech_DW.load_min -
               LPDs_single_agent_tech_B.Gain_f) - LPDs_single_agent_tech_B.Gain3)
             - LPDs_single_agent_tech_B.Gain5) -
            LPDs_single_agent_tech_DW.nano_grid_supply;
        }
        break;
      }

      /* End of Chart: '<S5>/Chart' */
    }

    /* RelationalOperator: '<S38>/Compare' incorporates:
     *  Constant: '<S38>/Constant'
     */
    LPDs_single_agent_tech_B.Compare_n = (rtb_nano_grid_controller_power <
      LPDs_single_agent_tech_P.Constant_Value_l);

    /* RelationalOperator: '<S39>/Compare' incorporates:
     *  Constant: '<S39>/Constant'
     */
    LPDs_single_agent_tech_B.Compare_n1 = (rtb_nano_grid_controller_power >
      LPDs_single_agent_tech_P.Constant_Value_k);
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* SignalConversion generated from: '<S36>/Enable' */
      LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_nanogrida =
        LPDs_single_agent_tech_B.Compare_n;

      /* SignalConversion generated from: '<S37>/Enable' */
      LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_nanogri_o =
        LPDs_single_agent_tech_B.Compare_n1;

      /* Memory: '<S34>/Memory2' */
      memcpy(&LPDs_single_agent_tech_B.Memory2[0],
             &LPDs_single_agent_tech_DW.Memory2_PreviousInput[0], sizeof(real_T)
             << 3U);

      /* RelationalOperator: '<S32>/Compare' incorporates:
       *  Constant: '<S32>/Constant'
       */
      LPDs_single_agent_tech_B.Compare_g =
        (LPDs_single_agent_tech_B.micro_grid_power <
         LPDs_single_agent_tech_P.Constant_Value_a);

      /* Outputs for Enabled SubSystem: '<S5>/Micro grid as load' incorporates:
       *  EnablePort: '<S30>/Enable'
       */
      if (rtsiIsModeUpdateTimeStep(&LPDs_single_agent_tech_M->solverInfo)) {
        if (LPDs_single_agent_tech_B.Compare_g) {
          LPDs_single_agent_tech_DW.Microgridasload_MODE = true;
        } else if (LPDs_single_agent_tech_DW.Microgridasload_MODE) {
          /* Disable for Enabled SubSystem: '<S30>/Enabled Subsystem' */
          if (LPDs_single_agent_tech_DW.EnabledSubsystem.EnabledSubsystem_MODE)
          {
            LPDs_s_EnabledSubsystem_Disable
              (&LPDs_single_agent_tech_DW.EnabledSubsystem);
          }

          /* End of Disable for SubSystem: '<S30>/Enabled Subsystem' */
          LPDs_single_agent_tech_DW.Microgridasload_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S5>/Micro grid as load' */
    }

    /* Outputs for Enabled SubSystem: '<S5>/Micro grid as load' incorporates:
     *  EnablePort: '<S30>/Enable'
     */
    if (LPDs_single_agent_tech_DW.Microgridasload_MODE) {
      if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
        /* Logic: '<S30>/(96%) EV_load <= EV_load_action <= EV_load' incorporates:
         *  Gain: '<S30>/96.00%'
         *  RelationalOperator: '<S30>/(96%) EV_load <= EV_load_action'
         *  RelationalOperator: '<S30>/EV_load_action<= EV_load'
         */
        LPDs_single_agent_tech_B.EV_load_requirements_b =
          ((LPDs_single_agent_tech_B.Memory2[7] >=
            LPDs_single_agent_tech_P.u600_Gain *
            LPDs_single_agent_tech_B.EV_Load_demand) &&
           (LPDs_single_agent_tech_B.Memory2[7] <=
            LPDs_single_agent_tech_B.EV_Load_demand));

        /* Logic: '<S30>/(96%) TCL_load <= TCL_load_action <=  TCL_load' incorporates:
         *  Gain: '<S30>/96%'
         *  RelationalOperator: '<S30>/(96%) TCL_load <= TCL_load_action'
         *  RelationalOperator: '<S30>/TCL_load_action<= TCL_load'
         */
        LPDs_single_agent_tech_B.TCL_load_requirements_h =
          ((LPDs_single_agent_tech_B.Memory2[6] >=
            LPDs_single_agent_tech_P.u6_Gain *
            LPDs_single_agent_tech_B.TCL_Load_demand) &&
           (LPDs_single_agent_tech_B.Memory2[6] <=
            LPDs_single_agent_tech_B.TCL_Load_demand));

        /* Logic: '<S30>/(96%) static_load <= static_load_action <=  static_load' incorporates:
         *  Gain: '<S30>/96 %'
         *  RelationalOperator: '<S30>/(96%) static_load <= static_load_action'
         *  RelationalOperator: '<S30>/static_load_action<= static_load'
         */
        LPDs_single_agent_tech_B.static_load_requirements_c =
          ((LPDs_single_agent_tech_B.Memory2[5] >=
            LPDs_single_agent_tech_P.u6_Gain_j *
            LPDs_single_agent_tech_B.Static_Load_demand) &&
           (LPDs_single_agent_tech_B.Memory2[5] <=
            LPDs_single_agent_tech_B.Static_Load_demand));

        /* Abs: '<S30>/Abs' */
        LPDs_single_agent_tech_B.Abs_e = fabs(LPDs_single_agent_tech_B.Memory2[3]);

        /* RelationalOperator: '<S30>/Micro Grid power Over Limit' incorporates:
         *  Abs: '<S30>/Abs2'
         *  Abs: '<S30>/Abs3'
         */
        LPDs_single_agent_tech_B.micro_grid_controllers_action_g = (fabs
          (LPDs_single_agent_tech_B.micro_grid_power) >= 0.0);
      }

      /* Logic: '<S30>/micro grid  power utilization' incorporates:
       *  Abs: '<S30>/Abs1'
       *  Constant: '<S30>/Constant'
       *  Gain: '<S30>/nearly (max limit)'
       *  RelationalOperator: '<S30>/Battery SOC > 90%'
       *  RelationalOperator: '<S30>/Nano Grid power Over Limit'
       */
      rtb_microgridpowerutilization_o =
        (LPDs_single_agent_tech_B.static_load_requirements_c &&
         LPDs_single_agent_tech_B.TCL_load_requirements_h &&
         LPDs_single_agent_tech_B.EV_load_requirements_b &&
         (LPDs_single_agent_tech_B.Gain >=
          LPDs_single_agent_tech_P.Constant_Value) &&
         (LPDs_single_agent_tech_B.Abs_e >= fabs
          (LPDs_single_agent_tech_P.nearlymaxlimit_Gain *
           rtb_nano_grid_controller_power)) &&
         LPDs_single_agent_tech_B.micro_grid_controllers_action_g);

      /* Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' */
      LPDs_single_ag_EnabledSubsystem(LPDs_single_agent_tech_M,
        rtb_microgridpowerutilization_o,
        &LPDs_single_agent_tech_DW.EnabledSubsystem);

      /* End of Outputs for SubSystem: '<S30>/Enabled Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S5>/Micro grid as load' */
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* RelationalOperator: '<S33>/Compare' incorporates:
       *  Constant: '<S33>/Constant'
       */
      LPDs_single_agent_tech_B.Compare_j =
        (LPDs_single_agent_tech_B.micro_grid_power >
         LPDs_single_agent_tech_P.Constant_Value_aw);

      /* Outputs for Enabled SubSystem: '<S5>/Micro grid as source' incorporates:
       *  EnablePort: '<S31>/Enable'
       */
      if (rtsiIsModeUpdateTimeStep(&LPDs_single_agent_tech_M->solverInfo)) {
        if (LPDs_single_agent_tech_B.Compare_j) {
          LPDs_single_agent_tech_DW.Microgridassource_MODE = true;
        } else if (LPDs_single_agent_tech_DW.Microgridassource_MODE) {
          /* Disable for Enabled SubSystem: '<S31>/Enabled Subsystem' */
          if (LPDs_single_agent_tech_DW.EnabledSubsystem_i.EnabledSubsystem_MODE)
          {
            LPDs_s_EnabledSubsystem_Disable
              (&LPDs_single_agent_tech_DW.EnabledSubsystem_i);
          }

          /* End of Disable for SubSystem: '<S31>/Enabled Subsystem' */
          LPDs_single_agent_tech_DW.Microgridassource_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S5>/Micro grid as source' */
    }

    /* Outputs for Enabled SubSystem: '<S5>/Micro grid as source' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    if (LPDs_single_agent_tech_DW.Microgridassource_MODE) {
      if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
        /* Gain: '<S31>/(max limit)' incorporates:
         *  Constant: '<S1>/Constant10'
         */
        LPDs_single_agent_tech_B.maxlimit =
          LPDs_single_agent_tech_P.maxlimit_Gain *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;

        /* DataTypeConversion: '<S31>/Cast To Boolean' */
        LPDs_single_agent_tech_B.PVutilizationis96100_j = false;

        /* DataTypeConversion: '<S31>/Cast To Boolean1' */
        LPDs_single_agent_tech_B.windutilizationis96100_g = false;

        /* RelationalOperator: '<S31>/micro Grid power Over Limit' */
        LPDs_single_agent_tech_B.micro_grid_controllers_actionmi =
          (LPDs_single_agent_tech_B.micro_grid_power >= 0.0);
      }

      /* Logic: '<S31>/micro grid  power utilization' incorporates:
       *  Gain: '<S31>/nearly (max limit)'
       *  RelationalOperator: '<S31>/.'
       *  RelationalOperator: '<S31>/..'
       */
      rtb_microgridpowerutilization =
        (LPDs_single_agent_tech_B.PVutilizationis96100_j &&
         LPDs_single_agent_tech_B.windutilizationis96100_g &&
         (LPDs_single_agent_tech_B.Subsystem1.In1 >=
          LPDs_single_agent_tech_B.maxlimit) &&
         (LPDs_single_agent_tech_B.Memory2[3] >=
          LPDs_single_agent_tech_P.nearlymaxlimit_Gain_m *
          rtb_nano_grid_controller_power) &&
         LPDs_single_agent_tech_B.micro_grid_controllers_actionmi);

      /* Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem' */
      LPDs_single_ag_EnabledSubsystem(LPDs_single_agent_tech_M,
        rtb_microgridpowerutilization,
        &LPDs_single_agent_tech_DW.EnabledSubsystem_i);

      /* End of Outputs for SubSystem: '<S31>/Enabled Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S5>/Micro grid as source' */

    /* Outputs for Enabled SubSystem: '<S5>/nano grid as load' incorporates:
     *  EnablePort: '<S36>/Enable'
     */
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M) && rtsiIsModeUpdateTimeStep
        (&LPDs_single_agent_tech_M->solverInfo)) {
      if (LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_nanogrida) {
        LPDs_single_agent_tech_DW.nanogridasload_MODE = true;
      } else if (LPDs_single_agent_tech_DW.nanogridasload_MODE) {
        /* Disable for Enabled SubSystem: '<S36>/Enabled Subsystem' */
        if (LPDs_single_agent_tech_DW.EnabledSubsystem_g.EnabledSubsystem_MODE)
        {
          LPDs_EnabledSubsystem_n_Disable
            (&LPDs_single_agent_tech_DW.EnabledSubsystem_g);
        }

        /* End of Disable for SubSystem: '<S36>/Enabled Subsystem' */
        LPDs_single_agent_tech_DW.nanogridasload_MODE = false;
      }
    }

    if (LPDs_single_agent_tech_DW.nanogridasload_MODE) {
      if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
        /* Logic: '<S36>/(96%) EV_load <= EV_load_action <= EV_load' incorporates:
         *  Gain: '<S36>/96.00%'
         *  RelationalOperator: '<S36>/(96%) EV_load <= EV_load_action'
         *  RelationalOperator: '<S36>/EV_load_action<= EV_load'
         */
        LPDs_single_agent_tech_B.EV_load_requirements =
          ((LPDs_single_agent_tech_B.Memory2[7] >=
            LPDs_single_agent_tech_P.u600_Gain_i *
            LPDs_single_agent_tech_B.EV_Load_demand) &&
           (LPDs_single_agent_tech_B.Memory2[7] <=
            LPDs_single_agent_tech_B.EV_Load_demand));

        /* Logic: '<S36>/(96%) TCL_load <= TCL_load_action <=  TCL_load' incorporates:
         *  Gain: '<S36>/96%'
         *  RelationalOperator: '<S36>/(96%) TCL_load <= TCL_load_action'
         *  RelationalOperator: '<S36>/TCL_load_action<= TCL_load'
         */
        LPDs_single_agent_tech_B.TCL_load_requirements =
          ((LPDs_single_agent_tech_B.Memory2[6] >=
            LPDs_single_agent_tech_P.u6_Gain_m *
            LPDs_single_agent_tech_B.TCL_Load_demand) &&
           (LPDs_single_agent_tech_B.Memory2[6] <=
            LPDs_single_agent_tech_B.TCL_Load_demand));

        /* Logic: '<S36>/(96%) static_load <= static_load_action <=  static_load' incorporates:
         *  Gain: '<S36>/96 %'
         *  RelationalOperator: '<S36>/(96%) static_load <= static_load_action'
         *  RelationalOperator: '<S36>/static_load_action<= static_load'
         */
        LPDs_single_agent_tech_B.static_load_requirements =
          ((LPDs_single_agent_tech_B.Memory2[5] >=
            LPDs_single_agent_tech_P.u6_Gain_p *
            LPDs_single_agent_tech_B.Static_Load_demand) &&
           (LPDs_single_agent_tech_B.Memory2[5] <=
            LPDs_single_agent_tech_B.Static_Load_demand));

        /* Abs: '<S36>/Abs' */
        LPDs_single_agent_tech_B.Abs = fabs(LPDs_single_agent_tech_B.Memory2[3]);
      }

      /* Logic: '<S36>/nano grid  power utilization' incorporates:
       *  Abs: '<S36>/Abs1'
       *  Constant: '<S36>/Constant'
       *  RelationalOperator: '<S36>/Battery SOC > 90%'
       *  RelationalOperator: '<S36>/Nano Grid power Over Limit'
       */
      rtb_nanogridpowerutilization_a =
        (LPDs_single_agent_tech_B.static_load_requirements &&
         LPDs_single_agent_tech_B.TCL_load_requirements &&
         LPDs_single_agent_tech_B.EV_load_requirements &&
         (LPDs_single_agent_tech_B.Gain >=
          LPDs_single_agent_tech_P.Constant_Value_b) &&
         (LPDs_single_agent_tech_B.Abs <= fabs(rtb_nano_grid_controller_power)));

      /* Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem' */
      LPDs_single__EnabledSubsystem_g(LPDs_single_agent_tech_M,
        rtb_nanogridpowerutilization_a,
        &LPDs_single_agent_tech_DW.EnabledSubsystem_g);

      /* End of Outputs for SubSystem: '<S36>/Enabled Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S5>/nano grid as load' */

    /* Outputs for Enabled SubSystem: '<S5>/nano grid as source' incorporates:
     *  EnablePort: '<S37>/Enable'
     */
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M) && rtsiIsModeUpdateTimeStep
        (&LPDs_single_agent_tech_M->solverInfo)) {
      if (LPDs_single_agent_tech_B.HiddenBuf_InsertedFor_nanogri_o) {
        LPDs_single_agent_tech_DW.nanogridassource_MODE = true;
      } else if (LPDs_single_agent_tech_DW.nanogridassource_MODE) {
        /* Disable for Enabled SubSystem: '<S37>/Enabled Subsystem' */
        if (LPDs_single_agent_tech_DW.EnabledSubsystem_p.EnabledSubsystem_MODE)
        {
          LPDs_EnabledSubsystem_n_Disable
            (&LPDs_single_agent_tech_DW.EnabledSubsystem_p);
        }

        /* End of Disable for SubSystem: '<S37>/Enabled Subsystem' */
        LPDs_single_agent_tech_DW.nanogridassource_MODE = false;
      }
    }

    if (LPDs_single_agent_tech_DW.nanogridassource_MODE) {
      if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
        /* Gain: '<S37>/30% of (max limit)' incorporates:
         *  Constant: '<S1>/Constant10'
         */
        LPDs_single_agent_tech_B.u0ofmaxlimit =
          LPDs_single_agent_tech_P.u0ofmaxlimit_Gain *
          LPDs_single_agent_tech_P.battery_discharge_power_state_upper_limit;

        /* DataTypeConversion: '<S37>/Cast To Boolean' */
        LPDs_single_agent_tech_B.PVutilizationis96100 = false;

        /* DataTypeConversion: '<S37>/Cast To Boolean1' */
        LPDs_single_agent_tech_B.windutilizationis96100 = false;
      }

      /* Logic: '<S37>/nano grid  power utilization' incorporates:
       *  RelationalOperator: '<S37>/.'
       *  RelationalOperator: '<S37>/Nano Grid power Over Limit'
       */
      rtb_nanogridpowerutilization =
        (LPDs_single_agent_tech_B.PVutilizationis96100 &&
         LPDs_single_agent_tech_B.windutilizationis96100 &&
         (LPDs_single_agent_tech_B.Subsystem1.In1 <=
          LPDs_single_agent_tech_B.u0ofmaxlimit) &&
         (LPDs_single_agent_tech_B.Memory2[3] <= rtb_nano_grid_controller_power));

      /* Outputs for Enabled SubSystem: '<S37>/Enabled Subsystem' */
      LPDs_single__EnabledSubsystem_g(LPDs_single_agent_tech_M,
        rtb_nanogridpowerutilization,
        &LPDs_single_agent_tech_DW.EnabledSubsystem_p);

      /* End of Outputs for SubSystem: '<S37>/Enabled Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S5>/nano grid as source' */

    /* Derivative: '<S47>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_p >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_ei >= LookUpTable_tmp)) {
      /* Derivative: '<S47>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_k = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_p;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_p;
      if (LPDs_single_agent_tech_DW.TimeStampA_p <
          LPDs_single_agent_tech_DW.TimeStampB_ei) {
        if (LPDs_single_agent_tech_DW.TimeStampB_ei < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_ei;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_o;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_p >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_ei;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_o;
      }

      /* Derivative: '<S47>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_k =
        (LPDs_single_agent_tech_B.LookUpTable_o - *lastU) / (LookUpTable_tmp -
        error);
    }

    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    }

    /* Derivative: '<S51>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_pg >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_g >= LookUpTable_tmp)) {
      /* Derivative: '<S51>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_jh = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_pg;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_ie;
      if (LPDs_single_agent_tech_DW.TimeStampA_pg <
          LPDs_single_agent_tech_DW.TimeStampB_g) {
        if (LPDs_single_agent_tech_DW.TimeStampB_g < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_g;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_cy;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_pg >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_g;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_cy;
      }

      /* Derivative: '<S51>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_jh =
        (LPDs_single_agent_tech_B.LookUpTable - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S50>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_mb = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_n[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_bd[0]);

    /* Derivative: '<S50>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_a >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_k >= LookUpTable_tmp)) {
      /* Derivative: '<S50>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_jn = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_a;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_iu;
      if (LPDs_single_agent_tech_DW.TimeStampA_a <
          LPDs_single_agent_tech_DW.TimeStampB_k) {
        if (LPDs_single_agent_tech_DW.TimeStampB_k < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_k;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_i;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_a >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_k;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_i;
      }

      /* Derivative: '<S50>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_jn =
        (LPDs_single_agent_tech_B.LookUpTable_mb - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S54>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_k = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_p[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_d[0]);

    /* Derivative: '<S54>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_f >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_n >= LookUpTable_tmp)) {
      /* Derivative: '<S54>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_d = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_f;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_k;
      if (LPDs_single_agent_tech_DW.TimeStampA_f <
          LPDs_single_agent_tech_DW.TimeStampB_n) {
        if (LPDs_single_agent_tech_DW.TimeStampB_n < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_n;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_n;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_f >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_n;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_n;
      }

      /* Derivative: '<S54>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_d =
        (LPDs_single_agent_tech_B.LookUpTable_k - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S55>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_c = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_nj[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_j[0]);

    /* Derivative: '<S55>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_o1 >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_a >= LookUpTable_tmp)) {
      /* Derivative: '<S55>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_g = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_o1;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_b;
      if (LPDs_single_agent_tech_DW.TimeStampA_o1 <
          LPDs_single_agent_tech_DW.TimeStampB_a) {
        if (LPDs_single_agent_tech_DW.TimeStampB_a < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_a;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_d;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_o1 >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_a;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_d;
      }

      /* Derivative: '<S55>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_g =
        (LPDs_single_agent_tech_B.LookUpTable_c - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Derivative: '<S59>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_g >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_de >= LookUpTable_tmp)) {
      /* Derivative: '<S59>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_kn = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_g;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_gr;
      if (LPDs_single_agent_tech_DW.TimeStampA_g <
          LPDs_single_agent_tech_DW.TimeStampB_de) {
        if (LPDs_single_agent_tech_DW.TimeStampB_de < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_de;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_du;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_g >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_de;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_du;
      }

      /* Derivative: '<S59>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_kn =
        (LPDs_single_agent_tech_B.LookUpTable_i - *lastU) / (LookUpTable_tmp -
        error);
    }

    /* Lookup: '<S58>/Look-Up Table' */
    LPDs_single_agent_tech_B.LookUpTable_g = rt_Lookup
      (&LPDs_single_agent_tech_P.LookUpTable_XData_a5[0], 48, LookUpTable_tmp,
       &LPDs_single_agent_tech_P.LookUpTable_YData_bt[0]);

    /* Derivative: '<S58>/Derivative' */
    if ((LPDs_single_agent_tech_DW.TimeStampA_ml >= LookUpTable_tmp) &&
        (LPDs_single_agent_tech_DW.TimeStampB_ex >= LookUpTable_tmp)) {
      /* Derivative: '<S58>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_gh = 0.0;
    } else {
      error = LPDs_single_agent_tech_DW.TimeStampA_ml;
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_ei;
      if (LPDs_single_agent_tech_DW.TimeStampA_ml <
          LPDs_single_agent_tech_DW.TimeStampB_ex) {
        if (LPDs_single_agent_tech_DW.TimeStampB_ex < LookUpTable_tmp) {
          error = LPDs_single_agent_tech_DW.TimeStampB_ex;
          lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_bh;
        }
      } else if (LPDs_single_agent_tech_DW.TimeStampA_ml >= LookUpTable_tmp) {
        error = LPDs_single_agent_tech_DW.TimeStampB_ex;
        lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_bh;
      }

      /* Derivative: '<S58>/Derivative' */
      LPDs_single_agent_tech_B.Derivative_gh =
        (LPDs_single_agent_tech_B.LookUpTable_g - *lastU) / (LookUpTable_tmp -
        error);
    }
  }

  if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(LPDs_single_agent_tech_M->rtwLogInfo,
                        (LPDs_single_agent_tech_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    real_T *lastU;

    /* Update for Integrator: '<S1>/initial_battery_energy' */
    LPDs_single_agent_tech_DW.initial_battery_energy_IWORK = 0;

    /* Update for Derivative: '<S17>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA = LPDs_single_agent_tech_M->Timing.t
        [0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA;
    } else if (LPDs_single_agent_tech_DW.TimeStampB == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB = LPDs_single_agent_tech_M->Timing.t
        [0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB;
    } else if (LPDs_single_agent_tech_DW.TimeStampA <
               LPDs_single_agent_tech_DW.TimeStampB) {
      LPDs_single_agent_tech_DW.TimeStampA = LPDs_single_agent_tech_M->Timing.t
        [0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB = LPDs_single_agent_tech_M->Timing.t
        [0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_b;

    /* End of Update for Derivative: '<S17>/Derivative' */

    /* Update for Derivative: '<S18>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_o == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_o =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_h;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_e == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_e =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_k;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_o <
               LPDs_single_agent_tech_DW.TimeStampB_e) {
      LPDs_single_agent_tech_DW.TimeStampA_o =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_h;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_e =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_k;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_l;

    /* End of Update for Derivative: '<S18>/Derivative' */

    /* Update for Derivative: '<S19>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_o2 == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_o2 =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_e;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_p == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_p =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_b;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_o2 <
               LPDs_single_agent_tech_DW.TimeStampB_p) {
      LPDs_single_agent_tech_DW.TimeStampA_o2 =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_e;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_p =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_b;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_om;

    /* End of Update for Derivative: '<S19>/Derivative' */

    /* Update for Derivative: '<S23>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_m == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_m =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_i;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_d == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_d =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_c;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_m <
               LPDs_single_agent_tech_DW.TimeStampB_d) {
      LPDs_single_agent_tech_DW.TimeStampA_m =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_i;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_d =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_c;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_m;

    /* End of Update for Derivative: '<S23>/Derivative' */

    /* Update for Derivative: '<S24>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_i == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_i =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_g;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_dc == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_dc =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_j;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_i <
               LPDs_single_agent_tech_DW.TimeStampB_dc) {
      LPDs_single_agent_tech_DW.TimeStampA_i =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_g;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_dc =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_j;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_f;

    /* End of Update for Derivative: '<S24>/Derivative' */

    /* Update for Derivative: '<S25>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_j == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_j =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_d;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_o == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_o =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_kb;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_j <
               LPDs_single_agent_tech_DW.TimeStampB_o) {
      LPDs_single_agent_tech_DW.TimeStampA_j =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_d;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_o =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_kb;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_p;

    /* End of Update for Derivative: '<S25>/Derivative' */
    if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
      /* Update for Memory: '<S34>/Memory2' */
      memset(&LPDs_single_agent_tech_DW.Memory2_PreviousInput[0], 0, sizeof
             (real_T) << 3U);
    }

    /* Update for Derivative: '<S47>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_p == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_p =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_p;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_ei == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_ei =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_o;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_p <
               LPDs_single_agent_tech_DW.TimeStampB_ei) {
      LPDs_single_agent_tech_DW.TimeStampA_p =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_p;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_ei =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_o;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_o;

    /* End of Update for Derivative: '<S47>/Derivative' */

    /* Update for Derivative: '<S51>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_pg == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_pg =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_ie;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_g == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_g =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_cy;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_pg <
               LPDs_single_agent_tech_DW.TimeStampB_g) {
      LPDs_single_agent_tech_DW.TimeStampA_pg =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_ie;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_g =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_cy;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable;

    /* End of Update for Derivative: '<S51>/Derivative' */

    /* Update for Derivative: '<S50>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_a == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_a =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_iu;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_k == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_k =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_i;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_a <
               LPDs_single_agent_tech_DW.TimeStampB_k) {
      LPDs_single_agent_tech_DW.TimeStampA_a =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_iu;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_k =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_i;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_mb;

    /* End of Update for Derivative: '<S50>/Derivative' */

    /* Update for Derivative: '<S54>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_f == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_f =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_k;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_n == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_n =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_n;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_f <
               LPDs_single_agent_tech_DW.TimeStampB_n) {
      LPDs_single_agent_tech_DW.TimeStampA_f =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_k;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_n =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_n;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_k;

    /* End of Update for Derivative: '<S54>/Derivative' */

    /* Update for Derivative: '<S55>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_o1 == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_o1 =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_b;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_a == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_a =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_d;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_o1 <
               LPDs_single_agent_tech_DW.TimeStampB_a) {
      LPDs_single_agent_tech_DW.TimeStampA_o1 =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_b;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_a =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_d;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_c;

    /* End of Update for Derivative: '<S55>/Derivative' */

    /* Update for Derivative: '<S59>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_g == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_g =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_gr;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_de == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_de =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_du;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_g <
               LPDs_single_agent_tech_DW.TimeStampB_de) {
      LPDs_single_agent_tech_DW.TimeStampA_g =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_gr;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_de =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_du;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_i;

    /* End of Update for Derivative: '<S59>/Derivative' */

    /* Update for Derivative: '<S58>/Derivative' */
    if (LPDs_single_agent_tech_DW.TimeStampA_ml == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampA_ml =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_ei;
    } else if (LPDs_single_agent_tech_DW.TimeStampB_ex == (rtInf)) {
      LPDs_single_agent_tech_DW.TimeStampB_ex =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_bh;
    } else if (LPDs_single_agent_tech_DW.TimeStampA_ml <
               LPDs_single_agent_tech_DW.TimeStampB_ex) {
      LPDs_single_agent_tech_DW.TimeStampA_ml =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeA_ei;
    } else {
      LPDs_single_agent_tech_DW.TimeStampB_ex =
        LPDs_single_agent_tech_M->Timing.t[0];
      lastU = &LPDs_single_agent_tech_DW.LastUAtTimeB_bh;
    }

    *lastU = LPDs_single_agent_tech_B.LookUpTable_g;

    /* End of Update for Derivative: '<S58>/Derivative' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(LPDs_single_agent_tech_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(LPDs_single_agent_tech_M)!=-1) &&
          !((rtmGetTFinal(LPDs_single_agent_tech_M)-
             (((LPDs_single_agent_tech_M->Timing.clockTick1+
                LPDs_single_agent_tech_M->Timing.clockTickH1* 4294967296.0)) *
              0.005)) > (((LPDs_single_agent_tech_M->Timing.clockTick1+
                           LPDs_single_agent_tech_M->Timing.clockTickH1*
                           4294967296.0)) * 0.005) * (DBL_EPSILON))) {
        rtmSetErrorStatus(LPDs_single_agent_tech_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&LPDs_single_agent_tech_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++LPDs_single_agent_tech_M->Timing.clockTick0)) {
      ++LPDs_single_agent_tech_M->Timing.clockTickH0;
    }

    LPDs_single_agent_tech_M->Timing.t[0] = rtsiGetSolverStopTime
      (&LPDs_single_agent_tech_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      LPDs_single_agent_tech_M->Timing.clockTick1++;
      if (!LPDs_single_agent_tech_M->Timing.clockTick1) {
        LPDs_single_agent_tech_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void LPDs_single_agent_tech_derivatives(void)
{
  XDot_LPDs_single_agent_tech_T *_rtXdot;
  _rtXdot = ((XDot_LPDs_single_agent_tech_T *) LPDs_single_agent_tech_M->derivs);

  /* Derivatives for Integrator: '<S1>/initial_battery_energy' */
  _rtXdot->initial_battery_energy_CSTATE = LPDs_single_agent_tech_B.Sum;
}

/* Model initialize function */
void LPDs_single_agent_tech_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LPDs_single_agent_tech_M, 0,
                sizeof(RT_MODEL_LPDs_single_agent_te_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LPDs_single_agent_tech_M->solverInfo,
                          &LPDs_single_agent_tech_M->Timing.simTimeStep);
    rtsiSetTPtr(&LPDs_single_agent_tech_M->solverInfo, &rtmGetTPtr
                (LPDs_single_agent_tech_M));
    rtsiSetStepSizePtr(&LPDs_single_agent_tech_M->solverInfo,
                       &LPDs_single_agent_tech_M->Timing.stepSize0);
    rtsiSetdXPtr(&LPDs_single_agent_tech_M->solverInfo,
                 &LPDs_single_agent_tech_M->derivs);
    rtsiSetContStatesPtr(&LPDs_single_agent_tech_M->solverInfo, (real_T **)
                         &LPDs_single_agent_tech_M->contStates);
    rtsiSetNumContStatesPtr(&LPDs_single_agent_tech_M->solverInfo,
      &LPDs_single_agent_tech_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&LPDs_single_agent_tech_M->solverInfo,
      &LPDs_single_agent_tech_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&LPDs_single_agent_tech_M->solverInfo,
      &LPDs_single_agent_tech_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&LPDs_single_agent_tech_M->solverInfo,
      &LPDs_single_agent_tech_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&LPDs_single_agent_tech_M->solverInfo,
      (boolean_T**) &LPDs_single_agent_tech_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&LPDs_single_agent_tech_M->solverInfo,
                          (&rtmGetErrorStatus(LPDs_single_agent_tech_M)));
    rtsiSetRTModelPtr(&LPDs_single_agent_tech_M->solverInfo,
                      LPDs_single_agent_tech_M);
  }

  rtsiSetSimTimeStep(&LPDs_single_agent_tech_M->solverInfo, MAJOR_TIME_STEP);
  LPDs_single_agent_tech_M->intgData.y = LPDs_single_agent_tech_M->odeY;
  LPDs_single_agent_tech_M->intgData.f[0] = LPDs_single_agent_tech_M->odeF[0];
  LPDs_single_agent_tech_M->intgData.f[1] = LPDs_single_agent_tech_M->odeF[1];
  LPDs_single_agent_tech_M->intgData.f[2] = LPDs_single_agent_tech_M->odeF[2];
  LPDs_single_agent_tech_M->contStates = ((X_LPDs_single_agent_tech_T *)
    &LPDs_single_agent_tech_X);
  LPDs_single_agent_tech_M->contStateDisabled = ((XDis_LPDs_single_agent_tech_T *)
    &LPDs_single_agent_tech_XDis);
  LPDs_single_agent_tech_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&LPDs_single_agent_tech_M->solverInfo, (void *)
                    &LPDs_single_agent_tech_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&LPDs_single_agent_tech_M->solverInfo,
    false);
  rtsiSetSolverName(&LPDs_single_agent_tech_M->solverInfo,"ode3");
  rtmSetTPtr(LPDs_single_agent_tech_M, &LPDs_single_agent_tech_M->Timing.tArray
             [0]);
  rtmSetTFinal(LPDs_single_agent_tech_M, 24.0);
  LPDs_single_agent_tech_M->Timing.stepSize0 = 0.005;
  rtmSetFirstInitCond(LPDs_single_agent_tech_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    LPDs_single_agent_tech_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(LPDs_single_agent_tech_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(LPDs_single_agent_tech_M->rtwLogInfo, (NULL));
    rtliSetLogT(LPDs_single_agent_tech_M->rtwLogInfo, "tout");
    rtliSetLogX(LPDs_single_agent_tech_M->rtwLogInfo, "");
    rtliSetLogXFinal(LPDs_single_agent_tech_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(LPDs_single_agent_tech_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(LPDs_single_agent_tech_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(LPDs_single_agent_tech_M->rtwLogInfo, 0);
    rtliSetLogDecimation(LPDs_single_agent_tech_M->rtwLogInfo, 1);
    rtliSetLogY(LPDs_single_agent_tech_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(LPDs_single_agent_tech_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(LPDs_single_agent_tech_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &LPDs_single_agent_tech_B), 0,
                sizeof(B_LPDs_single_agent_tech_T));

  /* states (continuous) */
  {
    (void) memset((void *)&LPDs_single_agent_tech_X, 0,
                  sizeof(X_LPDs_single_agent_tech_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&LPDs_single_agent_tech_XDis, 0,
                  sizeof(XDis_LPDs_single_agent_tech_T));
  }

  /* states (dwork) */
  (void) memset((void *)&LPDs_single_agent_tech_DW, 0,
                sizeof(DW_LPDs_single_agent_tech_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(LPDs_single_agent_tech_M->rtwLogInfo, 0.0,
    rtmGetTFinal(LPDs_single_agent_tech_M),
    LPDs_single_agent_tech_M->Timing.stepSize0, (&rtmGetErrorStatus
    (LPDs_single_agent_tech_M)));

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S1>/initial_battery_energy' */
    if (rtmIsFirstInitCond(LPDs_single_agent_tech_M)) {
      LPDs_single_agent_tech_X.initial_battery_energy_CSTATE = 0.0;
    }

    LPDs_single_agent_tech_DW.initial_battery_energy_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S1>/initial_battery_energy' */

    /* InitializeConditions for Derivative: '<S17>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S18>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_o = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_e = (rtInf);

    /* InitializeConditions for Derivative: '<S19>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_o2 = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_p = (rtInf);

    /* InitializeConditions for Derivative: '<S23>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_m = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_d = (rtInf);

    /* InitializeConditions for Derivative: '<S24>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_i = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_dc = (rtInf);

    /* InitializeConditions for Derivative: '<S25>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_j = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_o = (rtInf);

    /* InitializeConditions for Memory: '<S34>/Memory2' */
    for (i = 0; i < 8; i++) {
      LPDs_single_agent_tech_DW.Memory2_PreviousInput[i] =
        LPDs_single_agent_tech_P.Memory2_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<S34>/Memory2' */

    /* InitializeConditions for Derivative: '<S47>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_p = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_ei = (rtInf);

    /* InitializeConditions for Derivative: '<S51>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_pg = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_g = (rtInf);

    /* InitializeConditions for Derivative: '<S50>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_a = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_k = (rtInf);

    /* InitializeConditions for Derivative: '<S54>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_f = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_n = (rtInf);

    /* InitializeConditions for Derivative: '<S55>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_o1 = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_a = (rtInf);

    /* InitializeConditions for Derivative: '<S59>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_g = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_de = (rtInf);

    /* InitializeConditions for Derivative: '<S58>/Derivative' */
    LPDs_single_agent_tech_DW.TimeStampA_ml = (rtInf);
    LPDs_single_agent_tech_DW.TimeStampB_ex = (rtInf);

    /* SystemInitialize for Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
    initialize_msg_local_queues_for();
    LPDs_single_agent_tech_DW.charge_max = 1.0;
    LPDs_single_agent_tech_DW.charge_high = 0.95;
    LPDs_single_agent_tech_DW.charge_medium = 0.8;
    LPDs_single_agent_tech_DW.charge_low = 0.5;
    LPDs_single_agent_tech_DW.charge_min = 0.2;
    LPDs_single_agent_tech_DW.discharge_min = 0.0;
    LPDs_single_agent_tech_DW.discharge_low = 0.1;
    LPDs_single_agent_tech_DW.discharge_medium = 0.8;
    LPDs_single_agent_tech_DW.discharge_high = 0.95;
    LPDs_single_agent_tech_DW.discharge_max = 1.0;
    LPDs_single_agent_tech_B.battery_charge_factor = 0.0;
    LPDs_single_agent_tech_B.battery_discharge_factor = 0.0;
    LPDs_single_agent_tech_DW.HIGH_msgReservedData = 0.0;
    LPDs_single_agent_tech_DW.LOW_msgReservedData = 0.0;
    LPDs_single_agent_tech_DW.MAX_msgReservedData = 0.0;
    LPDs_single_agent_tech_DW.MIN_msgReservedData = 0.0;
    LPDs_single_agent_tech_DW.NORMAL_msgReservedData = 0.0;
    LPDs_single_agent_tech_B.battery_charging_power = 0.0;
    LPDs_single_agent_tech_B.battery_discharging_power = 0.0;
    LPDs_single_agent_tech_DW.batteryState_msgReservedData = 0.0;

    /* Chart: '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
    LPDs_single_agent_tech_DW.is_c6_LPDs_single_agent_tech =
      LPDs_single_agent_tech_IN_state;

    /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem' */
    LPDs_single_agen_Subsystem_Init(&LPDs_single_agent_tech_B.Subsystem,
      &LPDs_single_agent_tech_P.Subsystem);

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem1' */
    LPDs_single_agen_Subsystem_Init(&LPDs_single_agent_tech_B.Subsystem1,
      &LPDs_single_agent_tech_P.Subsystem1);

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem1' */

    /* SystemInitialize for Chart: '<S5>/Chart' */
    LPDs_single_agent_tech_DW.load_ = 0.0;
    LPDs_single_agent_tech_DW.power_remain = 0.0;
    LPDs_single_agent_tech_DW.load_min = 0.0;
    LPDs_single_agent_tech_DW.ks = 0.0;
    LPDs_single_agent_tech_DW.ke = 0.0;
    LPDs_single_agent_tech_DW.kt = 0.0;
    LPDs_single_agent_tech_DW.dwind = 0.0;
    LPDs_single_agent_tech_DW.dPV = 0.0;
    LPDs_single_agent_tech_DW.load = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_demand = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_supply = 0.0;
    LPDs_single_agent_tech_DW.mg_power_usage_nanogrid = 0.0;
    LPDs_single_agent_tech_DW.PV_remain = 0.0;
    LPDs_single_agent_tech_DW.wind_remain = 0.0;
    LPDs_single_agent_tech_DW.mg_power_usage_load = 0.0;
    LPDs_single_agent_tech_DW.dPw = 0.0;
    LPDs_single_agent_tech_DW.dP = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage = 0.0;
    LPDs_single_agent_tech_DW.PV_load_usage = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_demand_PV_usage_perce = 0.0;
    LPDs_single_agent_tech_DW.PV_load_usage_percentage = 0.0;
    LPDs_single_agent_tech_DW.PV_remain_ = 0.0;
    LPDs_single_agent_tech_DW.wind_nanogrid_usage_percentage = 0.0;
    LPDs_single_agent_tech_DW.wind_load_usage_percentage = 0.0;
    LPDs_single_agent_tech_DW.wind_remain_ = 0.0;
    LPDs_single_agent_tech_DW.wind_load_usage = 0.0;
    LPDs_single_agent_tech_DW.battery_charging_power_out = 0.0;
    LPDs_single_agent_tech_DW.battery_charging_power_out_perc = 0.0;
    LPDs_single_agent_tech_DW.battery_discharging_power_out = 0.0;
    LPDs_single_agent_tech_DW.battery_discharging_power_out_p = 0.0;
    LPDs_single_agent_tech_DW.battery_usage = 0.0;
    LPDs_single_agent_tech_DW.static_load_usage = 0.0;
    LPDs_single_agent_tech_DW.static_load_usage_percentage = 0.0;
    LPDs_single_agent_tech_DW.TCL_load_usage_percentage = 0.0;
    LPDs_single_agent_tech_DW.TCL_load_usage = 0.0;
    LPDs_single_agent_tech_DW.EV_load_usage_percentage = 0.0;
    LPDs_single_agent_tech_DW.EV_load_usage = 0.0;
    LPDs_single_agent_tech_DW.mg_power_usage = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_demand_mg_usage_perce = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage = 0.0;
    LPDs_single_agent_tech_DW.nano_grid_demand_wind_usage_per = 0.0;
    LPDs_single_agent_tech_DW.nanogrid_remain = 0.0;
    LPDs_single_agent_tech_DW.nanogrid_usage = 0.0;
    LPDs_single_agent_tech_DW.PV_nanogrid_usage_percentage = 0.0;
    LPDs_single_agent_tech_DW.PV_nanogrid_usage = 0.0;
    LPDs_single_agent_tech_DW.wind_nanogrid_usage = 0.0;
    LPDs_single_agent_tech_DW.wind_remain_percentage = 0.0;
    LPDs_single_agent_tech_DW.PV_remain_percentage = 0.0;
    LPDs_single_agent_tech_DW.power_balance_error = 0.0;
    LPDs_single_agent_tech_DW.total_power_produced = 0.0;
    LPDs_single_agent_tech_DW.total_power_consumed = 0.0;

    /* Chart: '<S5>/Chart' */
    LPDs_single_agent_tech_DW.is_c3_LPDs_single_agent_tech =
      LPDs_single__IN_Initialization1;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(LPDs_single_agent_tech_M)) {
      rtmSetFirstInitCond(LPDs_single_agent_tech_M, 0);
    }
  }
}

/* Model terminate function */
void LPDs_single_agent_tech_terminate(void)
{
  /* (no terminate code required) */
}
