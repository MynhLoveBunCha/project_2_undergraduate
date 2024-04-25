/*
 * File: My_PID_Controller.c
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

#include "My_PID_Controller.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* private model entry point functions */
extern void My_PID_Controller_derivatives(void);

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  My_PID_Controller_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  My_PID_Controller_step();
  My_PID_Controller_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  My_PID_Controller_step();
  My_PID_Controller_derivatives();

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

/* Model step function */
void My_PID_Controller_step(void)
{
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  /* Gain: '<S39>/Filter Coefficient' incorporates:
   *  Gain: '<S30>/Derivative Gain'
   *  Inport: '<Root>/e1'
   *  Integrator: '<S31>/Filter'
   *  Sum: '<S31>/SumD'
   */
  rtDW.FilterCoefficient = (93.0270543125415 * rtU.e1 - rtX.Filter_CSTATE) *
    100.0;

  /* Outport: '<Root>/u1' incorporates:
   *  Gain: '<S41>/Proportional Gain'
   *  Inport: '<Root>/e1'
   *  Integrator: '<S36>/Integrator'
   *  Sum: '<S45>/Sum'
   */
  rtY.u1 = (4509.06377833328 * rtU.e1 + rtX.Integrator_CSTATE) +
    rtDW.FilterCoefficient;

  /* Gain: '<S87>/Filter Coefficient' incorporates:
   *  Gain: '<S78>/Derivative Gain'
   *  Inport: '<Root>/e2'
   *  Integrator: '<S79>/Filter'
   *  Sum: '<S79>/SumD'
   */
  rtDW.FilterCoefficient_d = (142.912812826574 * rtU.e2 - rtX.Filter_CSTATE_e) *
    100.0;

  /* Outport: '<Root>/u2' incorporates:
   *  Gain: '<S89>/Proportional Gain'
   *  Inport: '<Root>/e2'
   *  Integrator: '<S84>/Integrator'
   *  Sum: '<S93>/Sum'
   */
  rtY.u2 = (6013.17845713596 * rtU.e2 + rtX.Integrator_CSTATE_c) +
    rtDW.FilterCoefficient_d;

  /* Gain: '<S135>/Filter Coefficient' incorporates:
   *  Gain: '<S126>/Derivative Gain'
   *  Inport: '<Root>/e3'
   *  Integrator: '<S127>/Filter'
   *  Sum: '<S127>/SumD'
   */
  rtDW.FilterCoefficient_m = (3650.65221871998 * rtU.e3 - rtX.Filter_CSTATE_l) *
    100.0;

  /* Outport: '<Root>/u3' incorporates:
   *  Gain: '<S137>/Proportional Gain'
   *  Inport: '<Root>/e3'
   *  Integrator: '<S132>/Integrator'
   *  Sum: '<S141>/Sum'
   */
  rtY.u3 = (176486.600743292 * rtU.e3 + rtX.Integrator_CSTATE_k) +
    rtDW.FilterCoefficient_m;

  /* Gain: '<S33>/Integral Gain' incorporates:
   *  Inport: '<Root>/e1'
   */
  rtDW.IntegralGain = 24313.7633743526 * rtU.e1;

  /* Gain: '<S81>/Integral Gain' incorporates:
   *  Inport: '<Root>/e2'
   */
  rtDW.IntegralGain_f = 43737.1828314861 * rtU.e2;

  /* Gain: '<S129>/Integral Gain' incorporates:
   *  Inport: '<Root>/e3'
   */
  rtDW.IntegralGain_o = 988052.474575045 * rtU.e3;
  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void My_PID_Controller_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = rtDW.IntegralGain;

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = rtDW.FilterCoefficient;

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = rtDW.IntegralGain_f;

  /* Derivatives for Integrator: '<S79>/Filter' */
  _rtXdot->Filter_CSTATE_e = rtDW.FilterCoefficient_d;

  /* Derivatives for Integrator: '<S132>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = rtDW.IntegralGain_o;

  /* Derivatives for Integrator: '<S127>/Filter' */
  _rtXdot->Filter_CSTATE_l = rtDW.FilterCoefficient_m;
}

/* Model initialize function */
void My_PID_Controller_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&rtM->solverInfo, false);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.2;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  rtX.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  rtX.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  rtX.Integrator_CSTATE_c = 0.0;

  /* InitializeConditions for Integrator: '<S79>/Filter' */
  rtX.Filter_CSTATE_e = 0.0;

  /* InitializeConditions for Integrator: '<S132>/Integrator' */
  rtX.Integrator_CSTATE_k = 0.0;

  /* InitializeConditions for Integrator: '<S127>/Filter' */
  rtX.Filter_CSTATE_l = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
