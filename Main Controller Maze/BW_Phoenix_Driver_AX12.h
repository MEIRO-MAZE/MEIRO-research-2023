//#include "main.h"
//
//#ifndef BW_PHOENIX_DRIVER_AX12_H
//#define BW_PHOENIX_DRIVER_AX12_H
//
//
////extern unsigned int CNTLEGS;
//
////unsigned int CNTLEGS=6;
//
//#define NUMSERVOSPERLEG 3
//
////#define CNTLEGS 6
//
//#define NUMSERVOS (NUMSERVOSPERLEG*CNTLEGS)//18	//
//
//#define cPwmMult      128
//#define cPwmDiv       375
//#define cPFConst      512    // half of 1024 range
//
//// Some defines for Voltage processing
//#define VOLTAGE_MIN_TIME_UNTIL_NEXT_INTERPOLATE 4000  // Min time in us Until we should do next interpolation, as to not interfer.
//#define VOLTAGE_MIN_TIME_BETWEEN_CALLS 150      // Max 6+ times per second
//#define VOLTAGE_MAX_TIME_BETWEEN_CALLS 1000    // call at least once per second...
//#define VOLTAGE_TIME_TO_ERROR          3000    // Error out if no valid item is returned in 3 seconds...
//
//// Current positions in AX coordinates
////uint16_t g_awCurAXPos[NUMSERVOS];
////uint16_t g_awGoalAXPos[NUMSERVOS];
//extern uint16_t      g_awCurAXPos[NUMSERVOS];
//extern uint16_t      g_awGoalAXPos[NUMSERVOS];
//
////#ifdef DEBUG_SERVOS
////#define ServosEnabled   (g_fEnableServos)
////#else
////#define ServosEnabled  (true)      // always true compiler should remove if...
////#endif
//
////=============================================================================
//// Global - Local to this file only...
////=============================================================================
//extern const uint8_t cPinTable[];
//
//#define FIRSTCOXAPIN     0
//#define FIRSTFEMURPIN    (CNTLEGS)
//#define FIRSTTIBIAPIN    (CNTLEGS*2)
//#define FIRSTTURRETPIN   (CNTLEGS*3)
//
//
//#endif
