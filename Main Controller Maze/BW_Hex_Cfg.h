////====================================================================
////Project Lynxmotion Phoenix
////Description:
////    This is the hardware configuration file for the
////    Version 2 PhantomX robot.
////    Will first define to use their commander unit.
////
////Date: June 19, 2013
////Programmer: Kurt (aka KurtE)
////
////NEW IN V1.0
////   - First Release - Changes from Trossen member KingPin
////
////====================================================================
//#ifndef BW_HEX_CFG_H
//#define BW_HEX_CFG_H
//
//#include "main.h"
//
//// Define other optional compnents to be included or not...
////#define PHANTOMX_V2     // Some code may depend on it being a V2 PhantomX
//
//#define cFemurHornOffset1 -35
//#define cTibiaHornOffset1 463
//#define cRRTibiaInv 0
//#define cRMTibiaInv 0
//#define cRFTibiaInv 0
//#define cLRTibiaInv 1
//#define cLMTibiaInv 1
//#define cLFTibiaInv 1
//
//#define OPT_SINGLELEG
////==================================================================================================================================
////==================================================================================================================================
////==================================================================================================================================
////  PhantomX
////==================================================================================================================================
//
//
////====================================================================
//#define  DEFAULT_GAIT_SPEED 35  // Default gait speed  - Will depend on what Servos you are using...
//#define  DEFAULT_SLOW_GAIT  50  // Had a couple different speeds...
//
//
////--------------------------------------------------------------------
//// Define which pins(sevo IDS go with which joint
//
//#define cRRCoxaPin      16 //8   //Rear Right leg Hip Horizontal
//#define cRRFemurPin     17 //10   //Rear Right leg Hip Vertical
//#define cRRTibiaPin     18 //12   //Rear Right leg Knee
//
//#define cRMCoxaPin      13 //14  //Middle Right leg Hip Horizontal
//#define cRMFemurPin     14 //16  //Middle Right leg Hip Vertical
//#define cRMTibiaPin     15 //18  //Middle Right leg Knee
//
//#define cRFCoxaPin      10 //2  //Front Right leg Hip Horizontal
//#define cRFFemurPin     11 //4  //Front Right leg Hip Vertical
//#define cRFTibiaPin     12 //6   //Front Right leg Knee
//
//#define cLRCoxaPin      7 //7   //Rear Left leg Hip Horizontal
//#define cLRFemurPin     8 //9   //Rear Left leg Hip Vertical
//#define cLRTibiaPin     9 //11   //Rear Left leg Knee
//
//#define cLMCoxaPin      4 //13   //Middle Left leg Hip Horizontal
//#define cLMFemurPin     5 //15   //Middle Left leg Hip Vertical
//#define cLMTibiaPin     6 //17  //Middle Left leg Knee
//
//#define cLFCoxaPin      1 //1   //Front Left leg Hip Horizontal
//#define cLFFemurPin     2 //3   //Front Left leg Hip Vertical
//#define cLFTibiaPin     3 //5   //Front Left leg Knee
//
//#define cTurretRotPin  20   // Turret Rotate Pin
//#define cTurretTiltPin 21  // Turret Tilt pin
//
////--------------------------------------------------------------------
////[MIN/MAX ANGLES] - Start off assume same as Phoenix...
//#define cRRCoxaMin1    -750
//#define cRRCoxaMax1    750
//#define cRRFemurMin1    -1000
//#define cRRFemurMax1    1000
//#define cRRTibiaMin1    -1020
//#define cRRTibiaMax1    670
//
//#define cRMCoxaMin1    -750    //Mechanical limits of the Right Middle Leg, decimals = 1
//#define cRMCoxaMax1     750
//#define cRMFemurMin1     -1000
//#define cRMFemurMax1     1000
//#define cRMTibiaMin1    -1020
//#define cRMTibiaMax1     670
//
//#define cRFCoxaMin1    -750    //Mechanical limits of the Right Front Leg, decimals = 1
//#define cRFCoxaMax1     750
//#define cRFFemurMin1    -1000
//#define cRFFemurMax1    1000
//#define cRFTibiaMin1    -1020
//#define cRFTibiaMax1    670
//
//#define cLRCoxaMin1    -750    //Mechanical limits of the Left Rear Leg, decimals = 1
//#define cLRCoxaMax1     750
//#define cLRFemurMin1     -1000
//#define cLRFemurMax1     1000
//#define cLRTibiaMin1    -1020
//#define cLRTibiaMax1     670
//
//#define cLMCoxaMin1    -1000    //Mechanical limits of the Left Middle Leg, decimals = 1
//#define cLMCoxaMax1     1000
//#define cLMFemurMin1     -1000
//#define cLMFemurMax1     1000
//#define cLMTibiaMin1    -1020
//#define cLMTibiaMax1     670
//
//#define cLFCoxaMin1     -750    //Mechanical limits of the Left Front Leg, decimals = 1
//#define cLFCoxaMax1     750
//#define cLFFemurMin1     -1000
//#define cLFFemurMax1     1000
//#define cLFTibiaMin1    -1020
//#define cLFTibiaMax1     670
//
//#define cTurretRotMin1  -1500
//#define cTurretRotMax1  1500
//#define cTurretTiltMin1  -125
//#define cTurretTiltMax1  1100
//
////--------------------------------------------------------------------
////[Joint offsets]
//// This allows us to calibrate servos to some fixed position, and then adjust them by moving theim
//// one or more servo horn clicks.  This requires us to adjust the value for those servos by 15 degrees
//// per click.  This is used with the T-Hex 4DOF legs
////First calibrate the servos in the 0 deg position using the SSC-32 reg offsets, then:
////--------------------------------------------------------------------
////[LEG DIMENSIONS]
////Universal dimensions for each leg in mm
//#define cXXCoxaLength     10    // PhantomX leg dimensions.
//#define cXXFemurLength    40    // MEASURE THIS!!! Guessed now :-)
//#define cXXTibiaLength    70  // MEASURE THIS!!! Guessed now :-)
//
//#define cRRCoxaLength     cXXCoxaLength	    //Right Rear leg
//#define cRRFemurLength    cXXFemurLength
//#define cRRTibiaLength    cXXTibiaLength
//
//
//#define cRMCoxaLength     cXXCoxaLength	    //Right middle leg
//#define cRMFemurLength    cXXFemurLength
//#define cRMTibiaLength    cXXTibiaLength
//
//
//#define cRFCoxaLength     cXXCoxaLength	    //Rigth front leg
//#define cRFFemurLength    cXXFemurLength
//#define cRFTibiaLength    cXXTibiaLength
//
//
//#define cLRCoxaLength     cXXCoxaLength	    //Left Rear leg
//#define cLRFemurLength    cXXFemurLength
//#define cLRTibiaLength    cXXTibiaLength
//
//
//#define cLMCoxaLength     cXXCoxaLength	    //Left middle leg
//#define cLMFemurLength    cXXFemurLength
//#define cLMTibiaLength    cXXTibiaLength
//
//
//#define cLFCoxaLength     cXXCoxaLength	    //Left front leg
//#define cLFFemurLength    cXXFemurLength
//#define cLFTibiaLength    cXXTibiaLength
//
//
//
////--------------------------------------------------------------------
////[BODY DIMENSIONS]
//#define cRRCoxaAngle1   -450   //Default Coxa setup angle, decimals = 1
//#define cRMCoxaAngle1    0      //Default Coxa setup angle, decimals = 1
//#define cRFCoxaAngle1    450      //Default Coxa setup angle, decimals = 1
//#define cLRCoxaAngle1    -450   //Default Coxa setup angle, decimals = 1
//#define cLMCoxaAngle1    0      //Default Coxa setup angle, decimals = 1
//#define cLFCoxaAngle1    450      //Default Coxa setup angle, decimals = 1
//
//#define X_COXA      62  // MM between front and back legs /2
//#define Y_COXA      37  // MM between front/back legs /2
//#define M_COXA      52  // MM between two middle legs /2
//
//#define cRROffsetX      -37     //Distance X from center of the body to the Right Rear coxa
//#define cRROffsetZ      73     //Distance Z from center of the body to the Right Rear coxa
//
//#define cRMOffsetX      -52    //Distance X from center of the body to the Right Middle coxa
//#define cRMOffsetZ      0       //Distance Z from center of the body to the Right Middle coxa
//
//#define cRFOffsetX      -37     //Distance X from center of the body to the Right Front coxa
//#define cRFOffsetZ      -73    //Distance Z from center of the body to the Right Front coxa
//
//#define cLROffsetX      37      //Distance X from center of the body to the Left Rear coxa
//#define cLROffsetZ      73     //Distance Z from center of the body to the Left Rear coxa
//
//#define cLMOffsetX      52     //Distance X from center of the body to the Left Middle coxa
//#define cLMOffsetZ      0       //Distance Z from center of the body to the Left Middle coxa
//
//#define cLFOffsetX      37      //Distance X from center of the body to the Left Front coxa
//#define cLFOffsetZ      -73    //Distance Z from center of the body to the Left Front coxa
//
////--------------------------------------------------------------------
////[START POSITIONS FEET]
//#define cHexInitXZ	 147
//#define CHexInitXZCos60  104        // COS(45) = .707
//#define CHexInitXZSin60  104    // sin(45) = .707
//#define CHexInitY	 25 //30
//
//// Lets try some multi leg positions depending on height settings.
//#define CNT_HEX_INITS 2
//#define MAX_BODY_Y  150
//
//
////const uint8_t g_abHexIntXZ[]= {cHexInitXZ, 144};
////const uint8_t g_abHexMaxBodyY[]= { 20, MAX_BODY_Y};
//
////extern const uint8_t g_abHexIntXZ[];
////extern const uint8_t g_abHexMaxBodyY[];
//
//extern const unsigned char g_abHexIntXZ[];
//extern const unsigned char g_abHexMaxBodyY[];
//
//#define cRRInitPosX     CHexInitXZCos60      //Start positions of the Right Rear leg
//#define cRRInitPosY     CHexInitY
//#define cRRInitPosZ     CHexInitXZSin60
//
//#define cRMInitPosX     cHexInitXZ      //Start positions of the Right Middle leg
//#define cRMInitPosY     CHexInitY
//#define cRMInitPosZ     0
//
//#define cRFInitPosX     CHexInitXZCos60      //Start positions of the Right Front leg
//#define cRFInitPosY     CHexInitY
//#define cRFInitPosZ     -CHexInitXZSin60
//
//#define cLRInitPosX     CHexInitXZCos60      //Start positions of the Left Rear leg
//#define cLRInitPosY     CHexInitY
//#define cLRInitPosZ     CHexInitXZSin60
//
//#define cLMInitPosX     cHexInitXZ      //Start positions of the Left Middle leg
//#define cLMInitPosY     CHexInitY
//#define cLMInitPosZ     0
//
//#define cLFInitPosX     CHexInitXZCos60      //Start positions of the Left Front leg
//#define cLFInitPosY     CHexInitY
//#define cLFInitPosZ     -CHexInitXZSin60
//
//// Turret initial position
//#define cTurretRotInit  0
//#define cTurretTiltInit 0
//
//#endif // HEX_CFG_H
//
