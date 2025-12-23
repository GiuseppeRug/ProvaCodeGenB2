#include "stubFunctions.h"

// Da levareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include "Board_types.h"
#include "deserialize.h"
#include "print.h"
/* Implementazioni stub (funzioni vuote) */

uint8_t CheckRTR(void)
{
	static uint8_t prova = 0;
	if (prova == 0){
		prova = 1;
		return 1;
	}
    return 0;
}

void UartTransmitIT(uint8_t *pData, size_t size)
{
    /* Stub */
	BUS_LocalStateB2 tmp;
	deserializeLocalStateB2(pData, size, &tmp);
    printLocalStateB2(&tmp);
}

void UartReceiveIT(uint8_t *pData, size_t size)
{
    /* Stub */
    //(void)pData;
    //(void)size;
}
