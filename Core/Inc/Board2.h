/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Board2.h
 *
 * Code generated for Simulink model 'Board2'.
 *
 * Model version                  : 2.62
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Dec 23 17:27:05 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Board2_h_
#define Board2_h_

#ifndef Board2_COMMON_INCLUDES_
#define Board2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* Board2_COMMON_INCLUDES_ */

#include <Board_types.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "serialize.h"
#include "deserialize.h"
#include "stubFunctions.h"

/* Block states (default storage) for system '<Root>' */
typedef struct {
  BUS_GlobalState board1GlobalState;   /* '<Root>/SupervisorB2' */
  BUS_LocalStateB1 board1LocalState;   /* '<Root>/SupervisorB2' */
  BUS_LocalStateB2 board2LocalState;   /* '<Root>/SupervisorB2' */
  BUS_Decision board2Decision;         /* '<Root>/SupervisorB2' */
  BUS_Decision board1Decision;         /* '<Root>/SupervisorB2' */
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
  uint8_T rx_buffer[64];               /* '<Root>/SupervisorB2' */
  uint8_T tx_buffer[64];               /* '<Root>/SupervisorB2' */
  uint8_T txPayload;                   /* '<Root>/SupervisorB2' */
  uint8_T rxPayload;                   /* '<Root>/SupervisorB2' */
  uint8_T received;                    /* '<Root>/SupervisorB2' */
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
  real_T continua;                     /* '<Root>/continua' */
  BUS_Sonar sonar;                     /* '<Root>/sonar' */
  real32_T gyroscope;                  /* '<Root>/gyroscope' */
  BUS_RemoteController remoteController;/* '<Root>/remoteController' */
  BUS_SetPoint setPoint;               /* '<Root>/setPoint' */
  ENUM_RoverAction roverAction;        /* '<Root>/roverAction' */
  ENUM_SafeAction safeAction;          /* '<Root>/safeAction' */
} ExtU_Board2_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  ENUM_UserAction currentUserAction;   /* '<Root>/currentUserAction' */
  BUS_GlobalState board2GlobalState;   /* '<Root>/board2GlobalState' */
} ExtY_Board2_T;

/* Real-time Model Data Structure */
struct tag_RTM_Board2_T {
  const char_T * volatile errorStatus;
};

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
