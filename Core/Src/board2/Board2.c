/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Board2.c
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

#include "Board2.h"
#include "enums.h"
#include "rtwtypes.h"
#include "ActionsModel.h"

/* Named constants for Chart: '<Root>/SupervisorB2' */
#define B_IN_StateCoherenceVerification ((uint8_T)3U)
#define Boar_IN_ComputingOwnGlobalState ((uint8_T)1U)
#define Board2_IN_ActuatorSelection    ((uint8_T)1U)
#define Board2_IN_CommunicationPhase   ((uint8_T)1U)
#define Board2_IN_ComputeDecision      ((uint8_T)1U)
#define Board2_IN_D_Receive            ((uint8_T)1U)
#define Board2_IN_ExchangeDecision     ((uint8_T)2U)
#define Board2_IN_ExchangeGlobalState  ((uint8_T)3U)
#define Board2_IN_ExchangeLocalState   ((uint8_T)4U)
#define Board2_IN_Execution            ((uint8_T)2U)
#define Board2_IN_GL_Receive           ((uint8_T)2U)
#define Board2_IN_GL_Transmit          ((uint8_T)3U)
#define Board2_IN_LS_Receive           ((uint8_T)1U)
#define Board2_IN_LS_Transmit          ((uint8_T)2U)
#define Board2_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define Board2_IN_NotCommunicating     ((uint8_T)2U)
#define Board2_IN_ReceivingRTR         ((uint8_T)1U)
#define Board2_IN_Transmit             ((uint8_T)3U)
#define Board2_IN_Trasmit              ((uint8_T)2U)
#define Board2_IN_UserActionComputation ((uint8_T)4U)
#define Board2_SIZE_DECISION           ((uint8_T)12U)
#define Board2_SIZE_GLOBAL_STATE       ((uint8_T)40U)
#define Board2_SIZE_LOCAL_STATE_B1     ((uint8_T)24U)
#define Board2_SIZE_LOCAL_STATE_B2     ((uint8_T)16U)
#define Board_IN_EmergencyStateAnalysis ((uint8_T)2U)

/* Block signals (default storage) */
B_Board2_T Board2_B;

/* Block states (default storage) */
DW_Board2_T Board2_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Board2_T Board2_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Board2_T Board2_Y;

/* Real-time model */
static RT_MODEL_Board2_T Board2_M_;
RT_MODEL_Board2_T *const Board2_M = &Board2_M_;

/* Forward declaration for local functions */
static ENUM_Actuator Board2_actuatorSelection(ENUM_Actuator lastActuator);
static ENUM_UserAction Board2_computeUserAction(int16_T x_lever, int16_T y_lever);
static ENUM_UserAction Board2_continueBraking(ENUM_UserAction currentUserAction,
  ENUM_UserAction lastUserAction);
static void Board2_printGlobalState(void);

/* Function for Chart: '<Root>/SupervisorB2' */
static ENUM_Actuator Board2_actuatorSelection(ENUM_Actuator lastActuator)
{
  ENUM_Actuator nextActuator;
  if (lastActuator == BOARD1) {
    nextActuator = BOARD2;
  } else {
    nextActuator = BOARD1;
  }

  return nextActuator;
}

/* Function for Chart: '<Root>/SupervisorB2' */
static ENUM_UserAction Board2_computeUserAction(int16_T x_lever, int16_T y_lever)
{
  ENUM_UserAction userAction;
  userAction = UA_NONE;
  if (x_lever < 0) {
    userAction = UA_ROTATE_LEFT;
  } else if (x_lever > 0) {
    userAction = UA_ROTATE_RIGHT;
  } else if (y_lever > 0) {
    userAction = UA_FORWARD;
  } else if (y_lever < 0) {
    userAction = UA_BACKWARD;
  }

  return userAction;
}

/* Function for Chart: '<Root>/SupervisorB2' */
static ENUM_UserAction Board2_continueBraking(ENUM_UserAction currentUserAction,
  ENUM_UserAction lastUserAction)
{
  ENUM_UserAction userAction;
  userAction = currentUserAction;
  if (currentUserAction == UA_NONE) {
    switch (lastUserAction) {
     case UA_BRAKING_SMOOTH:
      userAction = UA_BRAKING_SMOOTH;
      break;

     case UA_BRAKING_HARD:
      userAction = UA_BRAKING_HARD;
      break;
    }
  }

  return userAction;
}

/* Function for Chart: '<Root>/SupervisorB2' */
static void Board2_printGlobalState(void)
{
  printf("%s\n", "INIZIO");
  fflush(stdout);
}

