/*
 * LPDs_single_agent_tech.h
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

#ifndef RTW_HEADER_LPDs_single_agent_tech_h_
#define RTW_HEADER_LPDs_single_agent_tech_h_
#ifndef LPDs_single_agent_tech_COMMON_INCLUDES_
#define LPDs_single_agent_tech_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                             /* LPDs_single_agent_tech_COMMON_INCLUDES_ */

#include <stddef.h>
#include "LPDs_single_agent_tech_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals for system '<S1>/Subsystem' */
typedef struct {
  real_T In1;                          /* '<S11>/In1' */
} B_Subsystem_LPDs_single_agent_T;

/* Block states (default storage) for system '<S1>/Subsystem' */
typedef struct {
  boolean_T Subsystem_MODE;            /* '<S1>/Subsystem' */
} DW_Subsystem_LPDs_single_agen_T;

/* Block states (default storage) for system '<S30>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S30>/Enabled Subsystem' */
} DW_EnabledSubsystem_LPDs_sing_T;

/* Block states (default storage) for system '<S36>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S36>/Enabled Subsystem' */
} DW_EnabledSubsystem_LPDs_si_b_T;

/* Block signals (default storage) */
typedef struct {
  real_T initial_battery_capacity;     /* '<S1>/Divide1' */
  real_T kWh;                          /* '<S1>/1 s ----> 1h' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T LookUpTable;                  /* '<S51>/Look-Up Table' */
  real_T PV1_power_state;              /* '<S7>/Gain2' */
  real_T LookUpTable_i;                /* '<S59>/Look-Up Table' */
  real_T micro_grid_power;             /* '<S4>/Gain' */
  real_T LookUpTable_o;                /* '<S47>/Look-Up Table' */
  real_T Static_Load_demand;           /* '<S3>/Gain' */
  real_T TCL_Load_demand;              /* '<S3>/Gain1' */
  real_T EV_Load_demand;               /* '<S3>/Gain2' */
  real_T Sum;                          /* '<S5>/Sum' */
  real_T LookUpTable_b;                /* '<S17>/Look-Up Table' */
  real_T Derivative;                   /* '<S17>/Derivative' */
  real_T LookUpTable_l;                /* '<S18>/Look-Up Table' */
  real_T Derivative_f;                 /* '<S18>/Derivative' */
  real_T LookUpTable_om;               /* '<S19>/Look-Up Table' */
  real_T Derivative_j;                 /* '<S19>/Derivative' */
  real_T LookUpTable_m;                /* '<S23>/Look-Up Table' */
  real_T Derivative_i;                 /* '<S23>/Derivative' */
  real_T LookUpTable_f;                /* '<S24>/Look-Up Table' */
  real_T Derivative_p;                 /* '<S24>/Derivative' */
  real_T LookUpTable_p;                /* '<S25>/Look-Up Table' */
  real_T Derivative_a;                 /* '<S25>/Derivative' */
  real_T EV_loadskW;                   /* '<S5>/Gain66' */
  real_T EV_load_usagekW;              /* '<S5>/Gain67' */
  real_T nano_grid_supplykW;           /* '<S5>/Gain68' */
  real_T nano_grid_usagekW;            /* '<S5>/Gain69' */
  real_T nano_grid_remainkW;           /* '<S5>/Gain70' */
  real_T mg_powerkW;                   /* '<S5>/Gain75' */
  real_T mg_power_usagekW;             /* '<S5>/Gain76' */
  real_T mg_power_usage_loadkW;        /* '<S5>/Gain77' */
  real_T mg_power_usage_nanogridkW;    /* '<S5>/Gain78' */
  real_T total_power_producedkW;       /* '<S5>/Gain79' */
  real_T total_power_consumedkW;       /* '<S5>/Gain80' */
  real_T power_balance_errorkW;        /* '<S5>/Gain81' */
  real_T nano_grid_demandkW;           /* '<S5>/Gain71' */
  real_T nano_grid_demand_PV_usageskW; /* '<S5>/Gain72' */
  real_T nano_grid_demand_wind_usageskW;/* '<S5>/Gain73' */
  real_T nano_grid_demand_mg_usagekW;  /* '<S5>/Gain74' */
  real_T PV1_power_kW;                 /* '<S5>/Gain82' */
  real_T wind_power_kW;                /* '<S5>/Gain83' */
  real_T battery_discharging_power__kW;/* '<S5>/Gain84' */
  real_T nano_grid_supply_kW;          /* '<S5>/Gain85' */
  real_T mg_power_usage_kW;            /* '<S5>/Gain86' */
  real_T static_load_usage_kW;         /* '<S5>/Gain87' */
  real_T TCL_load_usage_kW;            /* '<S5>/Gain88' */
  real_T EV_load_usage_kW;             /* '<S5>/Gain89' */
  real_T battery_charging_power_out_kW;/* '<S5>/Gain90' */
  real_T nano_grid_demand_kW;          /* '<S5>/Gain91' */
  real_T PV1_powerskW;                 /* '<S5>/Gain12' */
  real_T PV_load_usagekW;              /* '<S5>/Gain13' */
  real_T PV_nanogrid_usagekW;          /* '<S5>/Gain14' */
  real_T PV_remain_kW;                 /* '<S5>/Gain53' */
  real_T wind_powerskW;                /* '<S5>/Gain54' */
  real_T wind_load_usagekW;            /* '<S5>/Gain55' */
  real_T wind_nanogrid_usagekW;        /* '<S5>/Gain56' */
  real_T wind_remain_kW;               /* '<S5>/Gain57' */
  real_T battery_charging_powerskW;    /* '<S5>/Gain58' */
  real_T battery_charging_power_outkW; /* '<S5>/Gain59' */
  real_T battery_discharging_powerskW; /* '<S5>/Gain60' */
  real_T battery_discharging_power_outkW;/* '<S5>/Gain61' */
  real_T static_loadskW;               /* '<S5>/Gain62' */
  real_T static_load_usagekW;          /* '<S5>/Gain63' */
  real_T TCL_loadskW;                  /* '<S5>/Gain64' */
  real_T TCL_load_usagekW;             /* '<S5>/Gain65' */
  real_T Gain21;                       /* '<S5>/Gain21' */
  real_T Gain22;                       /* '<S5>/Gain22' */
  real_T Gain23;                       /* '<S5>/Gain23' */
  real_T Gain24;                       /* '<S5>/Gain24' */
  real_T Gain3;                        /* '<S5>/Gain3' */
  real_T Gain5;                        /* '<S5>/Gain5' */
  real_T Gain16;                       /* '<S5>/Gain16' */
  real_T Gain_f;                       /* '<S5>/Gain' */
  real_T Memory2[8];                   /* '<S34>/Memory2' */
  real_T Derivative_k;                 /* '<S47>/Derivative' */
  real_T Derivative_jh;                /* '<S51>/Derivative' */
  real_T LookUpTable_mb;               /* '<S50>/Look-Up Table' */
  real_T Derivative_jn;                /* '<S50>/Derivative' */
  real_T LookUpTable_k;                /* '<S54>/Look-Up Table' */
  real_T Derivative_d;                 /* '<S54>/Derivative' */
  real_T LookUpTable_c;                /* '<S55>/Look-Up Table' */
  real_T Derivative_g;                 /* '<S55>/Derivative' */
  real_T Derivative_kn;                /* '<S59>/Derivative' */
  real_T LookUpTable_g;                /* '<S58>/Look-Up Table' */
  real_T Derivative_gh;                /* '<S58>/Derivative' */
  real_T u0ofmaxlimit;                 /* '<S37>/30% of (max limit)' */
  real_T Abs;                          /* '<S36>/Abs' */
  real_T maxlimit;                     /* '<S31>/(max limit)' */
  real_T Abs_e;                        /* '<S30>/Abs' */
  real_T y[58];                        /* '<S5>/MATLAB Function' */
  real_T battery_charge_factor;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T battery_discharge_factor;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T battery_charging_power;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T battery_discharging_power;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T Compare;                   /* '<S13>/Compare' */
  boolean_T discharging;               /* '<S1>/discharge' */
  boolean_T HiddenBuf_InsertedFor_Subsystem;
  boolean_T HiddenBuf_InsertedFor_Subsyst_i;
  boolean_T Compare_n;                 /* '<S38>/Compare' */
  boolean_T HiddenBuf_InsertedFor_nanogrida;
                         /* '<S5>/nano grid controller  forecast power demad' */
  boolean_T Compare_n1;                /* '<S39>/Compare' */
  boolean_T HiddenBuf_InsertedFor_nanogri_o;
                         /* '<S5>/nano grid controller forecast power supply' */
  boolean_T Compare_g;                 /* '<S32>/Compare' */
  boolean_T Compare_j;                 /* '<S33>/Compare' */
  boolean_T PVutilizationis96100;      /* '<S37>/Cast To Boolean' */
  boolean_T windutilizationis96100;    /* '<S37>/Cast To Boolean1' */
  boolean_T EV_load_requirements;
                        /* '<S36>/(96%) EV_load <= EV_load_action <= EV_load' */
  boolean_T TCL_load_requirements;
                    /* '<S36>/(96%) TCL_load <= TCL_load_action <=  TCL_load' */
  boolean_T static_load_requirements;
           /* '<S36>/(96%) static_load <= static_load_action <=  static_load' */
  boolean_T PVutilizationis96100_j;    /* '<S31>/Cast To Boolean' */
  boolean_T windutilizationis96100_g;  /* '<S31>/Cast To Boolean1' */
  boolean_T micro_grid_controllers_actionmi;/* '<S31>/micro Grid power Over Limit' */
  boolean_T EV_load_requirements_b;
                        /* '<S30>/(96%) EV_load <= EV_load_action <= EV_load' */
  boolean_T TCL_load_requirements_h;
                    /* '<S30>/(96%) TCL_load <= TCL_load_action <=  TCL_load' */
  boolean_T static_load_requirements_c;
           /* '<S30>/(96%) static_load <= static_load_action <=  static_load' */
  boolean_T micro_grid_controllers_action_g;/* '<S30>/Micro Grid power Over Limit' */
  B_Subsystem_LPDs_single_agent_T Subsystem1;/* '<S1>/Subsystem1' */
  B_Subsystem_LPDs_single_agent_T Subsystem;/* '<S1>/Subsystem' */
} B_LPDs_single_agent_tech_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S17>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S17>/Derivative' */
  real_T TimeStampB;                   /* '<S17>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S17>/Derivative' */
  real_T TimeStampA_o;                 /* '<S18>/Derivative' */
  real_T LastUAtTimeA_h;               /* '<S18>/Derivative' */
  real_T TimeStampB_e;                 /* '<S18>/Derivative' */
  real_T LastUAtTimeB_k;               /* '<S18>/Derivative' */
  real_T TimeStampA_o2;                /* '<S19>/Derivative' */
  real_T LastUAtTimeA_e;               /* '<S19>/Derivative' */
  real_T TimeStampB_p;                 /* '<S19>/Derivative' */
  real_T LastUAtTimeB_b;               /* '<S19>/Derivative' */
  real_T TimeStampA_m;                 /* '<S23>/Derivative' */
  real_T LastUAtTimeA_i;               /* '<S23>/Derivative' */
  real_T TimeStampB_d;                 /* '<S23>/Derivative' */
  real_T LastUAtTimeB_c;               /* '<S23>/Derivative' */
  real_T TimeStampA_i;                 /* '<S24>/Derivative' */
  real_T LastUAtTimeA_g;               /* '<S24>/Derivative' */
  real_T TimeStampB_dc;                /* '<S24>/Derivative' */
  real_T LastUAtTimeB_j;               /* '<S24>/Derivative' */
  real_T TimeStampA_j;                 /* '<S25>/Derivative' */
  real_T LastUAtTimeA_d;               /* '<S25>/Derivative' */
  real_T TimeStampB_o;                 /* '<S25>/Derivative' */
  real_T LastUAtTimeB_kb;              /* '<S25>/Derivative' */
  real_T Memory2_PreviousInput[8];     /* '<S34>/Memory2' */
  real_T TimeStampA_p;                 /* '<S47>/Derivative' */
  real_T LastUAtTimeA_p;               /* '<S47>/Derivative' */
  real_T TimeStampB_ei;                /* '<S47>/Derivative' */
  real_T LastUAtTimeB_o;               /* '<S47>/Derivative' */
  real_T TimeStampA_pg;                /* '<S51>/Derivative' */
  real_T LastUAtTimeA_ie;              /* '<S51>/Derivative' */
  real_T TimeStampB_g;                 /* '<S51>/Derivative' */
  real_T LastUAtTimeB_cy;              /* '<S51>/Derivative' */
  real_T TimeStampA_a;                 /* '<S50>/Derivative' */
  real_T LastUAtTimeA_iu;              /* '<S50>/Derivative' */
  real_T TimeStampB_k;                 /* '<S50>/Derivative' */
  real_T LastUAtTimeB_i;               /* '<S50>/Derivative' */
  real_T TimeStampA_f;                 /* '<S54>/Derivative' */
  real_T LastUAtTimeA_k;               /* '<S54>/Derivative' */
  real_T TimeStampB_n;                 /* '<S54>/Derivative' */
  real_T LastUAtTimeB_n;               /* '<S54>/Derivative' */
  real_T TimeStampA_o1;                /* '<S55>/Derivative' */
  real_T LastUAtTimeA_b;               /* '<S55>/Derivative' */
  real_T TimeStampB_a;                 /* '<S55>/Derivative' */
  real_T LastUAtTimeB_d;               /* '<S55>/Derivative' */
  real_T TimeStampA_g;                 /* '<S59>/Derivative' */
  real_T LastUAtTimeA_gr;              /* '<S59>/Derivative' */
  real_T TimeStampB_de;                /* '<S59>/Derivative' */
  real_T LastUAtTimeB_du;              /* '<S59>/Derivative' */
  real_T TimeStampA_ml;                /* '<S58>/Derivative' */
  real_T LastUAtTimeA_ei;              /* '<S58>/Derivative' */
  real_T TimeStampB_ex;                /* '<S58>/Derivative' */
  real_T LastUAtTimeB_bh;              /* '<S58>/Derivative' */
  real_T load_;                        /* '<S5>/Chart' */
  real_T power_remain;                 /* '<S5>/Chart' */
  real_T load_min;                     /* '<S5>/Chart' */
  real_T ks;                           /* '<S5>/Chart' */
  real_T ke;                           /* '<S5>/Chart' */
  real_T kt;                           /* '<S5>/Chart' */
  real_T dwind;                        /* '<S5>/Chart' */
  real_T dPV;                          /* '<S5>/Chart' */
  real_T load;                         /* '<S5>/Chart' */
  real_T nano_grid_demand;             /* '<S5>/Chart' */
  real_T nano_grid_supply;             /* '<S5>/Chart' */
  real_T mg_power_usage_nanogrid;      /* '<S5>/Chart' */
  real_T PV_remain;                    /* '<S5>/Chart' */
  real_T wind_remain;                  /* '<S5>/Chart' */
  real_T mg_power_usage_load;          /* '<S5>/Chart' */
  real_T dPw;                          /* '<S5>/Chart' */
  real_T dP;                           /* '<S5>/Chart' */
  real_T nano_grid_demand_PV_usage;    /* '<S5>/Chart' */
  real_T PV_load_usage;                /* '<S5>/Chart' */
  real_T nano_grid_demand_PV_usage_perce;/* '<S5>/Chart' */
  real_T PV_load_usage_percentage;     /* '<S5>/Chart' */
  real_T PV_remain_;                   /* '<S5>/Chart' */
  real_T wind_nanogrid_usage_percentage;/* '<S5>/Chart' */
  real_T wind_load_usage_percentage;   /* '<S5>/Chart' */
  real_T wind_remain_;                 /* '<S5>/Chart' */
  real_T wind_load_usage;              /* '<S5>/Chart' */
  real_T battery_charging_power_out;   /* '<S5>/Chart' */
  real_T battery_charging_power_out_perc;/* '<S5>/Chart' */
  real_T battery_discharging_power_out;/* '<S5>/Chart' */
  real_T battery_discharging_power_out_p;/* '<S5>/Chart' */
  real_T battery_usage;                /* '<S5>/Chart' */
  real_T static_load_usage;            /* '<S5>/Chart' */
  real_T static_load_usage_percentage; /* '<S5>/Chart' */
  real_T TCL_load_usage_percentage;    /* '<S5>/Chart' */
  real_T TCL_load_usage;               /* '<S5>/Chart' */
  real_T EV_load_usage_percentage;     /* '<S5>/Chart' */
  real_T EV_load_usage;                /* '<S5>/Chart' */
  real_T mg_power_usage;               /* '<S5>/Chart' */
  real_T nano_grid_demand_mg_usage;    /* '<S5>/Chart' */
  real_T nano_grid_demand_mg_usage_perce;/* '<S5>/Chart' */
  real_T nano_grid_demand_wind_usage;  /* '<S5>/Chart' */
  real_T nano_grid_demand_wind_usage_per;/* '<S5>/Chart' */
  real_T nanogrid_remain;              /* '<S5>/Chart' */
  real_T nanogrid_usage;               /* '<S5>/Chart' */
  real_T PV_nanogrid_usage_percentage; /* '<S5>/Chart' */
  real_T PV_nanogrid_usage;            /* '<S5>/Chart' */
  real_T wind_nanogrid_usage;          /* '<S5>/Chart' */
  real_T wind_remain_percentage;       /* '<S5>/Chart' */
  real_T PV_remain_percentage;         /* '<S5>/Chart' */
  real_T power_balance_error;          /* '<S5>/Chart' */
  real_T total_power_produced;         /* '<S5>/Chart' */
  real_T total_power_consumed;         /* '<S5>/Chart' */
  real_T charge_max;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T charge_high;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T charge_medium;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T charge_low;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T charge_min;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T discharge_min;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T discharge_low;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T discharge_medium;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T discharge_high;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T discharge_max;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T HIGH;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T LOW;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T MAX;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T MIN;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T NORMAL;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T batteryState;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T HIGH_msgData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T LOW_msgData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T MAX_msgData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T MIN_msgData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T NORMAL_msgData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T batteryState_msgData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T HIGH_msgReservedData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T LOW_msgReservedData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T MAX_msgReservedData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T MIN_msgReservedData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T NORMAL_msgReservedData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  real_T batteryState_msgReservedData;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  Msg_real_T Msg[61];
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  Queue_real_T Queue[6];
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* HIGH_msgInterface;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* HIGH_msgHandle;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* HIGH_msgDataPtr;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* LOW_msgInterface;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* LOW_msgHandle;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* LOW_msgDataPtr;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* MAX_msgInterface;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* MAX_msgHandle;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* MAX_msgDataPtr;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* MIN_msgInterface;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* MIN_msgHandle;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* MIN_msgDataPtr;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* NORMAL_msgInterface;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* NORMAL_msgHandle;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* NORMAL_msgDataPtr;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* batteryState_msgInterface;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* batteryState_msgHandle;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  void* batteryState_msgDataPtr;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  int32_T HIGH_qId;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  int32_T LOW_qId;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  int32_T MAX_qId;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  int32_T MIN_qId;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  int32_T NORMAL_qId;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  int32_T batteryState_qId;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  int_T initial_battery_energy_IWORK;  /* '<S1>/initial_battery_energy' */
  uint8_T is_c3_LPDs_single_agent_tech;/* '<S5>/Chart' */
  uint8_T is_c6_LPDs_single_agent_tech;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T HIGH_isValid;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T LOW_isValid;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T MAX_isValid;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T MIN_isValid;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T NORMAL_isValid;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T batteryState_isValid;
           /* '<S1>/BESSs, battery SOC ------ > charging, discharging. power' */
  boolean_T nanogridassource_MODE;     /* '<S5>/nano grid as source' */
  boolean_T nanogridasload_MODE;       /* '<S5>/nano grid as load' */
  boolean_T Microgridassource_MODE;    /* '<S5>/Micro grid as source' */
  boolean_T Microgridasload_MODE;      /* '<S5>/Micro grid as load' */
  DW_EnabledSubsystem_LPDs_si_b_T EnabledSubsystem_p;/* '<S37>/Enabled Subsystem' */
  DW_EnabledSubsystem_LPDs_si_b_T EnabledSubsystem_g;/* '<S36>/Enabled Subsystem' */
  DW_EnabledSubsystem_LPDs_sing_T EnabledSubsystem_i;/* '<S31>/Enabled Subsystem' */
  DW_EnabledSubsystem_LPDs_sing_T EnabledSubsystem;/* '<S30>/Enabled Subsystem' */
  DW_Subsystem_LPDs_single_agen_T Subsystem1;/* '<S1>/Subsystem1' */
  DW_Subsystem_LPDs_single_agen_T Subsystem;/* '<S1>/Subsystem' */
} DW_LPDs_single_agent_tech_T;

