/*
 * File: My_PID_Controller.h
 *
 * Code generated for Simulink model 'My_PID_Controller'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jan 16 11:48:31 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_My_PID_Controller_h_
#define RTW_HEADER_My_PID_Controller_h_
#ifndef My_PID_Controller_COMMON_INCLUDES_
#define My_PID_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* My_PID_Controller_COMMON_INCLUDES_ */

#include <string.h>
#include <stddef.h>

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

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define My_PID_Controller_M            (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T FilterCoefficient;            /* '<S39>/Filter Coefficient' */
  real_T FilterCoefficient_d;          /* '<S87>/Filter Coefficient' */
  real_T FilterCoefficient_m;          /* '<S135>/Filter Coefficient' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T IntegralGain_f;               /* '<S81>/Integral Gain' */
  real_T IntegralGain_o;               /* '<S129>/Integral Gain' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S84>/Integrator' */
  real_T Filter_CSTATE_e;              /* '<S79>/Filter' */
  real_T Integrator_CSTATE_k;          /* '<S132>/Integrator' */
  real_T Filter_CSTATE_l;              /* '<S127>/Filter' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S84>/Integrator' */
  real_T Filter_CSTATE_e;              /* '<S79>/Filter' */
  real_T Integrator_CSTATE_k;          /* '<S132>/Integrator' */
  real_T Filter_CSTATE_l;              /* '<S127>/Filter' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE_c;       /* '<S84>/Integrator' */
  boolean_T Filter_CSTATE_e;           /* '<S79>/Filter' */
  boolean_T Integrator_CSTATE_k;       /* '<S132>/Integrator' */
  boolean_T Filter_CSTATE_l;           /* '<S127>/Filter' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T e1;                           /* '<Root>/e1' */
  real_T e2;                           /* '<Root>/e2' */
  real_T e3;                           /* '<Root>/e3' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T u1;                           /* '<Root>/u1' */
  real_T u2;                           /* '<Root>/u2' */
  real_T u3;                           /* '<Root>/u3' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
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
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void My_PID_Controller_initialize(void);
extern void My_PID_Controller_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('code_generation_esp32/My_PID_Controller')    - opens subsystem code_generation_esp32/My_PID_Controller
 * hilite_system('code_generation_esp32/My_PID_Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'code_generation_esp32'
 * '<S1>'   : 'code_generation_esp32/My_PID_Controller'
 * '<S2>'   : 'code_generation_esp32/My_PID_Controller/PID Controller'
 * '<S3>'   : 'code_generation_esp32/My_PID_Controller/PID Controller1'
 * '<S4>'   : 'code_generation_esp32/My_PID_Controller/PID Controller2'
 * '<S5>'   : 'code_generation_esp32/My_PID_Controller/PID Controller/Anti-windup'
 * '<S6>'   : 'code_generation_esp32/My_PID_Controller/PID Controller/D Gain'
 * '<S7>'   : 'code_generation_esp32/My_PID_Controller/PID Controller/Filter'
 * '<S8>'   : 'code_generation_esp32/My_PID_Controller/PID Controller/Filter ICs'
 * '<S9>'   : 'code_generation_esp32/My_PID_Controller/PID Controller/I Gain'
 * '<S10>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Ideal P Gain'
 * '<S11>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Integrator'
 * '<S13>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Integrator ICs'
 * '<S14>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/N Copy'
 * '<S15>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/N Gain'
 * '<S16>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/P Copy'
 * '<S17>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Parallel P Gain'
 * '<S18>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Reset Signal'
 * '<S19>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Saturation'
 * '<S20>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Sum'
 * '<S22>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Sum Fdbk'
 * '<S23>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tracking Mode'
 * '<S24>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/postSat Signal'
 * '<S28>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/preSat Signal'
 * '<S29>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/D Gain/Internal Parameters'
 * '<S31>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Filter/Cont. Filter'
 * '<S32>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Integrator/Continuous'
 * '<S37>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/N Copy/Disabled'
 * '<S39>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/N Gain/Internal Parameters'
 * '<S40>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Sum/Sum_PID'
 * '<S46>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tsamp - Integral/Passthrough'
 * '<S50>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'code_generation_esp32/My_PID_Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S53>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Anti-windup'
 * '<S54>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/D Gain'
 * '<S55>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Filter'
 * '<S56>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Filter ICs'
 * '<S57>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/I Gain'
 * '<S58>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Ideal P Gain'
 * '<S59>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S60>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Integrator'
 * '<S61>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Integrator ICs'
 * '<S62>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/N Copy'
 * '<S63>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/N Gain'
 * '<S64>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/P Copy'
 * '<S65>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Parallel P Gain'
 * '<S66>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Reset Signal'
 * '<S67>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Saturation'
 * '<S68>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Saturation Fdbk'
 * '<S69>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Sum'
 * '<S70>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Sum Fdbk'
 * '<S71>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tracking Mode'
 * '<S72>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tracking Mode Sum'
 * '<S73>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tsamp - Integral'
 * '<S74>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tsamp - Ngain'
 * '<S75>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/postSat Signal'
 * '<S76>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/preSat Signal'
 * '<S77>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Anti-windup/Passthrough'
 * '<S78>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/D Gain/Internal Parameters'
 * '<S79>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Filter/Cont. Filter'
 * '<S80>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S81>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/I Gain/Internal Parameters'
 * '<S82>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S83>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Integrator/Continuous'
 * '<S85>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S86>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/N Copy/Disabled'
 * '<S87>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/N Gain/Internal Parameters'
 * '<S88>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/P Copy/Disabled'
 * '<S89>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S91>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Saturation/Passthrough'
 * '<S92>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S93>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Sum/Sum_PID'
 * '<S94>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S95>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S96>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S98>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'code_generation_esp32/My_PID_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S100>' : 'code_generation_esp32/My_PID_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S101>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Anti-windup'
 * '<S102>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/D Gain'
 * '<S103>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Filter'
 * '<S104>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Filter ICs'
 * '<S105>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/I Gain'
 * '<S106>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Ideal P Gain'
 * '<S107>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S108>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Integrator'
 * '<S109>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Integrator ICs'
 * '<S110>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/N Copy'
 * '<S111>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/N Gain'
 * '<S112>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/P Copy'
 * '<S113>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Parallel P Gain'
 * '<S114>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Reset Signal'
 * '<S115>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Saturation'
 * '<S116>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Saturation Fdbk'
 * '<S117>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Sum'
 * '<S118>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Sum Fdbk'
 * '<S119>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tracking Mode'
 * '<S120>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tracking Mode Sum'
 * '<S121>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tsamp - Integral'
 * '<S122>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tsamp - Ngain'
 * '<S123>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/postSat Signal'
 * '<S124>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/preSat Signal'
 * '<S125>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Anti-windup/Passthrough'
 * '<S126>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/D Gain/Internal Parameters'
 * '<S127>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Filter/Cont. Filter'
 * '<S128>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S129>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/I Gain/Internal Parameters'
 * '<S130>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S131>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S132>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Integrator/Continuous'
 * '<S133>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S134>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/N Copy/Disabled'
 * '<S135>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/N Gain/Internal Parameters'
 * '<S136>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/P Copy/Disabled'
 * '<S137>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S138>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S139>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Saturation/Passthrough'
 * '<S140>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S141>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Sum/Sum_PID'
 * '<S142>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S143>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S144>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S145>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S146>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S147>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S148>' : 'code_generation_esp32/My_PID_Controller/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_My_PID_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
