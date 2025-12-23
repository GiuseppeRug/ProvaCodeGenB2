/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Board2.c
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

#include <Board_types.h>
#include "Board2.h"
#include "rtwtypes.h"

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
#define Board2_SIZE_DECISION           ((uint8_T)24U)
#define Board2_SIZE_GLOBAL_STATE       ((uint8_T)40U)
#define Board2_SIZE_LOCAL_STATE_B1     ((uint8_T)24U)
#define Board2_SIZE_LOCAL_STATE_B2     ((uint8_T)16U)
#define Board_IN_EmergencyStateAnalysis ((uint8_T)2U)

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
static ENUM_UserAction Board2_computeUserAction(int16_T x_lever, int16_T y_lever);

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

/* Model step function */
void Board2_step(void)
{
  real_T continua_prev;

  /* Chart: '<Root>/SupervisorB2' incorporates:
   *  Inport: '<Root>/continua'
   *  Inport: '<Root>/gyroscope'
   *  Inport: '<Root>/remoteController'
   *  Inport: '<Root>/sonar'
   *  Outport: '<Root>/board2GlobalState'
   */
  continua_prev = Board2_DW.continua_start;
  Board2_DW.continua_start = Board2_U.continua;
  if (Board2_DW.is_active_c3_Board2 == 0U) {
    Board2_DW.is_active_c3_Board2 = 1U;

    /*  board2Decision.actuator = ENUM_Actuator.BOARD1;
       board2Decision.userAction = ENUM_UserAction.UA_NONE;
       inizializzaizone fasulla di decision con interi e non enum */
    Board2_DW.board2Decision.actuator = 1;
    Board2_DW.board2Decision.roverAction = 2;
    Board2_DW.board2Decision.safeAction = 3;

    /* Outport: '<Root>/currentUserAction' */
    /*  variabili locali
       Inizializzazione valori di output */
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

        /* Outport: '<Root>/currentUserAction' */
        Board2_Y.currentUserAction = Board2_computeUserAction
          (Board2_DW.board1GlobalState.localStateB2.remoteController.x_lever,
           Board2_DW.board1GlobalState.localStateB2.remoteController.y_lever);
        break;

       case B_IN_StateCoherenceVerification:
        Board2_DW.is_ComputeDecision = Board_IN_EmergencyStateAnalysis;
        break;

       default:
        /* case IN_UserActionComputation: */
        Board2_DW.is_ComputeDecision = Board2_IN_ActuatorSelection;

        /*  en: board2Decision.actuator = actuatorSelection(board2Decision.actuator); */
        break;
      }

      if (Board2_DW.exit_port_index_ComputeDecision == 2U) {
        Board2_DW.exit_port_index_ComputeDecision = 0U;
        Board2_DW.is_CommunicationPhase = Board2_IN_ExchangeDecision;
        Board2_DW.txPayload = Board2_SIZE_DECISION;
        Board2_DW.rxPayload = Board2_SIZE_DECISION;
        Board2_DW.is_ExchangeDecision = Board2_IN_D_Receive;

        /* Pronto a ricevere */
        UartReceiveIT(&Board2_DW.rx_buffer[0], Board2_DW.rxPayload);
      }
      break;

     case Board2_IN_ExchangeDecision:
      switch (Board2_DW.is_ExchangeDecision) {
       case Board2_IN_D_Receive:
        if (Board2_DW.received == 1) {
          Board2_DW.exit_port_index_D_Receive = 2U;
        }

        if (Board2_DW.exit_port_index_D_Receive == 2U) {
          Board2_DW.exit_port_index_D_Receive = 0U;
          deserializeDecision(&Board2_DW.rx_buffer[0], Board2_DW.rxPayload,
                              (BUS_Decision *)&Board2_DW.board1Decision);
          serializeDecision(&Board2_DW.tx_buffer[0], (BUS_Decision *)
                            &Board2_DW.board2Decision);
          Board2_DW.is_ExchangeDecision = Board2_IN_Transmit;

          /*  Aspettando la disponibilit� del partner per trasmettere */
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
          if (CheckRTR() != 0) {
            Board2_DW.is_Transmit = Board2_IN_Trasmit;
            UartTransmitIT(&Board2_DW.tx_buffer[0], Board2_DW.txPayload);
          }
        } else {
          /* case IN_Trasmit: */
          Board2_DW.is_Transmit = Board2_IN_NO_ACTIVE_CHILD;
          Board2_DW.exit_port_index_Transmit = 2U;
        }

        if (Board2_DW.exit_port_index_Transmit == 2U) {
          Board2_DW.exit_port_index_Transmit = 0U;
          Board2_DW.is_ExchangeDecision = Board2_IN_Execution;
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
        UartReceiveIT(&Board2_DW.rx_buffer[0], Board2_DW.rxPayload);
        break;

       case Board2_IN_GL_Receive:
        if (Board2_DW.received == 1) {
          Board2_DW.exit_port_index_GL_Receive = 2U;
        }

        if (Board2_DW.exit_port_index_GL_Receive == 2U) {
          Board2_DW.exit_port_index_GL_Receive = 0U;
          deserializeGlobalState(&Board2_DW.rx_buffer[0], Board2_DW.rxPayload,
            (BUS_GlobalState *)&Board2_DW.board1GlobalState);
          serializeGlobalState(&Board2_DW.tx_buffer[0], (BUS_GlobalState *)
                               &Board2_Y.board2GlobalState);
          Board2_DW.is_ExchangeGlobalState = Board2_IN_GL_Transmit;

          /*  Aspettando la disponibilit� del partner per trasmettere */
          Board2_DW.is_GL_Transmit = Board2_IN_ReceivingRTR;
        }
        break;

       default:
        /* case IN_GL_Transmit: */
        if (Board2_DW.is_GL_Transmit == Board2_IN_ReceivingRTR) {
          if (CheckRTR() != 0) {
            Board2_DW.is_GL_Transmit = Board2_IN_Trasmit;
            UartTransmitIT(&Board2_DW.tx_buffer[0], Board2_DW.txPayload);
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
        Board2_DW.is_ComputeDecision = B_IN_StateCoherenceVerification;
      }
      break;

     default:
      /* case IN_ExchangeLocalState: */
      if (Board2_DW.is_ExchangeLocalState == Board2_IN_LS_Receive) {
        if (Board2_DW.received == 1) {
          Board2_DW.exit_port_index_LS_Receive = 2U;
        }

        if (Board2_DW.exit_port_index_LS_Receive == 2U) {
          Board2_DW.exit_port_index_LS_Receive = 0U;
          deserializeLocalStateB1(&Board2_DW.rx_buffer[0], Board2_DW.rxPayload,
            (BUS_LocalStateB1 *)&Board2_DW.board1LocalState);
          serializeLocalStateB2(&Board2_DW.tx_buffer[0], (BUS_LocalStateB2 *)
                                &Board2_DW.board2LocalState);
          Board2_DW.is_ExchangeLocalState = Board2_IN_LS_Transmit;

          /*  Aspettando la disponibilit� del partner per trasmettere */
          Board2_DW.is_LS_Transmit = Board2_IN_ReceivingRTR;
        }
      } else {
        /* case IN_LS_Transmit: */
        if (Board2_DW.is_LS_Transmit == Board2_IN_ReceivingRTR) {
          if (CheckRTR() != 0) {
            Board2_DW.is_LS_Transmit = Board2_IN_Trasmit;
            UartTransmitIT(&Board2_DW.tx_buffer[0], Board2_DW.txPayload);
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
        Board2_DW.txPayload = Board2_SIZE_GLOBAL_STATE;
        Board2_DW.rxPayload = Board2_SIZE_GLOBAL_STATE;
        Board2_DW.is_ExchangeGlobalState = Boar_IN_ComputingOwnGlobalState;
        Board2_Y.board2GlobalState.localStateB1 = Board2_DW.board1LocalState;

        /*  forse dovrei fare una copia del backup all'inizio del mio stato,
           siccome durante la trasmissione le variabili possono cambiare */
        Board2_Y.board2GlobalState.localStateB2 = Board2_DW.board2LocalState;
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
    Board2_DW.txPayload = Board2_SIZE_LOCAL_STATE_B2;
    Board2_DW.rxPayload = Board2_SIZE_LOCAL_STATE_B1;
    Board2_DW.is_ExchangeLocalState = Board2_IN_LS_Receive;

    /* Pronto a ricevere */
    UartReceiveIT(&Board2_DW.rx_buffer[0], Board2_DW.rxPayload);
  }

  /* End of Chart: '<Root>/SupervisorB2' */
}

/* Model initialize function */
void Board2_initialize(void)
{
  /* (no initialization code required) */
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
