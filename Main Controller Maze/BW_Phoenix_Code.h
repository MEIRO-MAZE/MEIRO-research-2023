//#include "main.h"
//
//#ifndef BW_PHOENIX_CODE_H
//#define BW_PHOENIX_CODE_H
//
//
//
////extern unsigned int CNTLEGS;
//
//
////--------------------------------------------------------------------
////[TABLES]
////ArcCosinus Table
////Table build in to 3 part to get higher accuracy near cos = 1.
////The biggest error is near cos = 1 and has a biggest value of 3*0.012098rad = 0.521 deg.
////-    Cos 0 to 0.9 is done by steps of 0.0079 rad. [1/127]
////-    Cos 0.9 to 0.99 is done by steps of 0.0008 rad [0.1/127]
////-    Cos 0.99 to 1 is done by step of 0.0002 rad [0.01/64]
////Since the tables are overlapping the full range of 127+127+64 is not necessary. Total bytes: 277
//
////static const uint8_t GetACos[] = {
//extern const uint8_t GetACos[];
//
////Sin table 90 deg, persision 0.5 deg [180 values]
////static const uint16_t GetSin[] = {
//extern const uint16_t GetSin[] ;
//
//
////Build tables for Leg configuration like I/O and MIN/ Max values to easy access values using a FOR loop
////Constants are still defined as single values in the cfg file to make it easy to read/configure
//
//// BUGBUG: Need a cleaner way to define...
//// Lets allow for which legs servos to be inverted to be defined by the robot
//// This is used by the Lynxmotion Symetrical Quad.
//
//#ifndef cRRCoxaInv
//#define cRRCoxaInv 1
//#endif
//#ifndef cRMCoxaInv
//#define cRMCoxaInv 1
//#endif
//#ifndef cRFCoxaInv
//#define cRFCoxaInv 1
//#endif
//
//#ifndef cLRCoxaInv
//#define cLRCoxaInv 0
//#endif
//#ifndef cLMCoxaInv
//#define cLMCoxaInv 0
//#endif
//#ifndef cLFCoxaInv
//#define cLFCoxaInv 0
//#endif
//
//#ifndef cRRFemurInv
//#define cRRFemurInv 1
//#endif
//#ifndef cRMFemurInv
//#define cRMFemurInv 1
//#endif
//#ifndef cRFFemurInv
//#define cRFFemurInv 1
//#endif
//
//#ifndef cLRFemurInv
//#define cLRFemurInv 0
//#endif
//#ifndef cLMFemurInv
//#define cLMFemurInv 0
//#endif
//#ifndef cLFFemurInv
//#define cLFFemurInv 0
//#endif
//
//#ifndef cRRTibiaInv
//#define cRRTibiaInv 1
//#endif
//#ifndef cRMTibiaInv
//#define cRMTibiaInv 1
//#endif
//#ifndef cRFTibiaInv
//#define cRFTibiaInv 1
//#endif
//
//#ifndef cLRTibiaInv
//#define cLRTibiaInv 0
//#endif
//#ifndef cLMTibiaInv
//#define cLMTibiaInv 0
//#endif
//#ifndef cLFTibiaInv
//#define cLFTibiaInv 0
//#endif
//
//
//// Also define default BalanceDelay
//#ifndef BALANCE_DELAY
//#define BALANCE_DELAY 100
//#endif
//
//
//// Standard Hexapod...
//// Servo Horn offsets
//#ifdef cRRFemurHornOffset1   // per leg configuration
//static const short cFemurHornOffset1[]  = {
//  cRRFemurHornOffset1, cRMFemurHornOffset1, cRFFemurHornOffset1, cLRFemurHornOffset1, cLMFemurHornOffset1, cLFFemurHornOffset1};
//#define CFEMURHORNOFFSET1(LEGI) ((short)pgm_read_word(&cFemurHornOffset1[LEGI]))
//#else   // Fixed per leg, if not defined 0
//#ifndef cFemurHornOffset1
//#define cFemurHornOffset1  0
//#endif
//#define CFEMURHORNOFFSET1(LEGI)  (cFemurHornOffset1)
//#endif
//
//#ifdef cRRTibiaHornOffset1   // per leg configuration
//static const short cTibiaHornOffset1[]  = {
//  cRRTibiaHornOffset1, cRMTibiaHornOffset1, cRFTibiaHornOffset1, cLRTibiaHornOffset1, cLMTibiaHornOffset1, cLFTibiaHornOffset1};
//#define CTIBIAHORNOFFSET1(LEGI) ((short)pgm_read_word(&cTibiaHornOffset1[LEGI]))
//#else   // Fixed per leg, if not defined 0
//#ifndef cTibiaHornOffset1
//#define cTibiaHornOffset1  0
//#endif
//#define CTIBIAHORNOFFSET1(LEGI)  (cTibiaHornOffset1)
//#endif
//
//
////Min / Max values
//#ifndef SERVOS_DO_MINMAX
//extern const short cCoxaMin1[];
//extern const short cCoxaMax1[];
//extern const short cFemurMin1[];
//extern const short cFemurMax1[];
//extern const short cTibiaMin1[];
//extern const short cTibiaMax1[];
//
//#endif
//
//// Servo inverse direction
//extern const bool cCoxaInv[];
//extern bool cFemurInv[];
//extern const bool cTibiaInv[];
//
//
////Leg Lengths
//extern const uint8_t cCoxaLength[];
//extern const uint8_t cFemurLength[];
//extern const uint8_t cTibiaLength[];
//
//
////Body Offsets [distance between the center of the body and the center of the coxa]
//extern const short cOffsetX[];
//extern const short cOffsetZ[];
//
////Default leg angle
//extern const short cCoxaAngle1[];
//
//
//#ifdef cRRInitCoxaAngle1    // We can set different angles for the legs than just where they servo horns are set...
//extern const short cCoxaInitAngle1[];
//#endif
//
////Start positions for the leg
//extern const short cInitPosX[];
//extern const short cInitPosY[];
//extern const short cInitPosZ[];
//
//
////--------------------------------------------------------------------
////[REMOTE]
//  #define cTravelDeadZone         4    //The deadzone for the analog input from the remote
//
////====================================================================
////[ANGLES]
//extern short           CoxaAngle1[CNTLEGS];	//[CNTLEGS];    //Actual Angle of the horizontal hip, decimals = 1
//extern short           FemurAngle1[CNTLEGS];	//[CNTLEGS];   //Actual Angle of the vertical hip, decimals = 1
//extern short           TibiaAngle1[CNTLEGS];	//[CNTLEGS];   //Actual Angle of the knee, decimals = 1
//
////--------------------------------------------------------------------
////[POSITIONS SINGLE LEG CONTROL]
//
//extern short           LegPosX[CNTLEGS];	//[CNTLEGS];    //Actual X Posion of the Leg
//extern short           LegPosY[CNTLEGS];	//[CNTLEGS];    //Actual Y Posion of the Leg
//extern short           LegPosZ[CNTLEGS];	//[CNTLEGS];    //Actual Z Posion of the Leg
//
//
//
//////====================================================================
//////[ANGLES]
////extern short           CoxaAngle1[];    //Actual Angle of the horizontal hip, decimals = 1
////extern short           FemurAngle1[];   //Actual Angle of the vertical hip, decimals = 1
////extern short           TibiaAngle1[];   //Actual Angle of the knee, decimals = 1
////
//////--------------------------------------------------------------------
//////[POSITIONS SINGLE LEG CONTROL]
////
////extern short           LegPosX[];    //Actual X Posion of the Leg
////extern short           LegPosY[];    //Actual Y Posion of the Leg
////extern short           LegPosZ[];    //Actual Z Posion of the Leg
//
////--------------------------------------------------------------------
////[VARIABLES]
////uint8_t            Index;                    //Index universal used
////uint8_t            LegIndex;                //Index used for leg Index Number
//extern uint8_t            Index;                    //Index universal used
//extern uint8_t            LegIndex;                //Index used for leg Index Number
//
////GetSinCos / ArcCos
//extern short           AngleDeg1;        //Input Angle in degrees, decimals = 1
//extern short           sin4;             //Output Sinus of the given Angle, decimals = 4
//extern short           cos4;            //Output Cosinus of the given Angle, decimals = 4
//extern short           AngleRad4;        //Output Angle in radials, decimals = 4
//
////GetAtan2
//extern short           AtanX;            //Input X
//extern short           AtanY;            //Input Y
//extern short           Atan4;            //ArcTan2 output
//extern long            XYhyp2;            //Output presenting Hypotenuse of X and Y
//
////Body Inverse Kinematics
//extern short           PosX;            //Input position of the feet X
//extern short           PosZ;            //Input position of the feet Z
//extern short           PosY;            //Input position of the feet Y
//extern long            BodyFKPosX;        //Output Position X of feet with Rotation
//extern long            BodyFKPosY;        //Output Position Y of feet with Rotation
//extern long            BodyFKPosZ;        //Output Position Z of feet with Rotation
//
//
////Leg Inverse Kinematics
//extern long            IKFeetPosX;        //Input position of the Feet X
//extern long            IKFeetPosY;        //Input position of the Feet Y
//extern long            IKFeetPosZ;        //Input Position of the Feet Z
//extern bool         IKSolution;        //Output true if the solution is possible
//extern bool         IKSolutionWarning;    //Output true if the solution is NEARLY possible
//extern bool         IKSolutionError;    //Output true if the solution is NOT possible
//
//
////--------------------------------------------------------------------
////[TIMING]
//extern unsigned long   lTimerStart;    //Start time of the calculation cycles
//extern unsigned long   lTimerEnd;        //End time of the calculation cycles
////uint8_t            CycleTime;        //Total Cycle time
//extern uint8_t            CycleTime;        //Total Cycle time
//
////uint16_t            ServoMoveTime;        //Time for servo updates
////uint16_t            PrevServoMoveTime;    //Previous time for the servo updates
//extern uint16_t            ServoMoveTime;        //Time for servo updates
//extern uint16_t            PrevServoMoveTime;    //Previous time for the servo updates
//
////--------------------------------------------------------------------
////[Balance]
//extern long            TotalTransX;
//extern long            TotalTransZ;
//extern long            TotalTransY;
//extern long            TotalYBal1;
//extern long            TotalXBal1;
//extern long            TotalZBal1;
//
//
////[Single Leg Control]
//bool         AllDown;
//
////[gait - State]
//// Note: Information about the current gait is now part of the g_InControlState...
////boolean         TravelRequest;          //Temp to check if the gait is in motion
//
//extern long            GaitPosX[CNTLEGS];	//[CNTLEGS];         //Array containing Relative X position corresponding to the Gait
//extern long            GaitPosY[CNTLEGS];	//[CNTLEGS];         //Array containing Relative Y position corresponding to the Gait
//extern long            GaitPosZ[CNTLEGS];	//[CNTLEGS];         //Array containing Relative Z position corresponding to the Gait
//extern long            GaitRotY[CNTLEGS];	//[CNTLEGS];         //Array containing Relative Y rotation corresponding to the Gait
//
////boolean           GaitLegInAir[CNTLEGS];     // True if leg is in the air
////uint8_t          GaitNextLeg;                // The next leg which will be lifted
//
//extern bool        fWalking;            //  True if the robot are walking
//extern uint8_t            bExtraCycle;          // Forcing some extra timed cycles for avoiding "end of gait bug"
//#define         cGPlimit 2           // GP=GaitPos testing different limits
//
//
//extern short int LegStep;
//
////boolean        g_fRobotUpsideDown;    // Is the robot upside down?
////boolean        fRobotUpsideDownPrev;
//
//
////=============================================================================
//// Define our default standard Gaits
////=============================================================================
//#ifndef DEFAULT_GAIT_SPEED
//#define DEFAULT_GAIT_SPEED 50
//#define DEFAULT_SLOW_GAIT 70
//#endif
//
////cRR=0, cRF, cLR, cLF, CNTLEGS};
//
//
//// Hex Gaits
////  Speed, Steps, Lifted, Front Down, Lifted Factor, Half Height, On Ground,
////     Quad extra: COGAngleStart, COGAngleStep, CogRadius, COGCCW
////                      { RR, <RM> RF, LR, <LM>, LF}
////#ifdef DISPLAY_GAIT_NAMES
////extern "C" {
////  // Move the Gait Names to program space...
////  const char s_szGN1[]  = "Ripple 12";
////  const char s_szGN2[]  = "Tripod 8";
////  const char s_szGN3[]  = "Tripple 12";
////  const char s_szGN4[]  = "Tripple 16";
////  const char s_szGN5[]  = "Wave 24";
////  const char s_szGN6[]  = "Tripod 6";
////};
////#endif
//
////==============================================================================
//// Define Gait structure/class - Hopefully allow specific robots to define their
//// own gaits and/or define which of the standard ones they want.
////==============================================================================
//typedef struct _PhoenixGait {
//  short              NomGaitSpeed;       //Nominal speed of the gait
//  uint8_t            StepsInGait;         //Number of steps in gait
//  uint8_t            NrLiftedPos;         //Number of positions that a single leg is lifted [1-3]
//  uint8_t            FrontDownPos;        //Where the leg should be put down to ground
//  uint8_t            LiftDivFactor;       //Normaly: 2, when NrLiftedPos=5: 4
//  uint8_t            TLDivFactor;         //Number of steps that a leg is on the floor while walking
//  uint8_t            HalfLiftHeight;      // How high to lift at halfway up.
//
//  uint8_t            GaitLegNr[CNTLEGS];		//[CNTLEGS]; //Init position of the leg
//}
//PHOENIXGAIT;
//
//
//extern PHOENIXGAIT APG[];
//
//PHOENIXGAIT   gaitCur;             // Definition of the current gait
//
//
////--------------------------------------------------------------------
////uint8_t NUM_GAITS = sizeof(APG)/sizeof(APG[0]);
//extern uint8_t NUM_GAITS;
//
//extern unsigned long lTimeWaitEnd;
////=============================================================================
//// Function prototypes
////=============================================================================
//void GaitSelect(void);
//void WriteOutputs(void);
//void SingleLegControl(void);
//void GaitSeq(void);
//void BalanceBody(void);
//void CheckAngles();
//
//void PrintSystemStuff(void);            // Try to see why we fault...
//
//
////extern void  GaitGetNextLeg(uint8_t GaitStep);
//void BalCalcOneLeg (long PosX, long PosZ, long PosY, uint8_t BalLegNr);
//void BodyFK (short PosX, short PosZ, short PosY, short RotationY, uint8_t BodyIKLeg) ;
//void LegIK (short IKFeetPosX, short IKFeetPosY, short IKFeetPosZ, uint8_t LegIKLegNr);
//void Gait (uint8_t GaitCurrentLegNr);
//void GetSinCos(short AngleDeg1);
//
//extern short GetATan2 (short AtanX, short AtanY);
//extern unsigned long isqrt32 (unsigned long n);
//
//void StartUpdateServos(void);
//
//#endif
//
