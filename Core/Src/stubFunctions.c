#include "stubFunctions.h"

// Da levareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include "deserialize.h"
#include "print.h"
#include "Board2.h"

extern UART_HandleTypeDef hlpuart1; 	// UART per comunicazione tra schede

extern UART_HandleTypeDef huart2; 		// UART per Putty

extern DW_Board2_T Board2_DW;			//Riferimento alla board

void B2checkPrintReceive();
void B2checkPrintTransmit();

/* Implementazioni stub */
//ritorna GPIO_PIN_RESET oppure GPIO_PIN_SET. Rispettivamente 0 o 1.
uint8_t CheckRTR(void) {
	return HAL_GPIO_ReadPin(RTR_IN_GPIO_Port, RTR_IN_Pin);
}

void UartTransmitIT(uint8_t *pData, size_t size) {
	printMsg("B2 Transmitted\n\r\r\n");
	HAL_UART_Transmit(&hlpuart1, pData, size, HAL_MAX_DELAY);
	//B2checkPrintTransmit();
}

void UartReceiveIT(uint8_t *pData, size_t size) {
	Board2_DW.received = 0; 								//pulisco il falg
	printMsg("B2 Wait receive\n\r");

	if (HAL_UART_Receive_IT(&hlpuart1, pData, size) != HAL_OK) {
		printMsg("B2 RECEVE_INIT_ERR\n\r");
	} else {
		HAL_GPIO_WritePin(RTR_OUT_GPIO_Port, RTR_OUT_Pin, GPIO_PIN_SET); // Notifico la disponibilità a ricevere
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == LPUART1) {
		printMsg("B2 Received\n\r");
		if (Board2_DW.received == 0) {
			Board2_DW.received = 1;
			HAL_GPIO_WritePin(RTR_OUT_GPIO_Port, RTR_OUT_Pin, GPIO_PIN_RESET);
			//B2checkPrintReceive();
		}
	}
}

void B2checkPrintReceive() {
	static uint8_t cont = 0;
	switch (cont) {
	case 0:
		BUS_LocalStateB1 tmpLS;
		deserializeLocalStateB1(&Board2_DW.rx_buffer[0],
				sizeof(BUS_LocalStateB1), &tmpLS);
		printMsg("RECEIVED\r\n");
		printLocalStateB1(&tmpLS);
		break;
	case 1:
		BUS_GlobalState tmpGS;
		deserializeGlobalState(&Board2_DW.rx_buffer[0], sizeof(BUS_GlobalState),
				&tmpGS);
		printMsg("RECEIVED\r\n");
		printGlobalState(&tmpGS);
		break;
	case 2:
		BUS_Decision tmpD;
		deserializeDecision(&Board2_DW.rx_buffer[0], sizeof(BUS_Decision),
				&tmpD);
		printMsg("RECEIVED\r\n");
		printDecision(&tmpD);
		break;
	default:
		break;
	}
	cont = (cont + 1) % 3;
}

void B2checkPrintTransmit() {
	static uint8_t cont = 0;
	switch (cont) {
	case 0:
		BUS_LocalStateB2 tmpLS;
		deserializeLocalStateB2(&Board2_DW.tx_buffer[0],
				sizeof(BUS_LocalStateB2), &tmpLS);
		printMsg("TRANSMITTED\r\n");
		printLocalStateB2(&tmpLS);
		break;
	case 1:
		BUS_GlobalState tmpGS;
		deserializeGlobalState(&Board2_DW.tx_buffer[0], sizeof(BUS_GlobalState),
				&tmpGS);
		printMsg("TRANSMITTED\r\n");
		printGlobalState(&tmpGS);
		break;
	case 2:
		BUS_Decision tmpD;
		deserializeDecision(&Board2_DW.tx_buffer[0], sizeof(BUS_Decision),
				&tmpD);
		printMsg("TRANSMITTED\r\n");
		printDecision(&tmpD);
		break;
	default:
		break;
	}
	cont = (cont + 1) % 3;
}
