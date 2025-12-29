/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Board2.h
 *
 * Code generated for Simulink model 'Board2'.
 *
 * Model version                  : 3.5
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Dec 29 17:34:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Board2_h_
#define Board2_h_
#ifndef Board2_COMMON_INCLUDES_
#define Board2_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* Board2_COMMON_INCLUDES_ */

#include "Board2_types.h"
#include "sensors.h"
#include "decision.h"
#include "enums.h"
#include "states.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* user code (top of header file) */
#include "serialize.h"
#include "deserialize.h"
#include "stubFunctions.h"

/* Block signals (default storage) */
typedef struct {
  BUS_GlobalState board2GlobalState;   /* '<Root>/SupervisorB2' */
} B_Board2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  BUS_GlobalState board1GlobalState;   /* '<Root>/SupervisorB2' */
  BUS_Decision board1Decision;         /* '<Root>/SupervisorB2' */
  BUS_Decision board2Decision;         /* '<Root>/SupervisorB2' */
  BUS_LocalStateB1 board1LocalState;   /* '<Root>/SupervisorB2' */
  BUS_LocalStateB2 board2LocalState;   /* '<Root>/SupervisorB2' */
  real_T continua_start;               /* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_CommunicationPh;/* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_ComputeDecision;/* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_ExchangeDecisio;/* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_D_Receive;  /* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_Transmit;   /* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_ExchangeGlobalS;/* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_GL_Receive; /* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_GL_Transmit;/* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_ExchangeLocalSt;/* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_LS_Receive; /* '<Root>/SupervisorB2' */
  uint32_T exit_port_index_LS_Transmit;/* '<Root>/SupervisorB2' */
  uint8_T Board1RTR;                   /* '<Root>/Data Store Memory' */
  uint8_T Board2RTR;                   /* '<Root>/Data Store Memory1' */
  uint8_T Board1Received;              /* '<Root>/Data Store Memory2' */
  uint8_T Board2Received;              /* '<Root>/Data Store Memory3' */
  uint8_T txPayload;                   /* '<Root>/SupervisorB2' */
  uint8_T rxPayload;                   /* '<Root>/SupervisorB2' */
  uint8_T is_active_c3_Board2;         /* '<Root>/SupervisorB2' */
  uint8_T is_RoverState;               /* '<Root>/SupervisorB2' */
  uint8_T is_CommunicationPhase;       /* '<Root>/SupervisorB2' */
  uint8_T is_ComputeDecision;          /* '<Root>/SupervisorB2' */
  uint8_T is_ExchangeDecision;         /* '<Root>/SupervisorB2' */
  uint8_T is_Transmit;                 /* '<Root>/SupervisorB2' */
  uint8_T is_ExchangeGlobalState;      /* '<Root>/SupervisorB2' */
  uint8_T is_GL_Transmit;              /* '<Root>/SupervisorB2' */
  uint8_T is_ExchangeLocalState;       /* '<Root>/SupervisorB2' */
  uint8_T is_LS_Transmit;              /* '<Root>/SupervisorB2' */
} DW_Board2_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  BUS_Sonar sonar;                     /* '<Root>/sonar' */
  real32_T gyroscope;                  /* '<Root>/gyroscope' */
  BUS_RemoteController remoteController;/* '<Root>/remoteController' */
  real_T continua;                     /* '<Root>/continua' */
  uint8_T rx_buffer[64];               /* '<Root>/rx_buffer' */
} ExtU_Board2_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T tx_buffer[64];               /* '<Root>/tx_buffer' */
  BUS_SetPoint setPoint;               /* '<Root>/setPoint' */
  ENUM_RoverAction roverAction;        /* '<Root>/roverAction' */
  ENUM_SafeAction safeAction;          /* '<Root>/safeAction' */
  ENUM_TrackingObstacles statusObstacles;/* '<Root>/statusObstacles' */
  ENUM_UserAction currentUserAction;   /* '<Root>/currentUserAction' */
} ExtY_Board2_T;

/* Real-time Model Data Structure */
struct tag_RTM_Board2_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Board2_T Board2_B;

/* Block states (default storage) */
extern DW_Board2_T Board2_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Board2_T Board2_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Board2_T Board2_Y;

/* Model entry point functions */
extern void Board2_initialize(void);
extern void Board2_step(void);
extern void Board2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Board2_T *const Board2_M;

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
 * '<Root>' : 'Board2'
 * '<S1>'   : 'Board2/SupervisorB2'
 */
#endif                                 /* Board2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
