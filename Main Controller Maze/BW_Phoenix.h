////=============================================================================
////Project Lynxmotion Phoenix
////Description: Phoenix software
////
////Programmer: Jeroen Janssen [aka Xan]
////         Kurt Eckhardt(KurtE) converted to C and Arduino
////   Kare Halvorsen aka Zenta - Makes everything work correctly!
////
//// This version of the Phoenix code was ported over to the Arduino Environement
////
////
//// Phoenix.h - This is the first header file that is needed to build
////          a Phoenix program for a specific Hex Robot.
////
////
//// This file assumes that the main source file either directly or through include
//// file has defined all of the configuration information for the specific robot.
//// Each robot will also need to include:
////
////=============================================================================
////
////KNOWN BUGS:
////    - Lots ;)
////
////=============================================================================
////==============================================================================
//#ifndef BW_PHOENIX_H
//#define BW_PHOENIX_H
//
//#include "main.h"
////include <stdarg.h>
////#include <EEPROM.h>
//
////extern unsigned int CNTLEGS;
//
//
////#define PROGMEM
//#define pgm_read_byte(x)        (*((char *)x))
////  #define pgm_read_word(x)        (*((short *)(x & 0xfffffffe)))
//#define pgm_read_word(x)        ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x)))
//#define pgm_read_byte_near(x)   (*((char *)x))
//#define pgm_read_byte_far(x)    (*((char *)x))
////  #define pgm_read_word_near(x)   (*((short *)(x & 0xfffffffe))
////  #define pgm_read_word_far(x)    (*((short *)(x & 0xfffffffe)))
//#define pgm_read_word_near(x)   ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x)))
//#define pgm_read_word_far(x)    ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x))))
//#define PSTR(x)  x
////
//////=============================================================================
//////[CONSTANTS]
//////=============================================================================
//#define BUTTON_DOWN 0
//#define BUTTON_UP   1
////
////#define c1DEC       10
////#define c2DEC       100
////#define c4DEC       10000
////#define c6DEC       1000000
//
//extern float c1DEC;
//extern float c2DEC;
//extern float c4DEC;
//extern float c6DEC;
//
////
//enum {
//  cRR=0, cRM, cRF, cLR, cLM, cLF, CNTLEGS};
////
////#define WTIMERTICSPERMSMUL      64  // BAP28 is 16mhz need a multiplyer and divider to make the conversion with /8192
////#define WTIMERTICSPERMSDIV      125 //
////#define USEINT_TIMERAV
//
//
//// BUGBUG: to make Dynamic first pass simpl make it a variable.
////extern  uint8_t    NUM_GAITS;
//#define SmDiv        4  //"Smooth division" factor for the smooth control function, a value of 3 to 5 is most suitable
//void GaitSelect(void);
//short SmoothControl (short CtrlMoveInp, short CtrlMoveOut, uint8_t CtrlDivider);
//
//
//
////-----------------------------------------------------------------------------
//// Define Global variables
////-----------------------------------------------------------------------------
//
////extern boolean          g_fDebugOutput;
////extern boolean          g_fEnableServos;      // Hack to allow me to turn servo processing off...
////extern boolean          g_fRobotUpsideDown;    // Is the robot upside down?
//
//uint16_t GetLegsXZLength(void);
//void AdjustLegPositions(uint16_t XZLength1);
//void AdjustLegPositionsToBodyHeight();
//void ResetLegInitAngles(void);
//void RotateLegInitAngles (int iDeltaAngle);
//long GetCmdLineNum(uint8_t **ppszCmdLine);
//
//// debug handler...
////extern boolean g_fDBGHandleError;
//
////#ifdef OPT_BACKGROUND_PROCESS
////#define DoBackgroundProcess()   g_ServoDriver.BackgroundProcess()
////#else
////#define DoBackgroundProcess()
////#endif
//
////#ifdef DEBUG_IOPINS
////#define DebugToggle(pin)  {digitalWrite(pin, !digitalRead(pin));}
////#define DebugWrite(pin, state) {digitalWrite(pin, state);}
////#else
////#define DebugToggle(pin)  {;}
////#define DebugWrite(pin, state) {;}
////#endif
//
//
//
//
//
//typedef struct COORD3D
//{
//    float x,y,z;
//}
//COORD3D;
//
//struct movement
//{
//	float x;
//	float y;
//	float z;
//}
//BodyPos,BodyRot1,BodyRotOffset,TravelLength;
//
////[Single Leg Control]
//#ifdef OPT_SINGLELEG
//uint8_t          SelectedLeg;
//uint8_t          PrevSelectedLeg;
//COORD3D       SLLeg;               //
//bool       fSLHold;             //Single leg control mode
//#endif
//
////[gait]
//uint8_t          GaitType;            //Gait type
//uint8_t          GaitStep;            //Actual current step in gait
//
//short       LegLiftHeight;
//
////[TIMING]
//uint8_t          InputTimeDelay; //Delay that depends on the input to get the "sneaking" effect
//uint16_t          SpeedControl;   //Adjustible Delay
//uint8_t          ForceGaitStepCnt;          // new to allow us to force a step even when not moving
//
//uint16_t	BalanceMode;
//
//static short   g_BodyYOffset;
//static short   g_BodyYShift;
//static uint8_t    ControlMode;
//static uint8_t    HeightSpeedMode;
//
////[CONSTANTS]
//enum {
//  WALKMODE=0, TRANSLATEMODE, ROTATEMODE,
//#ifdef OPT_SINGLELEG
//  SINGLELEGMODE,
//#endif
//#ifdef OPT_GPPLAYER
//  GPPLAYERMODE,
//#endif
//  MODECNT};
//enum {
//  NORM_NORM=0, NORM_LONG, HIGH_NORM, HIGH_LONG};
//
//
////==============================================================================
//// class ControlState: This is the main structure of data that the Control
////      manipulates and is used by the main Phoenix Code to make it do what is
////      requested.
////==============================================================================
////typedef struct _InControlState {
//////  boolean       fRobotOn;            //Switch to turn on Phoenix
//////  boolean       fPrev_RobotOn;       //Previous loop state
////  //Body position
////  COORD3D       BodyPos;
////  COORD3D       BodyRotOffset;      // Body rotation offset;
////
////  //Body Inverse Kinematics
////  COORD3D       BodyRot1;            // X -Pitch, Y-Rotation, Z-Roll
////
////  //[gait]
////  uint8_t          GaitType;            //Gait type
////  uint8_t          GaitStep;            //Actual current step in gait
////  PHOENIXGAIT   gaitCur;             // Definition of the current gait
////
////  short       LegLiftHeight;       //Current Travel height
////  COORD3D       TravelLength;        // X-Z or Length, Y is rotation.
////
//////#ifdef cTurretRotPin
//////  // Turret information
//////  int           TurretRotAngle1;      // Rotation of turrent in 10ths of degree
//////  int           TurretTiltAngle1;    // the tile for the turret
//////#endif
////
////  //[Single Leg Control]
//////#ifdef OPT_SINGLELEG
////  uint8_t          SelectedLeg;
////  uint8_t          PrevSelectedLeg;
////  COORD3D       SLLeg;               //
//////  boolean       fSLHold;             //Single leg control mode
//////#endif
////
////  //[Balance]
//////  boolean       BalanceMode;
////
////  //[TIMING]
////  uint8_t          InputTimeDelay; //Delay that depends on the input to get the "sneaking" effect
////  uint16_t          SpeedControl;   //Adjustible Delay
////  uint8_t          ForceGaitStepCnt;          // new to allow us to force a step even when not moving
////
////#ifdef OPT_DYNAMIC_ADJUST_LEGS
////  short         aCoxaInitAngle1[CNTLEGS];
////#endif
////
////  //
////
////}
////INCONTROLSTATE;
//
//
////==============================================================================
////==============================================================================
//// Define the class(s) for Servo Drivers.
////==============================================================================
////==============================================================================
////class ServoDriver {
////public:
////  void Init(void);
////
////  uint16_t GetBatteryVoltage(void);
////
////#ifdef OPT_GPPLAYER
////  inline boolean  FIsGPEnabled(void) {
////    return _fGPEnabled;
////  };
////  boolean         FIsGPSeqDefined(uint8_t iSeq);
////  inline boolean  FIsGPSeqActive(void) {
////    return _fGPActive;
////  };
////  void            GPStartSeq(uint8_t iSeq);  // 0xff - says to abort...
////  void            GPPlayer(void);
////  uint8_t         GPNumSteps(void);          // How many steps does the current sequence have
////  uint8_t         GPCurStep(void);           // Return which step currently on...
////  void            GPSetSpeedMultiplyer(short sm) ;      // Set the Speed multiplier (100 is default)
////#endif
////  void            BeginServoUpdate(void);    // Start the update
////#ifdef c4DOF
////  void            OutputServoInfoForLeg(uint8_t LegIndex, short sCoxaAngle1, short sFemurAngle1, short sTibiaAngle1, short sTarsAngle1);
////#else
////  void            OutputServoInfoForLeg(uint8_t LegIndex, short sCoxaAngle1, short sFemurAngle1, short sTibiaAngle1);
////#endif
////#ifdef cTurretRotPin
////  void            OutputServoInfoForTurret(short sRotateAngle1, short sTiltAngle1);
////#endif
////  void            CommitServoDriver(uint16_t wMoveTime);
////  void            FreeServos(void);
////
////  void            IdleTime(void);        // called when the main loop when the robot is not on
////
////  // Allow for background process to happen...
////#ifdef OPT_BACKGROUND_PROCESS
////  void            BackgroundProcess(void);
////#endif
////
////#ifdef OPT_TERMINAL_MONITOR
////  void            ShowTerminalCommandList(void);
////  boolean         ProcessTerminalCommand(uint8_t *psz, uint8_t bLen);
////#endif
////
////private:
////
////#ifdef OPT_GPPLAYER
////  boolean _fGPEnabled;     // IS GP defined for this servo driver?
////  boolean _fGPActive;      // Is a sequence currently active - May change later when we integrate in sequence timing adjustment code
////  uint8_t    _iSeq;        // current sequence we are running
////  short    _sGPSM;        // Speed multiplier +-200
////#endif
////
////}
////;
//
////==============================================================================
////==============================================================================
//// Define global class objects
////==============================================================================
////==============================================================================
////extern ServoDriver      g_ServoDriver;           // our global servo driver class
////extern InputController  g_InputController;       // Our Input controller
////extern INCONTROLSTATE   g_InControlState;        // State information that controller changes
//
//
//#endif
//
//
//