/* Continuous states (default storage) */
typedef struct {
  real_T initial_battery_energy_CSTATE;/* '<S1>/initial_battery_energy' */
} X_LPDs_single_agent_tech_T;

/* State derivatives (default storage) */
typedef struct {
  real_T initial_battery_energy_CSTATE;/* '<S1>/initial_battery_energy' */
} XDot_LPDs_single_agent_tech_T;

/* State disabled  */
typedef struct {
  boolean_T initial_battery_energy_CSTATE;/* '<S1>/initial_battery_energy' */
} XDis_LPDs_single_agent_tech_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S1>/Subsystem' */
struct P_Subsystem_LPDs_single_agent_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S11>/Out1'
                                        */
};

/* Parameters for system: '<S30>/Enabled Subsystem' */
struct P_EnabledSubsystem_LPDs_singl_T_ {
  real_T Output1_Y0;                   /* Computed Parameter: Output1_Y0
                                        * Referenced by: '<S42>/Output1'
                                        */
};

/* Parameters for system: '<S36>/Enabled Subsystem' */
struct P_EnabledSubsystem_LPDs_sin_b_T_ {
  real_T Output1_Y0;                   /* Computed Parameter: Output1_Y0
                                        * Referenced by: '<S44>/Output1'
                                        */
};