/* Model step function */
void Board2_step(void)
{
  real_T continua_prev;

  /* Chart: '<Root>/SupervisorB2' incorporates:
   *  Inport: '<Root>/continua'
   *  Inport: '<Root>/gyroscope'
   *  Inport: '<Root>/remoteController'
   *  Inport: '<Root>/rx_buffer'
   *  Inport: '<Root>/sonar'
   *  Outport: '<Root>/currentUserAction'
   *  Outport: '<Root>/roverAction'
   *  Outport: '<Root>/safeAction'
   *  Outport: '<Root>/setPoint'
   *  Outport: '<Root>/tx_buffer'
   */
  continua_prev = Board2_DW.continua_start;
  Board2_DW.continua_start = Board2_U.continua;
  if (Board2_DW.is_active_c3_Board2 == 0) {
    Board2_DW.is_active_c3_Board2 = 1U;
    Board2_DW.board2Decision.actuator = BOARD1;

    /* Outport: '<Root>/currentUserAction' */
    Board2_Y.currentUserAction = UA_NONE;
    Board2_DW.is_RoverState = Board2_IN_NotCommunicating;
  } else if (Board2_DW.is_RoverState == Board2_IN_CommunicationPhase) {
    switch (Board2_DW.is_CommunicationPhase) {
     case Board2_IN_ComputeDecision:
      switch (Board2_DW.is_ComputeDecision) {
       case Board2_IN_ActuatorSelection:
        Board2_DW.is_ComputeDecision = Board2_IN_NO_ACTIVE_CHILD;
        Board2_DW.exit_port_index_ComputeDecision = 2U;
        break;

       case Board_IN_EmergencyStateAnalysis:
        Board2_DW.is_ComputeDecision = Board2_IN_UserActionComputation;
        Board2_DW.board2Decision.userAction = Board2_computeUserAction
          (Board2_B.board2GlobalState.localStateB2.remoteController.x_lever,
           Board2_B.board2GlobalState.localStateB2.remoteController.y_lever);
        Board2_DW.board2Decision.userAction = Board2_continueBraking
          (Board2_DW.board2Decision.userAction, Board2_Y.currentUserAction);

        /* Outport: '<Root>/currentUserAction' */
        Board2_Y.currentUserAction = Board2_DW.board2Decision.userAction;

        /* ModelReference: '<Root>/ModelAction' incorporates:
         *  Outport: '<Root>/currentUserAction'
         *  Outport: '<Root>/roverAction'
         *  Outport: '<Root>/safeAction'
         *  Outport: '<Root>/setPoint'
         *  Outport: '<Root>/statusObstacles'
         */
        ActionsModel_ComputeRoverAction(&Board2_Y.currentUserAction,
          &Board2_B.board2GlobalState.localStateB1.speed,
          &Board2_B.board2GlobalState.localStateB2.remoteController.x_lever,
          &Board2_B.board2GlobalState.localStateB2.remoteController.y_lever,
          &Board2_B.board2GlobalState.localStateB2.gyroscope,
          &Board2_B.board2GlobalState.localStateB2.sonar, &Board2_Y.setPoint,
          &Board2_Y.roverAction, &Board2_Y.safeAction, &Board2_Y.statusObstacles);
        Board2_DW.board2Decision.roverAction = Board2_Y.roverAction;
        Board2_DW.board2Decision.safeAction = Board2_Y.safeAction;
        Board2_DW.board2Decision.setPoint = Board2_Y.setPoint;
        break;

       case B_IN_StateCoherenceVerification:
        Board2_DW.is_ComputeDecision = Board_IN_EmergencyStateAnalysis;
        break;

       default:
        /* case IN_UserActionComputation: */
        Board2_DW.is_ComputeDecision = Board2_IN_ActuatorSelection;
        Board2_DW.board2Decision.actuator = Board2_actuatorSelection
          (Board2_DW.board2Decision.actuator);
        break;
      }

      if (Board2_DW.exit_port_index_ComputeDecision == 2U) {
        Board2_DW.exit_port_index_ComputeDecision = 0U;
        Board2_DW.is_CommunicationPhase = Board2_IN_ExchangeDecision;

        /*  Entry exchange decision */
        Board2_DW.txPayload = Board2_SIZE_DECISION;
        Board2_DW.rxPayload = Board2_SIZE_DECISION;
        Board2_DW.is_ExchangeDecision = Board2_IN_D_Receive;

        /* Pronto a ricevere */
        UART_ReceiveIT(&Board2_U.rx_buffer[0], Board2_DW.rxPayload);
        setRTR();
      }
      break;

     case Board2_IN_ExchangeDecision:
      switch (Board2_DW.is_ExchangeDecision) {
       case Board2_IN_D_Receive:
        if (hasReceived() == 1) {
          resetRTR();
          Board2_DW.exit_port_index_D_Receive = 2U;
        }

        if (Board2_DW.exit_port_index_D_Receive == 2U) {
          Board2_DW.exit_port_index_D_Receive = 0U;
          deserializeDecision(&Board2_U.rx_buffer[0], Board2_DW.rxPayload,
                              &Board2_DW.board1Decision);
          serializeDecision(&Board2_Y.tx_buffer[0], &Board2_DW.board2Decision);
          Board2_DW.is_ExchangeDecision = Board2_IN_Transmit;

          /*  Aspettando la disponibilità del partner per trasmettere */
          Board2_DW.is_Transmit = Board2_IN_ReceivingRTR;
        }
        break;

       case Board2_IN_Execution:
        if (continua_prev != Board2_DW.continua_start) {
          Board2_DW.is_ExchangeDecision = Board2_IN_NO_ACTIVE_CHILD;
          Board2_DW.exit_port_index_ExchangeDecisio = 2U;
        }
        break;

       default:
        /* case IN_Transmit: */
        if (Board2_DW.is_Transmit == Board2_IN_ReceivingRTR) {
          /*  RTR ricevuta */
          if (checkRTR() != 0) {
            Board2_DW.is_Transmit = Board2_IN_Trasmit;
            UART_TransmitIT(&Board2_Y.tx_buffer[0], Board2_DW.txPayload);
          }
        } else {
          /* case IN_Trasmit: */
          Board2_DW.is_Transmit = Board2_IN_NO_ACTIVE_CHILD;
          Board2_DW.exit_port_index_Transmit = 2U;
        }

        if (Board2_DW.exit_port_index_Transmit == 2U) {
          Board2_DW.exit_port_index_Transmit = 0U;
          Board2_DW.is_ExchangeDecision = Board2_IN_Execution;
          Board2_printGlobalState();
          Board2_printGlobalState();
        }
        break;
      }

      if (Board2_DW.exit_port_index_ExchangeDecisio == 2U) {
        Board2_DW.exit_port_index_ExchangeDecisio = 0U;
        Board2_DW.is_CommunicationPhase = Board2_IN_NO_ACTIVE_CHILD;
        Board2_DW.exit_port_index_CommunicationPh = 2U;
      }
      break;

     case Board2_IN_ExchangeGlobalState:
      switch (Board2_DW.is_ExchangeGlobalState) {
       case Boar_IN_ComputingOwnGlobalState:
        Board2_DW.is_ExchangeGlobalState = Board2_IN_GL_Receive;

        /* Pronto a ricevere */
        UART_ReceiveIT(&Board2_U.rx_buffer[0], Board2_DW.rxPayload);
        setRTR();
        break;

       case Board2_IN_GL_Receive:
        if (hasReceived() == 1) {
          resetRTR();
          Board2_DW.exit_port_index_GL_Receive = 2U;
        }

        if (Board2_DW.exit_port_index_GL_Receive == 2U) {
          Board2_DW.exit_port_index_GL_Receive = 0U;
          deserializeGlobalState(&Board2_U.rx_buffer[0], Board2_DW.rxPayload,
            &Board2_DW.board1GlobalState);
          serializeGlobalState(&Board2_Y.tx_buffer[0],
                               &Board2_B.board2GlobalState);
          Board2_DW.is_ExchangeGlobalState = Board2_IN_GL_Transmit;

          /*  Aspettando la disponibilità del partner per trasmettere */
          Board2_DW.is_GL_Transmit = Board2_IN_ReceivingRTR;
        }
        break;

       default:
        /* case IN_GL_Transmit: */
        if (Board2_DW.is_GL_Transmit == Board2_IN_ReceivingRTR) {
          /*  RTR ricevuta */
          if (checkRTR() != 0) {
            Board2_DW.is_GL_Transmit = Board2_IN_Trasmit;
            UART_TransmitIT(&Board2_Y.tx_buffer[0], Board2_DW.txPayload);
          }
        } else {
          /* case IN_Trasmit: */
          Board2_DW.is_GL_Transmit = Board2_IN_NO_ACTIVE_CHILD;
          Board2_DW.exit_port_index_GL_Transmit = 2U;
        }

        if (Board2_DW.exit_port_index_GL_Transmit == 2U) {
          Board2_DW.exit_port_index_GL_Transmit = 0U;
          Board2_DW.is_ExchangeGlobalState = Board2_IN_NO_ACTIVE_CHILD;
          Board2_DW.exit_port_index_ExchangeGlobalS = 2U;
        }
        break;
      }

      if (Board2_DW.exit_port_index_ExchangeGlobalS == 2U) {
        Board2_DW.exit_port_index_ExchangeGlobalS = 0U;
        Board2_DW.is_CommunicationPhase = Board2_IN_ComputeDecision;

        /*  Entry compute decision */
        Board2_DW.is_ComputeDecision = B_IN_StateCoherenceVerification;
      }
      break;

     default:
      /* case IN_ExchangeLocalState: */
      if (Board2_DW.is_ExchangeLocalState == Board2_IN_LS_Receive) {
        if (hasReceived() == 1) {
          resetRTR();
          Board2_DW.exit_port_index_LS_Receive = 2U;
        }

        if (Board2_DW.exit_port_index_LS_Receive == 2U) {
          Board2_DW.exit_port_index_LS_Receive = 0U;
          deserializeLocalStateB1(&Board2_U.rx_buffer[0], Board2_DW.rxPayload,
            &Board2_DW.board1LocalState);
          serializeLocalStateB2(&Board2_Y.tx_buffer[0],
                                &Board2_DW.board2LocalState);
          Board2_DW.is_ExchangeLocalState = Board2_IN_LS_Transmit;

          /*  Aspettando la disponibilità del partner per trasmettere */
          Board2_DW.is_LS_Transmit = Board2_IN_ReceivingRTR;
        }
      } else {
        /* case IN_LS_Transmit: */
        if (Board2_DW.is_LS_Transmit == Board2_IN_ReceivingRTR) {
          /*  RTR ricevuta */
          if (checkRTR() != 0) {
            Board2_DW.is_LS_Transmit = Board2_IN_Trasmit;
            UART_TransmitIT(&Board2_Y.tx_buffer[0], Board2_DW.txPayload);
          }
        } else {
          /* case IN_Trasmit: */
          Board2_DW.is_LS_Transmit = Board2_IN_NO_ACTIVE_CHILD;
          Board2_DW.exit_port_index_LS_Transmit = 2U;
        }

        if (Board2_DW.exit_port_index_LS_Transmit == 2U) {
          Board2_DW.exit_port_index_LS_Transmit = 0U;
          Board2_DW.is_ExchangeLocalState = Board2_IN_NO_ACTIVE_CHILD;
          Board2_DW.exit_port_index_ExchangeLocalSt = 2U;
        }
      }

      if (Board2_DW.exit_port_index_ExchangeLocalSt == 2U) {
        Board2_DW.exit_port_index_ExchangeLocalSt = 0U;
        Board2_DW.is_CommunicationPhase = Board2_IN_ExchangeGlobalState;

        /*  Entry exchange global state */
        Board2_DW.txPayload = Board2_SIZE_GLOBAL_STATE;
        Board2_DW.rxPayload = Board2_SIZE_GLOBAL_STATE;
        Board2_DW.is_ExchangeGlobalState = Boar_IN_ComputingOwnGlobalState;
        Board2_B.board2GlobalState.localStateB1 = Board2_DW.board1LocalState;

        /*  forse dovrei fare una copia del backup all'inizio del mio stato,
           siccome durante la trasmissione le variabili possono cambiare */
        Board2_B.board2GlobalState.localStateB2 = Board2_DW.board2LocalState;
      }
      break;
    }

    if (Board2_DW.exit_port_index_CommunicationPh == 2U) {
      Board2_DW.exit_port_index_CommunicationPh = 0U;
      Board2_DW.is_RoverState = Board2_IN_NotCommunicating;
    }
  } else {
    /* case IN_NotCommunicating: */
    Board2_DW.board2LocalState.sonar = Board2_U.sonar;
    Board2_DW.board2LocalState.gyroscope = Board2_U.gyroscope;
    Board2_DW.board2LocalState.remoteController = Board2_U.remoteController;
    Board2_DW.is_RoverState = Board2_IN_CommunicationPhase;
    Board2_DW.is_CommunicationPhase = Board2_IN_ExchangeLocalState;

    /*  Entry exchange local state */
    Board2_DW.txPayload = Board2_SIZE_LOCAL_STATE_B2;
    Board2_DW.rxPayload = Board2_SIZE_LOCAL_STATE_B1;
    Board2_DW.is_ExchangeLocalState = Board2_IN_LS_Receive;

    /* Pronto a ricevere */
    UART_ReceiveIT(&Board2_U.rx_buffer[0], Board2_DW.rxPayload);
    setRTR();
  }

  /* End of Chart: '<Root>/SupervisorB2' */
}

/* Model initialize function */
void Board2_initialize(void)
{
  /* Model Initialize function for ModelReference Block: '<Root>/ModelAction' */
  ActionsModel_initialize(rtmGetErrorStatusPointer(Board2_M));

  /* SystemInitialize for ModelReference: '<Root>/ModelAction' incorporates:
   *  Outport: '<Root>/currentUserAction'
   *  Outport: '<Root>/roverAction'
   *  Outport: '<Root>/safeAction'
   *  Outport: '<Root>/setPoint'
   *  Outport: '<Root>/statusObstacles'
   */
  ActionsModel_Init(&Board2_Y.setPoint, &Board2_Y.statusObstacles);
}

/* Model terminate function */
void Board2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
