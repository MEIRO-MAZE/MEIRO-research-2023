//#include "BW_Phoenix_Code.h"
//
////--------------------------------------------------------------------------
//// SETUP: the main arduino setup function.
////--------------------------------------------------------------------------
//void setup_phoenix(){
//
//  // Setup Init Positions
//  for (LegIndex= 0; LegIndex < CNTLEGS; LegIndex++ )
////  for (LegIndex= 0; LegIndex < 6; LegIndex++ )
//  {
//    LegPosX[LegIndex] = (short)pgm_read_word(&cInitPosX[LegIndex]);    //Set start positions for each leg
//    LegPosY[LegIndex] = (short)pgm_read_word(&cInitPosY[LegIndex]);
//    LegPosZ[LegIndex] = (short)pgm_read_word(&cInitPosZ[LegIndex]);
//  }
//
//  ResetLegInitAngles();
//
//  //Single leg control. Make sure no leg is selected
//#ifdef OPT_SINGLELEG
//  SelectedLeg = 255; // No Leg selected
//  PrevSelectedLeg = 255;
//#endif
//		g_BodyYOffset = 0;
//		g_BodyYShift = 0;
//
//  //Body Positions
//  BodyPos.x = 0;
//  BodyPos.y = 0;
//  BodyPos.z = 0;
//
//  //===TRANSLATE MODE===//
////	  BodyPos.x =  SmoothControl(((lx)*2/3), BodyPos.x, SmDiv);
////	  BodyPos.z =  SmoothControl(((ly)*2/3), BodyPos.z, SmDiv);
////	  BodyRot1.y = SmoothControl(((rightH)*2), BodyRot1.y, SmDiv);
////	  g_BodyYShift = (-(rightV)/2);
//  //===================//
//
//  //Body Rotations
//  BodyRot1.x = 0;
//  BodyRot1.y = 0;
//  BodyRot1.z = 0;
//
//  //===ROTATE MODE===//
////	  BodyRot1.x = (ly);
////	  BodyRot1.y = (rightH)*2;
////	  BodyRot1.z = (lx);
////	  g_BodyYShift = (-(rightV)/2);
//  //=================//
//
//  BodyRotOffset.x = 0;
//  BodyRotOffset.y = 0;        //Input Y offset value to adjust centerpoint of rotation
//  BodyRotOffset.z = 0;
//
//  //===WALK MODE===//
//	  TravelLength.x = 77;
//	  TravelLength.y = 0;
//	  TravelLength.z = 0;
//  //===============//
//
//
//  //Gait
//  GaitType = 0;
//  BalanceMode = 0;
//  LegLiftHeight = 50;
//  ForceGaitStepCnt = 0;    // added to try to adjust starting positions depending on height...
//  GaitStep = 1;
//  GaitSelect();
//
////  g_InputController.Init();
//
//		  ControlMode = WALKMODE;
//		  HeightSpeedMode = NORM_NORM;
////		  DoubleTravelOn = false;
////		  bJoystickWalkMode = 0;
//
//
//  // Servo Driver
//  ServoMoveTime = 150;
////  fRobotOn = 0;
////  g_fLowVoltageShutdown = false;
//
//}
//
//
////=============================================================================
//// Loop: the main arduino main Loop function
////=============================================================================
//
//
//void loop_phoenix (void)
//{
//
////    g_InputController.ControlInput();
//
//	  //Single leg control
//	  SingleLegControl ();
//
//  //Gait
//  GaitSeq();
//
//  //Balance calculations
//  TotalTransX = 0;     //reset values used for calculation of balance
//  TotalTransZ = 0;
//  TotalTransY = 0;
//  TotalXBal1 = 0;
//  TotalYBal1 = 0;
//  TotalZBal1 = 0;
//
//  //Reset IKsolution indicators
//  IKSolution = 0 ;
//  IKSolutionWarning = 0;
//  IKSolutionError = 0 ;
//
//  //Do IK for all Right legs
//
//  for (LegIndex = 0; LegIndex < (CNTLEGS/2); LegIndex++)
////  for (LegIndex = 0; LegIndex < (6/2); LegIndex++)
//  {
////    DoBackgroundProcess();
//    BodyFK(-LegPosX[LegIndex]+BodyPos.x+GaitPosX[LegIndex] - TotalTransX,
//    LegPosZ[LegIndex]+BodyPos.z+GaitPosZ[LegIndex] - TotalTransZ,
//    LegPosY[LegIndex]+BodyPos.y+GaitPosY[LegIndex] - TotalTransY,
//    GaitRotY[LegIndex], LegIndex);
//
//    LegIK (LegPosX[LegIndex]-BodyPos.x+BodyFKPosX-(GaitPosX[LegIndex] - TotalTransX),
//    LegPosY[LegIndex]+BodyPos.y-BodyFKPosY+GaitPosY[LegIndex] - TotalTransY,
//    LegPosZ[LegIndex]+BodyPos.z-BodyFKPosZ+GaitPosZ[LegIndex] - TotalTransZ, LegIndex);
//  }
//
//  //Do IK for all Left legs
//  for (LegIndex = (CNTLEGS/2); LegIndex < CNTLEGS; LegIndex++)
////  for (LegIndex = (6/2); LegIndex < 6; LegIndex++)
//  {
////    DoBackgroundProcess();
//    BodyFK(LegPosX[LegIndex]-BodyPos.x+GaitPosX[LegIndex] - TotalTransX,
//    LegPosZ[LegIndex]+BodyPos.z+GaitPosZ[LegIndex] - TotalTransZ,
//    LegPosY[LegIndex]+BodyPos.y+GaitPosY[LegIndex] - TotalTransY,
//    GaitRotY[LegIndex], LegIndex);
//    LegIK (LegPosX[LegIndex]+BodyPos.x-BodyFKPosX+GaitPosX[LegIndex] - TotalTransX,
//    LegPosY[LegIndex]+BodyPos.y-BodyFKPosY+GaitPosY[LegIndex] - TotalTransY,
//    LegPosZ[LegIndex]+BodyPos.z-BodyFKPosZ+GaitPosZ[LegIndex] - TotalTransZ, LegIndex);
//  }
//
//  //Check mechanical limits==========
////  CheckAngles();
//
//    //Calculate Servo Move time===========
////    if ((abs(TravelLength.x)>cTravelDeadZone) || (abs(TravelLength.z)>cTravelDeadZone) ||
////      (abs(TravelLength.y*2)>cTravelDeadZone)) {
////      ServoMoveTime = gaitCur.NomGaitSpeed + (InputTimeDelay*2) + SpeedControl;
//      ServoMoveTime = gaitCur.NomGaitSpeed;
////
////    }
////    else //Movement speed excl. Walking
////    ServoMoveTime = 200 + SpeedControl;
//
//    // note we broke up the servo driver into start/commit that way we can output all of the servo information
//    // before we wait and only have the termination information to output after the wait.  That way we hopefully
//    // be more accurate with our timings...
//
//    StartUpdateServos();
//
//    // See if we need to sync our processor with the servo driver while walking to ensure the prev is completed
//    //before sending the next one
//
//
//    // Finding any incident of GaitPos/Rot <>0:==================
//////    for (LegIndex = 0; LegIndex < CNTLEGS; LegIndex++)
////    for (LegIndex = 0; LegIndex < 6; LegIndex++)
////    {
////      if ( (GaitPosX[LegIndex] > cGPlimit) || (GaitPosX[LegIndex] < -cGPlimit)
////        || (GaitPosZ[LegIndex] > cGPlimit) || (GaitPosZ[LegIndex] < -cGPlimit)
////        || (GaitRotY[LegIndex] > cGPlimit) || (GaitRotY[LegIndex] < -cGPlimit))    {
////
////        bExtraCycle = gaitCur.NrLiftedPos + 1;//For making sure that we are using timed move until all legs are down
////        break;
////      }
////    }
////    if (bExtraCycle>0){
////      bExtraCycle--;
////      fWalking = !(bExtraCycle==0);
////
////      //Get endtime and calculate wait time
////      lTimeWaitEnd = lTimerStart + PrevServoMoveTime;
////
//////      DebugWrite(A1, HIGH);
////      do {
////        // Wait the appropriate time, call any background process while waiting...
//////        DoBackgroundProcess();
////      }
////      while (millis() < lTimeWaitEnd);
//////      DebugWrite(A1, LOW);
////
////    }
//
//    // Only do commit if we are actually doing something...
////    DebugToggle(A2);
//    CommitServoDriver(ServoMoveTime);
//
//  PrevServoMoveTime = ServoMoveTime;
//
//}
//
//
//void StartUpdateServos()
//{
//  uint8_t    LegIndex;
//
//  // First call off to the init...
//  BeginServoUpdate();    // Start the update
//
//    for (LegIndex = 0; LegIndex < CNTLEGS; LegIndex++)
////	for (LegIndex = 0; LegIndex < 6; LegIndex++)
//    {
//
//    OutputServoInfoForLeg(LegIndex,
//        cCoxaInv[LegIndex]? -CoxaAngle1[LegIndex] : CoxaAngle1[LegIndex],
//        cFemurInv[LegIndex]? -FemurAngle1[LegIndex] : FemurAngle1[LegIndex],
//        cTibiaInv[LegIndex]? -TibiaAngle1[LegIndex] : TibiaAngle1[LegIndex]);
//
//  }
////#ifdef cTurretRotPin
////  g_ServoDriver.OutputServoInfoForTurret(g_InControlState.TurretRotAngle1, g_InControlState.TurretTiltAngle1);  // fist just see if it will talk
////#endif
//}
//
//
////--------------------------------------------------------------------
////[SINGLE LEG CONTROL]
//void SingleLegControl(void)
//{
//#ifdef OPT_SINGLELEG
//
//  //Check if all legs are down
//  AllDown = (LegPosY[cRF]==(short)pgm_read_word(&cInitPosY[cRF])) &&
//    (LegPosY[cRR]==(short)pgm_read_word(&cInitPosY[cRR])) &&
//    (LegPosY[cLR]==(short)pgm_read_word(&cInitPosY[cLR])) &&
//
//    (LegPosY[cRM]==(short)pgm_read_word(&cInitPosY[cRM])) &&
//    (LegPosY[cLM]==(short)pgm_read_word(&cInitPosY[cLM])) &&
//
//
//    (LegPosY[cLF]==(short)pgm_read_word(&cInitPosY[cLF]));
//
//  if (SelectedLeg<= (CNTLEGS-1)) {
//    if (SelectedLeg!=PrevSelectedLeg) {
//      if (AllDown) { //Lift leg a bit when it got selected
//        LegPosY[SelectedLeg] = (short)pgm_read_word(&cInitPosY[SelectedLeg])-20;
//
//        //Store current status
//        PrevSelectedLeg = SelectedLeg;
//      }
//      else {//Return prev leg back to the init position
//        LegPosX[PrevSelectedLeg] = (short)pgm_read_word(&cInitPosX[PrevSelectedLeg]);
//        LegPosY[PrevSelectedLeg] = (short)pgm_read_word(&cInitPosY[PrevSelectedLeg]);
//        LegPosZ[PrevSelectedLeg] = (short)pgm_read_word(&cInitPosZ[PrevSelectedLeg]);
//      }
//    }
//    else if (!fSLHold) {
//      //LegPosY[g_InControlState.SelectedLeg] = LegPosY[g_InControlState.SelectedLeg]+g_InControlState.SLLeg.y;
//      LegPosY[SelectedLeg] = (short)pgm_read_word(&cInitPosY[SelectedLeg])+SLLeg.y;// Using DIY remote Zenta prefer it this way
//      LegPosX[SelectedLeg] = (short)pgm_read_word(&cInitPosX[SelectedLeg])+SLLeg.x;
//      LegPosZ[SelectedLeg] = (short)pgm_read_word(&cInitPosZ[SelectedLeg])+SLLeg.z;
//    }
//  }
//  else {//All legs to init position
//    if (!AllDown) {
//      for(LegIndex = 0; LegIndex <= (CNTLEGS-1);LegIndex++) {
//        LegPosX[LegIndex] = (short)pgm_read_word(&cInitPosX[LegIndex]);
//        LegPosY[LegIndex] = (short)pgm_read_word(&cInitPosY[LegIndex]);
//        LegPosZ[LegIndex] = (short)pgm_read_word(&cInitPosZ[LegIndex]);
//      }
//    }
//    if (PrevSelectedLeg!=255)
//      PrevSelectedLeg = 255;
//  }
//#endif
//}
//
//
//void GaitSelect(void)
//{
//  //Gait selector
//  // First pass simply use defined table, next up will allow robots to add or relace set...
//  if (GaitType < NUM_GAITS) {
//
//    gaitCur = APG[GaitType];
//
//  }
//
//}
//
////--------------------------------------------------------------------
////[GAIT Sequence]
//void GaitSeq(void)
//{
//  //Check if the Gait is in motion - If not if we are going to start a motion try to align our Gaitstep to start with a good foot
//  // for the direction we are about to go...
//
////  if (fWalking || (ForceGaitStepCnt != 0))
////    TravelRequest = true;   // Is walking or was walking...
////  else {
////    TravelRequest = (abs(TravelLength.x)>cTravelDeadZone)
////        || (abs(TravelLength.z)>cTravelDeadZone)
////        || (abs(TravelLength.y)>cTravelDeadZone) ;
////
////    if (TravelRequest) {
////
////    }
////    else {    //Clear values under the cTravelDeadZone
////      TravelLength.x=0;
////      TravelLength.z=0;
////      TravelLength.y=0;//Gait NOT in motion, return to home position
////    }
////  }
//
//  //Calculate Gait sequence
//  for (LegIndex = 0; LegIndex < CNTLEGS; LegIndex++)
////  for (LegIndex = 0; LegIndex < 6; LegIndex++)
//  { // for all legs
//    Gait(LegIndex);
//  }    // next leg
//
//  //Advance to the next step
//  GaitStep++;
//  if (GaitStep>gaitCur.StepsInGait)
//    GaitStep = 1;
//
//  // If we have a force count decrement it now...
//  if (ForceGaitStepCnt)
//    ForceGaitStepCnt--;
//}
//
//
////--------------------------------------------------------------------
////[GAIT]
//void Gait (uint8_t GaitCurrentLegNr)
//{
//
//  // Try to reduce the number of time we look at GaitLegnr and Gaitstep
////  short int LegStep = GaitStep - gaitCur.GaitLegNr[GaitCurrentLegNr];
//	LegStep = GaitStep - gaitCur.GaitLegNr[GaitCurrentLegNr];
//
//  //Leg middle up position OK
//  //Gait in motion
//  // For Lifted pos = 1, 3, 5
//  if (( (gaitCur.NrLiftedPos&1) &&
//    LegStep==0) || (LegStep==0 && ((abs(GaitPosX[GaitCurrentLegNr])>2) ||
//    (abs(GaitPosZ[GaitCurrentLegNr])>2) || (abs(GaitRotY[GaitCurrentLegNr])>2)))) { //Up
//    GaitPosX[GaitCurrentLegNr] = 0;
//    GaitPosY[GaitCurrentLegNr] = -LegLiftHeight;
//    GaitPosZ[GaitCurrentLegNr] = 0;
//    GaitRotY[GaitCurrentLegNr] = 0;
//  }
//  //Optional Half heigth Rear (2, 3, 5 lifted positions)
//  else if ((gaitCur.NrLiftedPos==2 && LegStep==0) || (gaitCur.NrLiftedPos>=3 &&
//    (LegStep==-1 || LegStep==(gaitCur.StepsInGait-1)))) {
//    GaitPosX[GaitCurrentLegNr] = -TravelLength.x/gaitCur.LiftDivFactor;
//    GaitPosY[GaitCurrentLegNr] = -3*LegLiftHeight/(3+gaitCur.HalfLiftHeight);     //Easier to shift between div factor: /1 (3/3), /2 (3/6) and 3/4
//    GaitPosZ[GaitCurrentLegNr] = -TravelLength.z/gaitCur.LiftDivFactor;
//    GaitRotY[GaitCurrentLegNr] = -TravelLength.y/gaitCur.LiftDivFactor;
//  }
//  // _A_
//  // Optional Half heigth front (2, 3, 5 lifted positions)
//  else if ((gaitCur.NrLiftedPos>=2) && (LegStep==1 || LegStep==-(gaitCur.StepsInGait-1))) {
//    GaitPosX[GaitCurrentLegNr] = TravelLength.x/gaitCur.LiftDivFactor;
//    GaitPosY[GaitCurrentLegNr] = -3*LegLiftHeight/(3+gaitCur.HalfLiftHeight); // Easier to shift between div factor: /1 (3/3), /2 (3/6) and 3/4
//    GaitPosZ[GaitCurrentLegNr] = TravelLength.z/gaitCur.LiftDivFactor;
//    GaitRotY[GaitCurrentLegNr] = TravelLength.y/gaitCur.LiftDivFactor;
//  }
//
//  //Optional Half heigth Rear 5 LiftedPos (5 lifted positions)
//  else if (((gaitCur.NrLiftedPos==5 && (LegStep==-2 )))) {
//    GaitPosX[GaitCurrentLegNr] = -TravelLength.x/2;
//    GaitPosY[GaitCurrentLegNr] = -LegLiftHeight/2;
//    GaitPosZ[GaitCurrentLegNr] = -TravelLength.z/2;
//    GaitRotY[GaitCurrentLegNr] = -TravelLength.y/2;
//  }
//
//  //Optional Half heigth Front 5 LiftedPos (5 lifted positions)
//  else if ((gaitCur.NrLiftedPos==5) && (LegStep==2 || LegStep==-(gaitCur.StepsInGait-2))) {
//    GaitPosX[GaitCurrentLegNr] = TravelLength.x/2;
//    GaitPosY[GaitCurrentLegNr] = -LegLiftHeight/2;
//    GaitPosZ[GaitCurrentLegNr] = TravelLength.z/2;
//    GaitRotY[GaitCurrentLegNr] = TravelLength.y/2;
//  }
//  //_B_
//  //Leg front down position //bug here?  From _A_ to _B_ there should only be one gaitstep, not 2!
//  //For example, where is the case of LegStep==0+2 executed when NRLiftedPos=3?
//  else if ((LegStep==gaitCur.FrontDownPos || LegStep==-(gaitCur.StepsInGait-gaitCur.FrontDownPos)) && GaitPosY[GaitCurrentLegNr]<0) {
//    GaitPosX[GaitCurrentLegNr] = TravelLength.x/2;
//    GaitPosZ[GaitCurrentLegNr] = TravelLength.z/2;
//    GaitRotY[GaitCurrentLegNr] = TravelLength.y/2;
//    GaitPosY[GaitCurrentLegNr] = 0;
//  }
//
//  //Move body forward
//  else {
//    GaitPosX[GaitCurrentLegNr] = GaitPosX[GaitCurrentLegNr] - (TravelLength.x/(short)gaitCur.TLDivFactor);
//    GaitPosY[GaitCurrentLegNr] = 0;
//    GaitPosZ[GaitCurrentLegNr] = GaitPosZ[GaitCurrentLegNr] - (TravelLength.z/(short)gaitCur.TLDivFactor);
//    GaitRotY[GaitCurrentLegNr] = GaitRotY[GaitCurrentLegNr] - (TravelLength.y/(short)gaitCur.TLDivFactor);
//  }
//
//}
//
//
////--------------------------------------------------------------------
////[GETSINCOS] Get the sinus and cosinus from the angle +/- multiple circles
////AngleDeg1     - Input Angle in degrees
////sin4        - Output Sinus of AngleDeg
////cos4          - Output Cosinus of AngleDeg
//void GetSinCos(short AngleDeg1)
//{
//  short        ABSAngleDeg1;    //Absolute value of the Angle in Degrees, decimals = 1
//  //Get the absolute value of AngleDeg
//  if (AngleDeg1 < 0)
//    ABSAngleDeg1 = AngleDeg1 *-1;
//  else
//    ABSAngleDeg1 = AngleDeg1;
//
//  //Shift rotation to a full circle of 360 deg -> AngleDeg // 360
//  if (AngleDeg1 < 0)    //Negative values
//    AngleDeg1 = 3600-(ABSAngleDeg1-(3600*(ABSAngleDeg1/3600)));
//  else                //Positive values
//  AngleDeg1 = ABSAngleDeg1-(3600*(ABSAngleDeg1/3600));
//
//  if (AngleDeg1>=0 && AngleDeg1<=900)     // 0 to 90 deg
//  {
//    sin4 = pgm_read_word(&GetSin[AngleDeg1/5]);             // 5 is the presision (0.5) of the table
//    cos4 = pgm_read_word(&GetSin[(900-(AngleDeg1))/5]);
//  }
//
//  else if (AngleDeg1>900 && AngleDeg1<=1800)     // 90 to 180 deg
//  {
//    sin4 = pgm_read_word(&GetSin[(900-(AngleDeg1-900))/5]); // 5 is the presision (0.5) of the table
//    cos4 = -pgm_read_word(&GetSin[(AngleDeg1-900)/5]);
//  }
//  else if (AngleDeg1>1800 && AngleDeg1<=2700) // 180 to 270 deg
//  {
//    sin4 = -pgm_read_word(&GetSin[(AngleDeg1-1800)/5]);     // 5 is the presision (0.5) of the table
//    cos4 = -pgm_read_word(&GetSin[(2700-AngleDeg1)/5]);
//  }
//
//  else if(AngleDeg1>2700 && AngleDeg1<=3600) // 270 to 360 deg
//  {
//    sin4 = -pgm_read_word(&GetSin[(3600-AngleDeg1)/5]); // 5 is the presision (0.5) of the table
//    cos4 = pgm_read_word(&GetSin[(AngleDeg1-2700)/5]);
//  }
//}
//
//
////--------------------------------------------------------------------
////(GETARCCOS) Get the sinus and cosinus from the angle +/- multiple circles
////cos4        - Input Cosinus
////AngleRad4     - Output Angle in AngleRad4
//long GetArcCos(short cos4)
//{
//  bool NegativeValue/*:1*/;    //If the the value is Negative
//  //Check for negative value
//  if (cos4<0)
//  {
//    cos4 = -cos4;
//    NegativeValue = 1;
//  }
//  else
//    NegativeValue = 0;
//
//  //Limit cos4 to his maximal value
//  cos4 = fmin(cos4,c4DEC);
//
//  if ((cos4>=0) && (cos4<9000))
//  {
//    AngleRad4 = (uint8_t)pgm_read_byte(&GetACos[cos4/79]);
//    AngleRad4 = ((long)AngleRad4*616)/c1DEC;            //616=acos resolution (pi/2/255) ;
//  }
//  else if ((cos4>=9000) && (cos4<9900))
//  {
//    AngleRad4 = (uint8_t)pgm_read_byte(&GetACos[(cos4-9000)/8+114]);
//    AngleRad4 = (long)((long)AngleRad4*616)/c1DEC;             //616=acos resolution (pi/2/255)
//  }
//  else if ((cos4>=9900) && (cos4<=10000))
//  {
//    AngleRad4 = (uint8_t)pgm_read_byte(&GetACos[(cos4-9900)/2+227]);
//    AngleRad4 = (long)((long)AngleRad4*616)/c1DEC;             //616=acos resolution (pi/2/255)
//  }
//
//  //Add negative sign
//  if (NegativeValue)
//    AngleRad4 = 31416 - AngleRad4;
//
//  return AngleRad4;
//}
//
//unsigned long isqrt32 (unsigned long n) //
//{
//  unsigned long root;
//  unsigned long remainder;
//  unsigned long  place;
//
//  root = 0;
//  remainder = n;
//  place = 0x40000000; // OR place = 0x4000; OR place = 0x40; - respectively
//
//  while (place > remainder)
//    place = place >> 2;
//  while (place)
//  {
//    if (remainder >= root + place)
//    {
//      remainder = remainder - root - place;
//      root = root + (place << 1);
//    }
//    root = root >> 1;
//    place = place >> 2;
//  }
//  return root;
//}
//
//
////--------------------------------------------------------------------
////(GETATAN2) Simplyfied ArcTan2 function based on fixed point ArcCos
////ArcTanX         - Input X
////ArcTanY         - Input Y
////ArcTan4          - Output ARCTAN2(X/Y)
////XYhyp2            - Output presenting Hypotenuse of X and Y
//short GetATan2 (short AtanX, short AtanY)
//{
//  XYhyp2 = isqrt32(((long)AtanX*AtanX*c4DEC) + ((long)AtanY*AtanY*c4DEC));
//  GetArcCos (((long)AtanX*(long)c6DEC) /(long) XYhyp2);
//
//  if (AtanY < 0)                // removed overhead... Atan4 = AngleRad4 * (AtanY/abs(AtanY));
//    Atan4 = -AngleRad4;
//  else
//    Atan4 = AngleRad4;
//  return Atan4;
//}
//
////--------------------------------------------------------------------
////(BODY INVERSE KINEMATICS)
////BodyRotX         - Global Input pitch of the body
////BodyRotY         - Global Input rotation of the body
////BodyRotZ         - Global Input roll of the body
////RotationY         - Input Rotation for the gait
////PosX            - Input position of the feet X
////PosZ            - Input position of the feet Z
////SinB                  - Sin buffer for BodyRotX
////CosB               - Cos buffer for BodyRotX
////SinG                  - Sin buffer for BodyRotZ
////CosG               - Cos buffer for BodyRotZ
////BodyFKPosX         - Output Position X of feet with Rotation
////BodyFKPosY         - Output Position Y of feet with Rotation
////BodyFKPosZ         - Output Position Z of feet with Rotation
//void BodyFK (short PosX, short PosZ, short PosY, short RotationY, uint8_t BodyIKLeg)
//{
//  short            SinA4;          //Sin buffer for BodyRotX calculations
//  short            CosA4;          //Cos buffer for BodyRotX calculations
//  short            SinB4;          //Sin buffer for BodyRotX calculations
//  short            CosB4;          //Cos buffer for BodyRotX calculations
//  short            SinG4;          //Sin buffer for BodyRotZ calculations
//  short            CosG4;          //Cos buffer for BodyRotZ calculations
//  short             CPR_X;            //Final X value for centerpoint of rotation
//  short            CPR_Y;            //Final Y value for centerpoint of rotation
//  short            CPR_Z;            //Final Z value for centerpoint of rotation
//
//  //Calculating totals from center of the body to the feet
//  CPR_X = (short)pgm_read_word(&cOffsetX[BodyIKLeg])+PosX + BodyRotOffset.x;
//  CPR_Y = PosY + BodyRotOffset.y;         //Define centerpoint for rotation along the Y-axis
//  CPR_Z = (short)pgm_read_word(&cOffsetZ[BodyIKLeg]) + PosZ + BodyRotOffset.z;
//
//  //Successive global rotation matrix:
//  //Math shorts for rotation: Alfa [A] = Xrotate, Beta [B] = Zrotate, Gamma [G] = Yrotate
//  //Sinus Alfa = SinA, cosinus Alfa = cosA. and so on...
//
//  //First calculate sinus and cosinus for each rotation:
//  GetSinCos (BodyRot1.x+TotalXBal1);
//  SinG4 = sin4;
//  CosG4 = cos4;
//
//  GetSinCos (BodyRot1.z+TotalZBal1);
//  SinB4 = sin4;
//  CosB4 = cos4;
//
//
//  GetSinCos (BodyRot1.y+(RotationY*c1DEC)+TotalYBal1) ;
//
//  SinA4 = sin4;
//  CosA4 = cos4;
//
//  //Calcualtion of rotation matrix:
//  BodyFKPosX = ((long)CPR_X*c2DEC - ((long)CPR_X*c2DEC*CosA4/c4DEC*CosB4/c4DEC - (long)CPR_Z*c2DEC*CosB4/c4DEC*SinA4/c4DEC
//    + (long)CPR_Y*c2DEC*SinB4/c4DEC ))/c2DEC;
//  BodyFKPosZ = ((long)CPR_Z*c2DEC - ( (long)CPR_X*c2DEC*CosG4/c4DEC*SinA4/c4DEC + (long)CPR_X*c2DEC*CosA4/c4DEC*SinB4/c4DEC*SinG4/c4DEC
//    + (long)CPR_Z*c2DEC*CosA4/c4DEC*CosG4/c4DEC - (long)CPR_Z*c2DEC*SinA4/c4DEC*SinB4/c4DEC*SinG4/c4DEC
//    - (long)CPR_Y*c2DEC*CosB4/c4DEC*SinG4/c4DEC ))/c2DEC;
//  BodyFKPosY = ((long)CPR_Y  *c2DEC - ( (long)CPR_X*c2DEC*SinA4/c4DEC*SinG4/c4DEC - (long)CPR_X*c2DEC*CosA4/c4DEC*CosG4/c4DEC*SinB4/c4DEC
//    + (long)CPR_Z*c2DEC*CosA4/c4DEC*SinG4/c4DEC + (long)CPR_Z*c2DEC*CosG4/c4DEC*SinA4/c4DEC*SinB4/c4DEC
//    + (long)CPR_Y*c2DEC*CosB4/c4DEC*CosG4/c4DEC ))/c2DEC;
//}
//
//
//
////--------------------------------------------------------------------
////[LEG INVERSE KINEMATICS] Calculates the angles of the coxa, femur and tibia for the given position of the feet
////IKFeetPosX            - Input position of the Feet X
////IKFeetPosY            - Input position of the Feet Y
////IKFeetPosZ            - Input Position of the Feet Z
////IKSolution            - Output true if the solution is possible
////IKSolutionWarning     - Output true if the solution is NEARLY possible
////IKSolutionError    - Output true if the solution is NOT possible
////FemurAngle1           - Output Angle of Femur in degrees
////TibiaAngle1           - Output Angle of Tibia in degrees
////CoxaAngle1            - Output Angle of Coxa in degrees
////--------------------------------------------------------------------
//void LegIK (short IKFeetPosX, short IKFeetPosY, short IKFeetPosZ, uint8_t LegIKLegNr)
//{
//  unsigned long    IKSW2;            //Length between Shoulder and Wrist, decimals = 2
//  unsigned long    IKA14;            //Angle of the line S>W with respect to the ground in radians, decimals = 4
//  unsigned long    IKA24;            //Angle of the line S>W with respect to the femur in radians, decimals = 4
//  short            IKFeetPosXZ;    //Diagonal direction from Input X and Z
//
//#define TarsOffsetXZ 0      // Vector value
//#define TarsOffsetY  0      //Vector value / The 2 DOF IK calcs (femur and tibia) are based upon these vectors
//
//  long            Temp1;
//  long            Temp2;
//  long            T3;
//
//  //Calculate IKCoxaAngle and IKFeetPosXZ
//  GetATan2 (IKFeetPosX, IKFeetPosZ);
//  CoxaAngle1[LegIKLegNr] = (((long)Atan4*180) / 3141) + (short)pgm_read_word(&cCoxaAngle1[LegIKLegNr]);
//
//  //Length between the Coxa and tars [foot]
//  IKFeetPosXZ = XYhyp2/c2DEC;
//
//  //Using GetAtan2 for solving IKA1 and IKSW
//  //IKA14 - Angle between SW line and the ground in radians
//  IKA14 = GetATan2 (IKFeetPosY-TarsOffsetY, IKFeetPosXZ-(uint8_t)pgm_read_byte(&cCoxaLength[LegIKLegNr])-TarsOffsetXZ);
//
//  //IKSW2 - Length between femur axis and tars
//  IKSW2 = XYhyp2;
//
//  //IKA2 - Angle of the line S>W with respect to the femur in radians
//  Temp1 = ((((long)(uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr])*(uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr])) - ((long)(uint8_t)pgm_read_byte(&cTibiaLength[LegIKLegNr])*(uint8_t)pgm_read_byte(&cTibiaLength[LegIKLegNr])))*c4DEC + ((long)IKSW2*IKSW2));
//  Temp2 = (long)(2*(uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr]))*c2DEC * (unsigned long)IKSW2;
//  T3 = Temp1 / (Temp2/c4DEC);
//  IKA24 = GetArcCos (T3 );
//
//  //IKFemurAngle
//
//  FemurAngle1[LegIKLegNr] = -(long)(IKA14 + IKA24) * 180 / 3141 + 900 + CFEMURHORNOFFSET1(LegIKLegNr);//Normal
//
//
//  //IKTibiaAngle
//  Temp1 = ((((long)(uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr])*(uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr])) + ((long)(uint8_t)pgm_read_byte(&cTibiaLength[LegIKLegNr])*(uint8_t)pgm_read_byte(&cTibiaLength[LegIKLegNr])))*c4DEC - ((long)IKSW2*IKSW2));
//  Temp2 = 2 * ((long)((uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr]))) * (long)((uint8_t)pgm_read_byte(&cTibiaLength[LegIKLegNr]));
//  GetArcCos (Temp1 / Temp2);
//
//
//
//    TibiaAngle1[LegIKLegNr] = -(1800-(long)AngleRad4*180/3141 + CTIBIAHORNOFFSET1(LegIKLegNr));//Full range tibia, right side (up side up)
//
//
////  //Set the Solution quality
////  if(IKSW2 < ((uint16_t)((uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr])+(uint8_t)pgm_read_byte(&cTibiaLength[LegIKLegNr])-30)*c2DEC))
////    IKSolution = 1;
////  else
////  {
////    if(IKSW2 < ((uint16_t)((uint8_t)pgm_read_byte(&cFemurLength[LegIKLegNr])+(uint8_t)pgm_read_byte(&cTibiaLength[LegIKLegNr]))*c2DEC))
////      IKSolutionWarning = 1;
////    else
////      IKSolutionError = 1    ;
////  }
//
//}
//
////--------------------------------------------------------------------
////[CHECK ANGLES] Checks the mechanical limits of the servos
////--------------------------------------------------------------------
////#ifdef DEBUG
////short CheckServoAngleBounds(short sID,  short sVal, const short *sMin PROGMEM, const short *sMax PROGMEM) {
////#else
////short CheckServoAngleBounds(short sID __attribute__((unused)),  short sVal, const short *sMin PROGMEM, const short *sMax PROGMEM) {
////#endif
////    // Pull into simple function as so I can report errors on debug
////    // Note ID is bogus, but something to let me know which one.
////    short s = (short)pgm_read_word(sMin);
////    if (sVal < s) {
////
////        return s;
////    }
////
////    s = (short)pgm_read_word(sMax);
////    if (sVal > s) {
////
////        return s;
////    }
////    return sVal;
////
////}
//
////--------------------------------------------------------------------
////[CHECK ANGLES] Checks the mechanical limits of the servos
////--------------------------------------------------------------------
//void CheckAngles(void)
//{
//#ifndef SERVOS_DO_MINMAX
//  short s = 0;      // BUGBUG just some index so we can get a hint who errored out
//  for (LegIndex = 0; LegIndex < CNTLEGS; LegIndex++)
////  for (LegIndex = 0; LegIndex < 6; LegIndex++)
//  {
//    CoxaAngle1[LegIndex]  = CheckServoAngleBounds(s++, CoxaAngle1[LegIndex], &cCoxaMin1[LegIndex], &cCoxaMax1[LegIndex]);
//    FemurAngle1[LegIndex] = CheckServoAngleBounds(s++, FemurAngle1[LegIndex], &cFemurMin1[LegIndex], &cFemurMax1[LegIndex]);
//    TibiaAngle1[LegIndex] = CheckServoAngleBounds(s++, TibiaAngle1[LegIndex], &cTibiaMin1[LegIndex], &cTibiaMax1[LegIndex]);
//  }
//#endif
//}
//
//
////--------------------------------------------------------------------
//// SmoothControl (From Zenta) -  This function makes the body
////            rotation and translation much smoother
////--------------------------------------------------------------------
//short SmoothControl (short CtrlMoveInp, short CtrlMoveOut, uint8_t CtrlDivider)
//{
//
//  if (CtrlMoveOut < (CtrlMoveInp - 4))
//    return CtrlMoveOut + abs((CtrlMoveOut - CtrlMoveInp)/CtrlDivider);
//  else if (CtrlMoveOut > (CtrlMoveInp + 4))
//    return CtrlMoveOut - abs((CtrlMoveOut - CtrlMoveInp)/CtrlDivider);
//
//  return CtrlMoveInp;
//}
//
//
////--------------------------------------------------------------------
//// GetLegsXZLength -
////--------------------------------------------------------------------
//uint16_t g_wLegsXZLength = 0xffff;
//uint16_t GetLegsXZLength(void)
//{
//    // Could save away or could do a little math on one leg...
//    if (g_wLegsXZLength != 0xffff)
//        return g_wLegsXZLength;
//
//    return isqrt32((LegPosX[0] * LegPosX[0]) + (LegPosZ[0] * LegPosZ[0]));
//}
//
//
////--------------------------------------------------------------------
//// AdjustLegPositions() - Will adjust the init leg positions to the
////      width passed in.
////--------------------------------------------------------------------
//#ifndef MIN_XZ_LEG_ADJUST
//#define MIN_XZ_LEG_ADJUST (cCoxaLength[0])      // don't go inside coxa...
//#endif
//
//#ifndef MAX_XZ_LEG_ADJUST
//#define MAX_XZ_LEG_ADJUST   (uint16_t)(cCoxaLength[0]+cTibiaLength[0] + cFemurLength[0]/4)
//#endif
//
//void AdjustLegPositions(uint16_t XZLength1)
//{
//	uint8_t LegIndex;
//
//    //now lets see what happens when we change the leg positions...
//    if (XZLength1 > MAX_XZ_LEG_ADJUST)
//        XZLength1 = MAX_XZ_LEG_ADJUST;
//    if (XZLength1 < MIN_XZ_LEG_ADJUST)
//        XZLength1 = MIN_XZ_LEG_ADJUST;
//
//    // see if same length as when we came in
//    if (XZLength1 == g_wLegsXZLength)
//        return;
//
//    g_wLegsXZLength = XZLength1;
//
//
//    for (LegIndex = 0; LegIndex < CNTLEGS; LegIndex++)
////    for (LegIndex = 0; LegIndex < 6; LegIndex++)
//    {
//
//#ifdef OPT_DYNAMIC_ADJUST_LEGS
//      GetSinCos(g_InControlState.aCoxaInitAngle1[LegIndex]);
//#else
//#ifdef cRRInitCoxaAngle1    // We can set different angles for the legs than just where they servo horns are set...
//      GetSinCos((short)pgm_read_word(&cCoxaInitAngle1[LegIndex]));
//#else
//      GetSinCos((short)pgm_read_word(&cCoxaAngle1[LegIndex]));
//#endif
//#endif
//      LegPosX[LegIndex] = ((long)((long)cos4 * XZLength1))/c4DEC;  //Set start positions for each leg
//      LegPosZ[LegIndex] = -((long)((long)sin4 * XZLength1))/c4DEC;
//
//    }
//
//    // Make sure we cycle through one gait to have the legs all move into their new locations...
//    ForceGaitStepCnt = gaitCur.StepsInGait;
//}
//
////--------------------------------------------------------------------
//// ResetLegInitAngles - This is used when we allow the user to
//// adjust the leg position angles.  This resets to what it was when the
//// the program was started.
////--------------------------------------------------------------------
//void ResetLegInitAngles(void)
//{
//#ifdef OPT_DYNAMIC_ADJUST_LEGS
//    for (int LegIndex=0; LegIndex < CNTLEGS; LegIndex++) {
//#ifdef cRRInitCoxaAngle1    // We can set different angles for the legs than just where they servo horns are set...
//            aCoxaInitAngle1[LegIndex] = (short)pgm_read_word(&cCoxaInitAngle1[LegIndex]);
//#else
//            aCoxaInitAngle1[LegIndex] = (short)pgm_read_word(&cCoxaAngle1[LegIndex]);
//#endif
//    }
//    g_wLegsXZLength = 0xffff;
//#endif
//}
//
////--------------------------------------------------------------------
//// ResetLegInitAngles - This is used when we allow the user to
////--------------------------------------------------------------------
//void RotateLegInitAngles (int iDeltaAngle)
//{
//#ifdef OPT_DYNAMIC_ADJUST_LEGS
//    for (int LegIndex=0; LegIndex < CNTLEGS; LegIndex++) {
//        // We will use the cCoxaAngle1 array to know which direction the legs logically are
//        // If the initial angle is 0 don't mess with.  Hex middle legs...
//        if ((short)pgm_read_word(&cCoxaAngle1[LegIndex]) > 0)
//            aCoxaInitAngle1[LegIndex] += iDeltaAngle;
//         else if ((short)pgm_read_word(&cCoxaAngle1[LegIndex]) < 0)
//            aCoxaInitAngle1[LegIndex] -= iDeltaAngle;
//
//        // Make sure we don't exceed some min/max angles.
//        // Right now hard coded to +-70 degrees... Should probably load
//        if (aCoxaInitAngle1[LegIndex] > 700)
//            aCoxaInitAngle1[LegIndex] = 700;
//        else if (aCoxaInitAngle1[LegIndex] < -700)
//            aCoxaInitAngle1[LegIndex] = -700;
//    }
//    g_wLegsXZLength = 0xffff;
//#else
//   iDeltaAngle++;   // remove unused warning...
//#endif
//}
//
//
////--------------------------------------------------------------------
//// AdjustLegPositionsToBodyHeight() - Will try to adjust the position of the legs
////     to be appropriate for the current y location of the body...
////--------------------------------------------------------------------
//
//uint8_t g_iLegInitIndex = 0x00;    // remember which index we are currently using...
//
//void AdjustLegPositionsToBodyHeight()
//{
//#ifdef CNT_HEX_INITS
//  // Lets see which of our units we should use...
//  // Note: We will also limit our body height here...
//  if (BodyPos.y > (short)pgm_read_byte(&g_abHexMaxBodyY[CNT_HEX_INITS-1]))
//    BodyPos.y =  (short)pgm_read_byte(&g_abHexMaxBodyY[CNT_HEX_INITS-1]);
//
//  uint8_t i;
//  uint16_t XZLength1 = pgm_read_byte(&g_abHexIntXZ[CNT_HEX_INITS-1]);
//  for(i = 0; i < (CNT_HEX_INITS-1); i++) {    // Don't need to look at last entry as we already init to assume this one...
//    if (BodyPos.y <= (short)pgm_read_byte(&g_abHexMaxBodyY[i])) {
//      XZLength1 = pgm_read_byte(&g_abHexIntXZ[i]);
//      break;
//    }
//  }
//  if (i != g_iLegInitIndex) {
//    g_iLegInitIndex = i;  // remember the current index...
//
//    // Call off to helper function to do the work.
//
//    AdjustLegPositions(XZLength1);
//  }
//#endif // CNT_HEX_INITS
//
//}
//
//
////#endif
//
//
//