/* Parameters (default storage) */
struct P_LPDs_single_agent_tech_T_ {
  real_T EV_load_priority_factor;      /* Variable: EV_load_priority_factor
                                        * Referenced by: '<S5>/Constant19'
                                        */
  real_T EV_load_rating;               /* Variable: EV_load_rating
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T PV_power_rating;              /* Variable: PV_power_rating
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T TCL_load_priority_factor;     /* Variable: TCL_load_priority_factor
                                        * Referenced by: '<S5>/Constant18'
                                        */
  real_T TCL_load_rating;              /* Variable: TCL_load_rating
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Wind_power_rating;            /* Variable: Wind_power_rating
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T battery_SOC_state_lower_limit;
                                      /* Variable: battery_SOC_state_lower_limit
                                       * Referenced by: '<S1>/Constant3'
                                       */
  real_T battery_SOC_state_upper_limit;
                                      /* Variable: battery_SOC_state_upper_limit
                                       * Referenced by: '<S1>/Constant4'
                                       */
  real_T battery_capacity_state_upper_limit;
                                 /* Variable: battery_capacity_state_upper_limit
                                  * Referenced by: '<S1>/Constant2'
                                  */
  real_T battery_charge_power_state_upper_limit;
                             /* Variable: battery_charge_power_state_upper_limit
                              * Referenced by: '<S1>/Constant6'
                              */
  real_T battery_discharge_power_state_upper_limit;
                          /* Variable: battery_discharge_power_state_upper_limit
                           * Referenced by: '<S1>/Constant10'
                           */
  real_T nano_grid_controller_power_rating;
                                  /* Variable: nano_grid_controller_power_rating
                                   * Referenced by: '<S6>/Gain'
                                   */
  real_T static_load_priority_factor;  /* Variable: static_load_priority_factor
                                        * Referenced by: '<S5>/Constant20'
                                        */
  real_T static_load_rating;           /* Variable: static_load_rating
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T u600_Gain;                    /* Expression: 0.96
                                        * Referenced by: '<S30>/96.00%'
                                        */
  real_T u6_Gain;                      /* Expression: 0.96
                                        * Referenced by: '<S30>/96%'
                                        */
  real_T u6_Gain_j;                    /* Expression: 0.96
                                        * Referenced by: '<S30>/96 %'
                                        */
  real_T nearlymaxlimit_Gain;          /* Expression: 0.96
                                        * Referenced by: '<S30>/nearly (max limit)'
                                        */
  real_T Constant_Value;               /* Expression: 0.9
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T maxlimit_Gain;                /* Expression: 0.96
                                        * Referenced by: '<S31>/(max limit)'
                                        */
  real_T nearlymaxlimit_Gain_m;        /* Expression: 0.96
                                        * Referenced by: '<S31>/nearly (max limit)'
                                        */
  real_T u600_Gain_i;                  /* Expression: 0.96
                                        * Referenced by: '<S36>/96.00%'
                                        */
  real_T u6_Gain_m;                    /* Expression: 0.96
                                        * Referenced by: '<S36>/96%'
                                        */
  real_T u6_Gain_p;                    /* Expression: 0.96
                                        * Referenced by: '<S36>/96 %'
                                        */
  real_T Constant_Value_b;             /* Expression: 0.9
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T u0ofmaxlimit_Gain;            /* Expression: 0.3
                                        * Referenced by: '<S37>/30% of (max limit)'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Constant_Value_aw;            /* Expression: 0
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant6_Value;              /* Expression: 0.95
                                        * Referenced by: '<S5>/Constant6'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T sh_Gain;                      /* Expression: 1/3600
                                        * Referenced by: '<S1>/s ----> h'
                                        */
  real_T us1h_Gain;                    /* Expression: 3600
                                        * Referenced by: '<S1>/1 s ----> 1h'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T LookUpTable_XData[48];        /* Expression: sps.tv
                                        * Referenced by: '<S51>/Look-Up Table'
                                        */
  real_T LookUpTable_YData[48];        /* Expression: sps.opv
                                        * Referenced by: '<S51>/Look-Up Table'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1/100
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T LookUpTable_XData_o[48];      /* Expression: sps.tv
                                        * Referenced by: '<S59>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_b[48];      /* Expression: sps.opv
                                        * Referenced by: '<S59>/Look-Up Table'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/100
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T micro_grid_controller_power_sta;/* Expression: 1e6
                                          * Referenced by: '<S4>/micro_grid_controller_power_state'
                                          */
  real_T Gain_Gain_a;                  /* Expression: 1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T LookUpTable_XData_b[48];      /* Expression: sps.tv
                                        * Referenced by: '<S47>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_e[48];      /* Expression: sps.opv
                                        * Referenced by: '<S47>/Look-Up Table'
                                        */
  real_T Static_Load_demand_Value;     /* Expression: 0.9
                                        * Referenced by: '<S3>/Static_Load_demand'
                                        */
  real_T TCL_Load_demand_Value;        /* Expression: 0.1
                                        * Referenced by: '<S3>/TCL_Load_demand'
                                        */
  real_T EV_Load_demand_Value;         /* Expression: 0.5
                                        * Referenced by: '<S3>/EV_Load_demand'
                                        */
  real_T LookUpTable_XData_ba[2];      /* Expression: sps.tv
                                        * Referenced by: '<S17>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_i[2];       /* Expression: sps.opv
                                        * Referenced by: '<S17>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 0
                                        * Referenced by: '<S17>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_d[2];       /* Expression: sps.tv
                                        * Referenced by: '<S18>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_p[2];       /* Expression: sps.opv
                                        * Referenced by: '<S18>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_f;         /* Expression: 0
                                        * Referenced by: '<S18>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_a[2];       /* Expression: sps.tv
                                        * Referenced by: '<S19>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_pj[2];      /* Expression: sps.opv
                                        * Referenced by: '<S19>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_m;         /* Expression: 0
                                        * Referenced by: '<S19>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_c[48];      /* Expression: sps.tv
                                        * Referenced by: '<S23>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_g[48];      /* Expression: sps.opv
                                        * Referenced by: '<S23>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_d;         /* Expression: 0
                                        * Referenced by: '<S23>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_k[48];      /* Expression: sps.tv
                                        * Referenced by: '<S24>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_po[48];     /* Expression: sps.opv
                                        * Referenced by: '<S24>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_h;         /* Expression: 0
                                        * Referenced by: '<S24>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_kl[48];     /* Expression: sps.tv
                                        * Referenced by: '<S25>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_m[48];      /* Expression: sps.opv
                                        * Referenced by: '<S25>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_g;         /* Expression: 0
                                        * Referenced by: '<S25>/Hit  Crossing'
                                        */
  real_T Gain66_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain66'
                                        */
  real_T Gain67_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain67'
                                        */
  real_T Gain68_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain68'
                                        */
  real_T Gain69_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain69'
                                        */
  real_T Gain70_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain70'
                                        */
  real_T Gain75_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain75'
                                        */
  real_T Gain76_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain76'
                                        */
  real_T Gain77_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain77'
                                        */
  real_T Gain78_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain78'
                                        */
  real_T Gain79_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain79'
                                        */
  real_T Gain80_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain80'
                                        */
  real_T Gain81_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain81'
                                        */
  real_T Gain71_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain71'
                                        */
  real_T Gain72_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain72'
                                        */
  real_T Gain73_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain73'
                                        */
  real_T Gain74_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain74'
                                        */
  real_T Gain82_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain82'
                                        */
  real_T Gain83_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain83'
                                        */
  real_T Gain84_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain84'
                                        */
  real_T Gain85_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain85'
                                        */
  real_T Gain86_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain86'
                                        */
  real_T Gain87_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain87'
                                        */
  real_T Gain88_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain88'
                                        */
  real_T Gain89_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain89'
                                        */
  real_T Gain90_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain90'
                                        */
  real_T Gain91_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain91'
                                        */
  real_T Gain12_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain12'
                                        */
  real_T Gain13_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain13'
                                        */
  real_T Gain14_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain14'
                                        */
  real_T Gain53_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain53'
                                        */
  real_T Gain54_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain54'
                                        */
  real_T Gain55_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain55'
                                        */
  real_T Gain56_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain56'
                                        */
  real_T Gain57_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain57'
                                        */
  real_T Gain58_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain58'
                                        */
  real_T Gain59_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain59'
                                        */
  real_T Gain60_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain60'
                                        */
  real_T Gain61_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain61'
                                        */
  real_T Gain62_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain62'
                                        */
  real_T Gain63_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain63'
                                        */
  real_T Gain64_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain64'
                                        */
  real_T Gain65_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S5>/Gain65'
                                        */
  real_T Gain21_Gain;                  /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain21'
                                        */
  real_T Gain22_Gain;                  /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain22'
                                        */
  real_T Gain23_Gain;                  /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain23'
                                        */
  real_T Gain24_Gain;                  /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain24'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain16'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 1e3
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S34>/Memory2'
                                        */
  real_T HitCrossing_Offset_c;         /* Expression: 0
                                        * Referenced by: '<S47>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_o;         /* Expression: 0
                                        * Referenced by: '<S51>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_n[48];      /* Expression: sps.tv
                                        * Referenced by: '<S50>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_bd[48];     /* Expression: sps.opv
                                        * Referenced by: '<S50>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_ha;        /* Expression: 0
                                        * Referenced by: '<S50>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_p[48];      /* Expression: sps.tv
                                        * Referenced by: '<S54>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_d[48];      /* Expression: sps.opv
                                        * Referenced by: '<S54>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_gz;        /* Expression: 0
                                        * Referenced by: '<S54>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_nj[48];     /* Expression: sps.tv
                                        * Referenced by: '<S55>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_j[48];      /* Expression: sps.opv
                                        * Referenced by: '<S55>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_b;         /* Expression: 0
                                        * Referenced by: '<S55>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_a;         /* Expression: 0
                                        * Referenced by: '<S59>/Hit  Crossing'
                                        */
  real_T LookUpTable_XData_a5[48];     /* Expression: sps.tv
                                        * Referenced by: '<S58>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_bt[48];     /* Expression: sps.opv
                                        * Referenced by: '<S58>/Look-Up Table'
                                        */
  real_T HitCrossing_Offset_av;        /* Expression: 0
                                        * Referenced by: '<S58>/Hit  Crossing'
                                        */
  boolean_T Nano_grid_load_Reward_Y0;
                                 /* Computed Parameter: Nano_grid_load_Reward_Y0
                                  * Referenced by: '<S30>/Nano_grid_load_Reward'
                                  */
  boolean_T Nano_grid_load_Punish_Y0;
                                 /* Computed Parameter: Nano_grid_load_Punish_Y0
                                  * Referenced by: '<S30>/Nano_grid_load_Punish'
                                  */
  boolean_T micro_grid_source_Reward_Y0;
                              /* Computed Parameter: micro_grid_source_Reward_Y0
                               * Referenced by: '<S31>/micro_grid_source_Reward'
                               */
  boolean_T micro_grid_source_Punish_Y0;
                              /* Computed Parameter: micro_grid_source_Punish_Y0
                               * Referenced by: '<S31>/micro_grid_source_Punish'
                               */
  boolean_T Nano_grid_load_Reward_Y0_p;
                               /* Computed Parameter: Nano_grid_load_Reward_Y0_p
                                * Referenced by: '<S36>/Nano_grid_load_Reward'
                                */
  boolean_T Nano_grid_load_Punish_Y0_p;
                               /* Computed Parameter: Nano_grid_load_Punish_Y0_p
                                * Referenced by: '<S36>/Nano_grid_load_Punish'
                                */
  boolean_T Nano_grid_source_Reward_Y0;
                               /* Computed Parameter: Nano_grid_source_Reward_Y0
                                * Referenced by: '<S37>/Nano_grid_source_Reward'
                                */
  boolean_T Nano_grid_source_Punish_Y0;
                               /* Computed Parameter: Nano_grid_source_Punish_Y0
                                * Referenced by: '<S37>/Nano_grid_source_Punish'
                                */
  P_EnabledSubsystem_LPDs_sin_b_T EnabledSubsystem_p;/* '<S37>/Enabled Subsystem' */
  P_EnabledSubsystem_LPDs_sin_b_T EnabledSubsystem_g;/* '<S36>/Enabled Subsystem' */
  P_EnabledSubsystem_LPDs_singl_T EnabledSubsystem_i;/* '<S31>/Enabled Subsystem' */
  P_EnabledSubsystem_LPDs_singl_T EnabledSubsystem;/* '<S30>/Enabled Subsystem' */
  P_Subsystem_LPDs_single_agent_T Subsystem1;/* '<S1>/Subsystem1' */
  P_Subsystem_LPDs_single_agent_T Subsystem;/* '<S1>/Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_LPDs_single_agent_tec_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_LPDs_single_agent_tech_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_LPDs_single_agent_tech_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_LPDs_single_agent_tech_T LPDs_single_agent_tech_P;

/* Block signals (default storage) */
extern B_LPDs_single_agent_tech_T LPDs_single_agent_tech_B;

/* Continuous states (default storage) */
extern X_LPDs_single_agent_tech_T LPDs_single_agent_tech_X;

/* Disabled states (default storage) */
extern XDis_LPDs_single_agent_tech_T LPDs_single_agent_tech_XDis;

/* Block states (default storage) */
extern DW_LPDs_single_agent_tech_T LPDs_single_agent_tech_DW;

/* Model entry point functions */
extern void LPDs_single_agent_tech_initialize(void);
extern void LPDs_single_agent_tech_step(void);
extern void LPDs_single_agent_tech_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LPDs_single_agent_te_T *const LPDs_single_agent_tech_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LPDs_single_agent_tech'
 * '<S1>'   : 'LPDs_single_agent_tech/BESS_10 kWh'
 * '<S2>'   : 'LPDs_single_agent_tech/Industrial_Load'
 * '<S3>'   : 'LPDs_single_agent_tech/Load_100kW'
 * '<S4>'   : 'LPDs_single_agent_tech/Micro_Grid_Controller'
 * '<S5>'   : 'LPDs_single_agent_tech/Nano_Grid_Controller1'
 * '<S6>'   : 'LPDs_single_agent_tech/Nano_Grid_Controller2'
 * '<S7>'   : 'LPDs_single_agent_tech/PV1_100kW'
 * '<S8>'   : 'LPDs_single_agent_tech/PV2 (100 kW)'
 * '<S9>'   : 'LPDs_single_agent_tech/Wind_20kW'
 * '<S10>'  : 'LPDs_single_agent_tech/BESS_10 kWh/BESSs, battery SOC ------ > charging, discharging. power'
 * '<S11>'  : 'LPDs_single_agent_tech/BESS_10 kWh/Subsystem'
 * '<S12>'  : 'LPDs_single_agent_tech/BESS_10 kWh/Subsystem1'
 * '<S13>'  : 'LPDs_single_agent_tech/BESS_10 kWh/charge'
 * '<S14>'  : 'LPDs_single_agent_tech/Industrial_Load/EV_Load'
 * '<S15>'  : 'LPDs_single_agent_tech/Industrial_Load/Static_Load'
 * '<S16>'  : 'LPDs_single_agent_tech/Industrial_Load/TCL_Load'
 * '<S17>'  : 'LPDs_single_agent_tech/Industrial_Load/EV_Load/Model'
 * '<S18>'  : 'LPDs_single_agent_tech/Industrial_Load/Static_Load/Model'
 * '<S19>'  : 'LPDs_single_agent_tech/Industrial_Load/TCL_Load/Model'
 * '<S20>'  : 'LPDs_single_agent_tech/Load_100kW/EV_Load_demand1'
 * '<S21>'  : 'LPDs_single_agent_tech/Load_100kW/Static_Load_demand1'
 * '<S22>'  : 'LPDs_single_agent_tech/Load_100kW/TCL_Load_demand1'
 * '<S23>'  : 'LPDs_single_agent_tech/Load_100kW/EV_Load_demand1/Model'
 * '<S24>'  : 'LPDs_single_agent_tech/Load_100kW/Static_Load_demand1/Model'
 * '<S25>'  : 'LPDs_single_agent_tech/Load_100kW/TCL_Load_demand1/Model'
 * '<S26>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/BESS'
 * '<S27>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Chart'
 * '<S28>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Load'
 * '<S29>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/MATLAB Function'
 * '<S30>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Micro grid as load'
 * '<S31>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Micro grid as source'
 * '<S32>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Micro grid controller  forecast power demad'
 * '<S33>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Micro grid controller forecast power supply'
 * '<S34>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Subsystem1'
 * '<S35>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Subsystem2'
 * '<S36>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/nano grid as load'
 * '<S37>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/nano grid as source'
 * '<S38>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/nano grid controller  forecast power demad'
 * '<S39>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/nano grid controller forecast power supply'
 * '<S40>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/BESS/charging'
 * '<S41>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/BESS/discharging'
 * '<S42>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Micro grid as load/Enabled Subsystem'
 * '<S43>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/Micro grid as source/Enabled Subsystem'
 * '<S44>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/nano grid as load/Enabled Subsystem'
 * '<S45>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller1/nano grid as source/Enabled Subsystem'
 * '<S46>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller2/nano_grid_controller_power_state1'
 * '<S47>'  : 'LPDs_single_agent_tech/Nano_Grid_Controller2/nano_grid_controller_power_state1/Model'
 * '<S48>'  : 'LPDs_single_agent_tech/PV1_100kW/PV1_power_forecast1'
 * '<S49>'  : 'LPDs_single_agent_tech/PV1_100kW/PV1_power_state1'
 * '<S50>'  : 'LPDs_single_agent_tech/PV1_100kW/PV1_power_forecast1/Model'
 * '<S51>'  : 'LPDs_single_agent_tech/PV1_100kW/PV1_power_state1/Model'
 * '<S52>'  : 'LPDs_single_agent_tech/PV2 (100 kW)/Real time PV Power production  based on solar irradiance'
 * '<S53>'  : 'LPDs_single_agent_tech/PV2 (100 kW)/Stair Generator1'
 * '<S54>'  : 'LPDs_single_agent_tech/PV2 (100 kW)/Real time PV Power production  based on solar irradiance/Model'
 * '<S55>'  : 'LPDs_single_agent_tech/PV2 (100 kW)/Stair Generator1/Model'
 * '<S56>'  : 'LPDs_single_agent_tech/Wind_20kW/Wind_power_forecast1'
 * '<S57>'  : 'LPDs_single_agent_tech/Wind_20kW/Wind_power_state1'
 * '<S58>'  : 'LPDs_single_agent_tech/Wind_20kW/Wind_power_forecast1/Model'
 * '<S59>'  : 'LPDs_single_agent_tech/Wind_20kW/Wind_power_state1/Model'
 */
#endif                                /* RTW_HEADER_LPDs_single_agent_tech_h_ */
