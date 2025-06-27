//#include "BW_Phoenix_Driver_AX12.h"
//
////------------------------------------------------------------------------------------------
////[BeginServoUpdate] Does whatever preperation that is needed to start a move of a servos
////------------------------------------------------------------------------------------------
//void BeginServoUpdate(void)    // Start the update
//{
//	  uint8_t i;
//      //Servo control need to save away the new positions...
//      for (i = 0; i < NUMSERVOS; i++) {
//        g_awCurAXPos[i] = g_awGoalAXPos[i];
//      }
//}
//
////------------------------------------------------------------------------------------------
////[OutputServoInfoForLeg] Do the output to the SSC-32 for the servos associated with
////         the Leg number passed in.
////------------------------------------------------------------------------------------------
////void OutputServoInfoForLeg(uint8_t LegIndex, short sCoxaAngle1, short sFemurAngle1, short sTibiaAngle1)
//void OutputServoInfoForLeg(uint8_t LegIndex, short sCoxaAngle1, short sFemurAngle1, short sTibiaAngle1)
//{
////  uint16_t    wCoxaSDV;        // Coxa value in servo driver units
////  uint16_t    wFemurSDV;        //
////  uint16_t    wTibiaSDV;        //
//	uint16_t    wCoxaSDV;        // Coxa value in servo driver units
//	uint16_t    wFemurSDV;        //
//	uint16_t    wTibiaSDV;        //
//
//  // The Main code now takes care of the inversion before calling.
//  wCoxaSDV = (((long)(sCoxaAngle1)) * cPwmMult) / cPwmDiv + cPFConst;
//  wFemurSDV = (((long)((long)(sFemurAngle1)) * cPwmMult) / cPwmDiv + cPFConst);
//  wTibiaSDV = (((long)(sTibiaAngle1)) * cPwmMult) / cPwmDiv + cPFConst;
//
//      // Save away the new positions...
//      g_awGoalAXPos[FIRSTCOXAPIN + LegIndex] = wCoxaSDV;  // What order should we store these values?
//      g_awGoalAXPos[FIRSTFEMURPIN + LegIndex] = wFemurSDV;
//      g_awGoalAXPos[FIRSTTIBIAPIN + LegIndex] = wTibiaSDV;
//}
//
////==============================================================================
//// Calculate servo speeds to achieve desired pose timing
//// We make the following assumptions:
//// AX-12 speed is 59rpm @ 12V which corresponds to 0.170s/60deg
//// The AX-12 manual states this as the 'no load speed' at 12V
//// The Moving Speed control table entry states that 0x3FF = 114rpm
//// and according to Robotis this means 0x212 = 59rpm and anything greater 0x212 is also 59rpm
////uint16_t CalculateAX12MoveSpeed(uint16_t wCurPos, uint16_t wGoalPos, uint16_t wTime)
//uint16_t CalculateAX12MoveSpeed(uint16_t wCurPos, uint16_t wGoalPos, uint16_t wTime)
//{
////  uint16_t wTravel;
//  uint16_t wTravel;
//  uint32_t factor;
////  uint16_t wSpeed;
//  uint16_t wSpeed;
//
//  // find the amount of travel for each servo
//  if ( wGoalPos > wCurPos) {
//    wTravel = wGoalPos - wCurPos;
//  }
//  else {
//    wTravel = wCurPos - wGoalPos;
//  }
//
//  // now we can calculate the desired moving speed
//  // for 59pm the factor is 847.46 which we round to 848
//  // we need to use a temporary 32bit integer to prevent overflow
//  factor = (uint32_t) 848 * wTravel;
//
//  wSpeed = (uint16_t) ( factor / wTime );
//  // if the desired speed exceeds the maximum, we need to adjust
//  if (wSpeed > 1023) wSpeed = 1023;
//  // we also use a minimum speed of 26 (5% of 530 the max value for 59RPM)
//  if (wSpeed < 26) wSpeed = 26;
//
//  return wSpeed;
//}
//
////--------------------------------------------------------------------
////[CommitServoDriver Updates the positions of the servos - This outputs
////         as much of the command as we can without committing it.  This
////         allows us to once the previous update was completed to quickly
////        get the next command to start
////--------------------------------------------------------------------
////void CommitServoDriver(uint16_t wMoveTime)
//void CommitServoDriver(uint16_t wMoveTime)
//{
////#ifdef cSSC_BINARYMODE
////  uint8_t    abOut[3];
////#endif
//
//      // Need to first output the header for the Sync Write
//      int length = 4 + (NUMSERVOS * 5);   // 5 = id + pos(2byte) + speed(2 bytes)
//      int checksum = 254 + length + AX_SYNC_WRITE + 4 + AX_GOAL_POSITION_L;
////      uint16_t wSpeed;
//      uint16_t wSpeed;
////      setTXall();
//
//      GPIO_SetBits(GPIOC, GPIO_Pin_1);
//
//      Dynamx_Send(USART6,0xFF);
//      Dynamx_Send(USART6,0xFF);
//      Dynamx_Send(USART6,0xFE);
//      Dynamx_Send(USART6,length);
//      Dynamx_Send(USART6,AX_SYNC_WRITE);
//      Dynamx_Send(USART6,AX_GOAL_POSITION_L);
//      Dynamx_Send(USART6,4);    // number of bytes per servo (plus the ID...)
//
//      int i;
//      for (i = 0; i < NUMSERVOS; i++) {
//        wSpeed = CalculateAX12MoveSpeed(g_awCurAXPos[i], g_awGoalAXPos[i], wMoveTime);    // What order should we store these values?
//        uint8_t id = pgm_read_byte(&cPinTable[i]);
//        checksum += id + (g_awGoalAXPos[i] & 0xff) + (g_awGoalAXPos[i] >> 8) + (wSpeed >> 8) + (wSpeed & 0xff);
//        Dynamx_Send(USART6,id);
//        Dynamx_Send(USART6,g_awGoalAXPos[i] & 0xff);
//        Dynamx_Send(USART6,g_awGoalAXPos[i] >> 8);
//        Dynamx_Send(USART6,wSpeed & 0xff);
//        Dynamx_Send(USART6,wSpeed >> 8);
//
//      }
//      Dynamx_Send(USART6,0xff - (checksum % 256));
//
//      GPIO_ResetBits(GPIOC, GPIO_Pin_1);
////      setRX(0);
//}
