#ifndef INC_DECISION_H_
#define INC_DECISION_H_

#include "enums.h"

/* SetPoint */
typedef struct {
    float leftAxis;
    float rightAxis;
} BUS_SetPoint;

/* Decision */
typedef struct {
	ENUM_Actuator   actuator;
    ENUM_UserAction userAction;
    ENUM_RoverAction roverAction;
    ENUM_SafeAction safeAction;
    BUS_SetPoint setPoint;
} BUS_Decision;

#endif /* INC_DECISION_H_ */
