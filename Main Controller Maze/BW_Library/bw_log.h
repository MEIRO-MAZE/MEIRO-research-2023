/*===========================================================================================================================*
*===========================================================================================================================*
								 PROJECT Bhatara Wijaya 3.17 Ver.1.0
								  	Bhatara Wijaya Progress Logs
@Author  : BW Programmer Team
		   	   Ryan		(Batch 2013)
		   	   Hafidin	(Batch 2014)
		   	   Bertoni	(Batch 2015)
@Company : Brawijaya University Robotics Team
@Division: Intelligent Fire-Fighting Robot Division
@Team    : Project Bhatara Wijaya (Legged Robot Sub-Division)
@E-mail	 : krpai.jte.ub@gmail.com
@Version : ALPHA RELEASE (ON PROGRESS)
@IDE	 : CooCox IDE 1.7.8

<================= UPDATE LOGS

<=== Version 1.0
@Date:


<=== Version 2.0
@Date:

<================= LIBRARY DEPENDENCIES

<================= BRIEFS

*===========================================================================================================================*
============================================================================================================================*/



/*
 * YUME 2016 LOG
 *
 * =============================================================================================
 * Thursday, November 26th 2015
 * =============================================================================================
 * Problems
 * fungsi banyak yang stuck di satu titik, program masih jalan tapi hanya routine Evade_Wall()
 * yang terus menerus dilakukan alur program bermasalah
 *
 * Solution
 * kesalahan ada ketika robot mendeteksi cat obstacle, nilai CAT_FOUND[PREVIOUS]
 * dan CAT_FOUND[PRESENT] selalu berbeda, oleh karena itu program follow selalu dilewati
 *
 * Progress
 * memperbaiki alur program memakan waktu satu hari kerja,
 * HALLWAY SC -> detect cat obstacle -> ROOM 4 -> ROOM 1 (EXTINGUISH FIRE)
 * -> ROOM 3 (EXTINGUISH FIRE)
 *
 *
 *
 * =============================================================================================
 * Friday, November 27th 2015
 * =============================================================================================
 *
 * Problems
 * fungsi di depan pintu ROOM 1 masih kurang konsisten, peralihan dari berputar hingga follow
 * sering membuat robot berputar arah
 * kondisi khusus ketika di depan ROOM 1 variable ROOM_COUNTER bernilai <=2 juga sering losses
 * menyebabkan algoritma yang terpakai adalah konfigurasi biasa (robot berputar-putar antara
 * ROOM 1 -> ROOM 3, dan seterusnya
 *
 *
 * Progress
 * YUME mematikan 3 lilin
 * START HALLWAY SC -> detect CAT OBSTACLE -> ROOM 4 -> ROOM 1 (EXTINGUISH FIRE)
 * -> ROOM 3 (EXTINGUISH FIRE) -> CROSSING THE BORDERLINE -> RETURN TO BLUE ZONE
 * -> WARZONE (EXTINGUISH FIRE)
 *
 * START ROOM 4 -> ROOM 1 (EXTINGUISH FIRE) -> ROOM 3 (EXTINGUISH FIRE)
 * -> CROSSING THE BORDERLINE -> RETURN TO BLUE ZONE -> WARZONE (EXTINGUISH FIRE)
 *
 *
 *
 *
 * =============================================================================================
 * Tuesday, December 1st 2015
 * =============================================================================================
 *
 * Problems
 * Jalur untuk TPA81 bermasalah
 * FRONT TCS3200 bermasalah (nilai RED dan BLUE selalu sama, namun WHITE sudah benar)
 *
 *
 * Progress
 * 1. Algoritma crossing dari ROOM 3 (ruang pertama) ke borderline, lalu matikan lilin di warzone
 * 2. Bongkar robot, pasang mekanika body tengah dan bumper baru
 * 3. Pasang+troubleshoot board cadangan (Buzzer sekarang sudah bisa)
 *
 *
 * =============================================================================================
 * Wednesday, December 2nd 2015
 * =============================================================================================
 *
 * Problems
 * FRONT TCS3200 masih bermasalah (nilai RED dan BLUE selalu sama, namun WHITE sudah benar)
 * mekanika lama tidak sesuai dengan algoritma, bumper bagian depan sering menyangkut dinding
 * dan furniture, titik buta bertambah di bagian depan
 *
 * Progress
 * Konversi algoritma terbaru untuk RED_ZONE (tetapi belum diuji coba)
 * jalur TPA81 yang bermasalah di board baru sudah ditangani (overtime siang hari)
 * FRONT TCS3200 sudah diperbaiki
 *
 *
 * =============================================================================================
 *						December 3rd 2015 - January 31st 2016
 * 									MISSING JOURNAL
 *
 * Long story short, YUME win the Internal Battle against Semut Subuh
 * winning by points alone (YUME -1 vs Semut Subuh -5)
 * with neither of them able to extinguish the fire
 * =============================================================================================
 *
 *
 * =============================================================================================
 * 									PROJECT YUME 2.16
 * 									ROAD TO KRPAI 2016
 *
 * =============================================================================================
 *
 * =============================================================================================
 * Monday, Ferbruary 1st 2016
 * =============================================================================================
 *
 * PROGRESS SO FAR...
 *
 * PINOUT MAPPING (FULL)
 *
 * SOFTWARES:
 * Ryan:
 * 		Revising I2C Communication Library (solved the 'stuck' program when I2C Device disconnected)
 * 		Add feature in I2C Communication Library, ReadMultiByte & WriteMultiByte
 * 		MPU6050 IMU Sensor interfacing, get Pitch & Roll Angle with complementary filter
 * 		CMPS-11 Magnetic Compass Sensor (All Features)
 * 			1. 	CMPS-11 Calibration
 * 			2. 	Pitch & Roll Angle with Kalman Filter
 * 			4. 	Pitch & Roll Angle without Kalman Filter
 * 			5. 	Compass Bearing 8 Bit
 * 			6. 	Compass Bearing 16 Bit
 * 			7. 	Magnetometer Raw Data
 * 			8. 	Accelerometer Raw Data
 * 			9. 	Gyroscope Raw Data
 * 			10. Temperature Raw Data (Hardly accurate? or is it the chip temperature? because it always shows over 90 degrees Celcius
 * 			11. Complementary filter for Pitch & Roll Angle
 *
 * Hafidin:
 * 		TCS3200 interfacing on the AVR ATMega chip
 * 		Progress on working the grey-black-white floor rule, auto calibration & communication
 *
 * 	ELECTRONICS
 * 	Oky:
 * 		Flame Sensor slave (soldering...)
 * 		Extinguisher Driver (tested)
 * 		Main controller board (2 stack, printing...)
 *
 * 	Abdan:
 * 		TCS3200 Slave (designing)
 *
 * 	MECHANICALS
 *
 *	Ekky & Meilan:
 *		Robot Changes 3 times
 *			1. YUME with forklift mechanism
 *			2. YUME with planar arm mechanism
 *			3. YUME without arm mechanism (USED)
 *		Handle bar from aluminium alloy (requiring some finishing works)
 *		Upper base from aluminium alloy (requiring some finishing works)
 *		Planar arm prototype from aluminium alloy (but not used in the national rule)
 *		bumper from acrylic sheet (printing...)
 *		ping))) bracket from acrylic sheet (printing...)
 *		LS bumper (prototype)
 *
 *
 * =============================================================================================
 * Tuesday, Ferbruary 2nd 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 * 		idle
 *
 * Hafidin:
 * 		Working on TCS3200 slave program

 * 	ELECTRONICS
 * 	Oky:
 * 		Desoldering Parallax Ping)))  & change default header to straight one
 *
 * 	Abdan:
 *		Working on user button and led indicator board
 *
 * 	MECHANICALS
 *
 *	Ekky & Meilan:
 * 		Assembly of bumper, upper base, & handle bar
 *
 * =============================================================================================
 * Wednesday, Ferbruary 2nd 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 * 		TCS3200 Rule for distinguishing Gray carpet, black floor, and white lines (on STM32)
 *
 * Hafidin:
 * 		Still working on TCS3200 slave program

 * 	ELECTRONICS
 * 	Oky:
 * 		Soldering IR Proximity switch
 *
 * 	Abdan:
 *		*Absent (HIGH SCHOOL REUNION)
 *
 * 	MECHANICALS
 *
 *	Ekky & Meilan:
 *		Assembly of ping))) bracket
 *		Extinguisher bracket
 *
 * TROUBLES
 * 		FRONT TCS3200 cables seems not connected properly, thus data can't be read
 *
 * =============================================================================================
 * Thursday, Ferbruary 3rd 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 * 		idle
 *
 * Hafidin:
 * 		Still working on TCS3200 slave program

 * 	ELECTRONICS
 * 	Oky:
 * 		Assembling sound receiver & driver extinguisher
 * 		TROUBLE FOUND: output 3v dari pin D.12 (BLDC) tidak mencukupi, harus di pullup (sedangkan PD12 tidak bisa di pull-up)
 * 		SOLUTION     : pin trigger extinguisher diganti jadi PB15 (TPA Servo)
 *
 * 	Abdan:
 *		soldering pump
 *		unsoldering board YUME lama
 *
 * 	MECHANICALS
 *
 *	Ekky & Meilan:
 *		Revising extinguisher bracket
 *
 * =============================================================================================
 * Friday, February 4th 2016
 * =============================================================================================
 *
 * Missing Log
 *
 * =============================================================================================
 * Saturday, February 5th 2016
 * =============================================================================================
 *
 * Progress Log:
 *
 * 1. Persiapan untuk demo di tryout SBMPTN UB
 * 2. extinguisher Pompa air berhasil dipasang (modifikasi pompa air lama)
 *
 * =============================================================================================
 * Sunday, February 6th 2016
 * =============================================================================================
 *
 * *ABSENT, SICK LEAVE
 *
 * =============================================================================================
 * Monday, February 7th 2016
 * =============================================================================================
 *
 * *ABSENT, SICK LEAVE
 *

 * =============================================================================================
 * Tuesday, February 8th 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 * 		Trial A (non arbitrary start) Video Take
 *
 * Hafidin:
 * 		Absent

 * 	ELECTRONICS
 * 	Oky:
 * 		Soldering main controller board
 * 		Maintenance
 *
 * 	Abdan:
 *		Absent
 *
 * 	MECHANICALS
 *
 *	Ekky & Meilan:
 * 		Maintenance
 *
 * =============================================================================================
 * Wednesday, Ferbruary 9th 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 * 		Trial B (Arbitrary Start) Video Take
 *
 * Hafidin:
 * 		Absent

 * 	ELECTRONICS
 * 	Oky:
 * 		Soldering main controller board (FINISHED)
 * 		Maintenance
 *
 * 	Abdan:
 *		Soldering flame sensor (
 *
 * 	MECHANICALS
 *
 *	Ekky & Meilan:
 *		Maintenance
 *
 * TROUBLES
 * 		Video Trial B terlalu lama (4 menit) dan sempat tersangkut
 * 		UV-Tron tidak mendeteksi keberadaan api sama sekali, jauh maupun dekat
 * 		sepertinya lembab atau terpercik air
 *
 * =============================================================================================
 * Thursday, Ferbruary 11st 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *
 *
 * Hafidin:
 * 		Absent

 * 	ELECTRONICS
 * 	Oky:
 * 		Perbaiki UV-Tron
 *
 * 	Abdan:
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *	 	ABSENT
 *
 *	Meilan:
 *
 *
 * SOLUTION
 * 		shielding UV-TRON dilepas, bohlam UV dibersihkan, board driver dibersihkan dengan kuas
 * 		UV-TRON kembali normal setelah dibersihkan
 *
 * =============================================================================================
 * ===================================MISSING JOURNAL===========================================
 * PROGRESS SO FAR...
 * YUME Video Trailer
 * New Tibia Design
 * Painting Upper Base and Handle Bar Aluminium
 *
 *
 *
 * =============================================================================================
 *
 *
 *
 * =============================================================================================
 * Wednesday, February 24th 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *		Troubleshooting new main controller board
 *
 * Hafidin:
 * 		Absent

 * 	ELECTRONICS
 * 	Oky:
 * 		Troubleshooting new main controller board
 *
 * 	Abdan:
 * 		Absent
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *		Fabricating new tibia design from aluminium
 *
 *	Meilan:
 *		Fabricating new tibia design from aluminium
 *
 *  ===YUME 2016 MAIN CONTROLLER BOARD TROUBLESHOOTING===
 *  TESTED SO FAR...
 *  Hexapod Servo
 *  ALL USART (trouble in vcc)
 *  ALL I2C (I2C3 Can only be used in 250 kHz maximum)
 *  Rangefinder controller & Ping)))
 *  Buzzer
 *  LCD
 *  INFRARED PROXIMITY SWITCH
 *  LIMIT SWITCH BUMPER
 *  Pan Servo TPA81 (PB15)
 *
 *
 *  TROUBLE FOUND:
 *  Pan Servo CMUCAM5 -> (PD12, TIM4 CH1) -> Suplai power ada, tapi output PD12 0 v
 *  Apakah ada kesalahan program?
 *  test jalur secara elektrik tidak ada masalah
 *  ketika servo disambungkan langsung ke STM32, hasilnya sama, servo tidak menerima sinyal
 *
 *
 *
 * =============================================================================================
 * Thursday, February 25th 2016
 * =============================================================================================
 *
 *	PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *		Troubleshooting IR based flame sensor
 *		Flame tracking with IR based flame sensor (ON/OFF Controller)
 *
 * Hafidin:
 * 		Researching I2C LCD, trying to figuring out HAL LCD Driver
 *
 * 	ELECTRONICS
 * 	Oky:
 * 		Troubleshooting IR based flame sensor
 *
 * 	Abdan:
 * 		Absent
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *		Fabricating new tibia design from aluminium
 *
 *	Meilan:
 *		Fabricating new tibia design from aluminium
 *
 *
 * =============================================================================================
 * Friday, February 26th 2016
 * =============================================================================================
 * PROJECT YUME 2016 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL!
 *
 *
 * PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *		Flame tracking with IR based flame sensor (PID Controller)
 *
 * Hafidin:
 * 		Researching I2C LCD, trying to figuring out HAL LCD Driver
 * 		Trying I2C LCD on Arduino
 *
 * 	ELECTRONICS
 * 	Oky:
 * 		Fixing IR Based Flame Sensor
 *
 * 	Abdan:
 * 		Researching Bandpass Filter
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *		Fabricating new tibia design from aluminium
 *		Applying newly printed bumper
 *		Testing new tibia design
 *
 *	Meilan:
 *		Fabricating new tibia design from aluminium
 *		Applying newly printed bumper
 *		Testing new tibia design
 *
 *
 * =============================================================================================
 * 								SOME NOTES MISSING
 * PROGRESS SO FAR...
 * SOFTWARES:
 * 				Flame Following algorithm with PID Controller
 *
 * ELECTRONICS:
 * 				Soldering TCS3200 Controller (on progress)
 * 				Soldering Button Board (on progress)
 *
 * MECHANICALS:
 * 				Fabricating Limit Switch Based Bumper
 *
 *
 *
 * =============================================================================================
 *
 *
 * =============================================================================================
 * Friday, March 4th 2016
 * =============================================================================================
 * PROJECT YUME 2016 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL!
 *
 *
 * PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *
 *
 * Hafidin:
 * 		Researching I2C LCD
 *
 * 	ELECTRONICS
 * 	Oky:
 * 		Soldering TCS3200 Controller and Button Board
 *
 * 	Abdan:
 * 		Researching Bandpass Filter
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *		Finishing New Tibia
 *
 *	Meilan:
 *		Finishing New Tibia
 *
 *
 *
 * =============================================================================================
 * 								SOME NOTES MISSING
 * PROGRESS SO FAR...
 * SOFTWARES:
 * 				TCS3200 ATMEGA8 INTERFACING
 * 				TCS3200 ATMEGA8 SLAVE <-> STM32 MAIN CONTROLLER MAIN MENU COMMUNICATION
 * 				CONTACT BUMPER INTERFACING
 *
 * ELECTRONICS:
 * 				DESIGN TS3200 SLAVE (NEW) -> REVISION
 *
 * MECHANICALS:
 * 				EXTINGUISHER BRACKET
 *
 * =============================================================================================
 *
 *
 * =============================================================================================
 * Saturday, March 12nd 2016
 * =============================================================================================
 * PROJECT YUME 2016 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL!
 *
 *
 * PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *			TCS3200 ATMEGA8 SLAVE <-> STM32 MAIN CONTROLLER MAIN MENU COMMUNICATION
 *			RAW SCRATCH FOR TCS3200 AUTOCALIBRATION
 *
 * Hafidin:
 * 			Researching I2C LCD
 *
 * 	ELECTRONICS
 * 	Oky:
 * 			WIRING & MAINTENANCE
 *
 * 	Abdan:
 * 			Researching Bandpass Filter
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *			EXTINGUISHER BRACKET
 *
 *	Meilan:
 *
 *
 *	TROUBLES FOUND:
 *					1. PIN BUMPER PA.6 selalu logika 1. ketika dicek dengan multimeter,
 *					   tegangan selalu 2,5 Volt
 *					2. Pin Extinguisher perlu pull-up dan PE.1 tidak bisa di pull-up
 *
 *	SOLUTION FOUND:
 *					1. Pin bumper ganti jadi pin piezoelectric PC.1 dan PC.2
 *					2. Pin extinguisher diganti jadi pin PB.15, (pin TPA Servo)
 *
 *
 * =============================================================================================
 * Monday, March 14th 2016
 * =============================================================================================
 * PROJECT YUME 2016 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL!
 *
 *
 * PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *
 *
 * Hafidin:
 *
 *
 * 	ELECTRONICS
 * 	Oky:
 * 			Fixing DC Micropump
 *
 * 	Abdan:
 * 			*Absent, away on Kediri
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *			Fixing DC Micropump
 *
 *	Meilan:
 *			Painting new Hallway (arena)
 *
 *	TROUBLES FOUND:
 *					1. Tiba-tiba DC micropump tidak bisa menyala, namun board driver
 *					   Optocoupler bekerja normal
 *
 *	SOLUTION FOUND:
 *					1. 	Ternyata sikat dari motor DC hangus terbakar, tidak kuat diberi
 *						tegangan 12 Volt (specs aslinya 5 Volt).Sehingga perlu kanibal
 *						sikat dari motor DC cadangan, mekanika micropump masih tetap dipakai.
 *
 *
 * =============================================================================================
 * Friday, March 18th 2016
 * =============================================================================================
 * PROJECT YUME 2016 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL!
 *
 *
 * PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *
 *
 * Hafidin:
 *
 *
 * 	ELECTRONICS
 * 	Oky:
 *
 *
 * 	Abdan:
 *
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *
 *
 *	Meilan:
 *
 *
 *	TROUBLES FOUND:
 *					1. Slave TCS3200 data keluarannya selalu nol, baik di middle maupun di front
 *
 *	SOLUTION FOUND:
 *					1. jalur tcs3200 ada yang tidak tersambung, di front, pin OE (PC5 tidak tersambung)
 *						sedangkan di middle pin OE (PD5 tidak tersambung)
 *					2. Pin SPI harus dikosongi!
 *
 *
 * =============================================================================================
 * 										SOME NOTES MISSING
 * PROGRESS SO FAR...
 * SOFTWARES:
 * 				YUME NAVIGATION ALL ROUTE (MINUS ALL ROOM TO HALLWAY_SC)
 * 				YUME FOLLOWHOME
 * 				YUME STRATEGY BEHAVIOUR BASED SYSTEM ON ARBITRARY START
 * 				YUME RETURN TRIP ALGORITHM
 *
 *
 * ELECTRONICS:
 * 				IR BASED FLAME SENSOR VERSION 2
 * 				ON PROGRESS: REVISING TCS3200 BOARD AND MAKING SPARE ELECTRONICS BOARD
 *
 * MECHANICALS:
 * 				TIBIA COVER
 * 				ADD-ON CARRYING HANDLE
 * 				MAINTENANCE
 *
 * =============================================================================================
 *
 * =============================================================================================
 * Friday, April 1st 2016
 * =============================================================================================
 * PROJECT YUME 2016 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL!
 *
 *
 * PROGRESS SO FAR...
 * SOFTWARES:
 * Ryan:
 *
 *
 * Hafidin:
 *
 *
 * 	ELECTRONICS
 * 	Oky:
 *
 *
 * 	Abdan:
 *
 *
 *
 * 	MECHANICALS
 *
 *	Ekky:
 *
 *
 *	Meilan:
 *
 *
 *	TROUBLES FOUND:
 *					1. penambahan algoritma pengenalan home membuat followtracer bermasalah
 *						robot salah persepsi antara garis ruang dan home circle. kemudian
 *						robot berhenti dan sinyal kontrol servo bermasalah
 *
 *	SOLUTION FOUND:
 *
 *
 * =============================================================================================
 * 										SOME NOTES MISSING
 * PROJECT YUME 2016 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL!
 *
 * PROGRESS SO FAR... (Wednesday, April 6th 2016) H-28 KRPAI REGIONAL 4
 *
 * SOFTWARES:
 * 				YUME Trial algorithm
 * 				YUME home = Room 2, FIRE = Room 1, extinguish fire, and return trip
 * 				Fixing bugs in navigation (Room 2 <-> Room 1)
 * 				YUME FireFight Algorithm
 * 					* without furniture -> 90% (GOOD)
 * 					* with furniture    -> 80% (DECENT, with few bugs and error)
 * 				TCS3200 Slave data -> DECENT, with few bugs (but difficult calibration process)
 *
 * ELECTRONICS:
 * 				Waiting for new PCB
 *
 * MECHANICALS:
 * 				New tibia cover
 * 				Peletakan TCS3200 processor ditaruh dibawah base
 *
 * TROUBLES FOUND:
 * 					Proses kalibrasi TCS3200 LAMA
 * 					FollowTracer routine kadang error (garis putih terlewat)
 * 					YUME_FireFight routine kadang error
 * 					Servo tibia kiri belakang (HS-7954SH) BERMASALAH GEARNYA
 * 					ganti pakai servo HS-5645MG hasil kanibal servo (ekspektasi umur servo rendah?)
 *
 * =============================================================================================
 *
 *
 * =============================================================================================
 * 										SOME NOTES MISSING
 * 	END OF PROJECT YUME 2016
 * =============================================================================================
 *
 *
 *
 *
 * =============================================================================================
 * 								    PROJECT BHATARA WIJAYA 2017
 * =============================================================================================
 *
 *
 * ==================================================================================================
 * PROJECT BHATARA WIJAYA 2017 - JUARA REGIONAL! LOLOS NASIONAL! JUARA NASIONAL! JUARA INTERNASIONAL!
 * <========= Wednesday, January 25th 2017 ===
 *
 * <=== What's New!?
 *
 * SOFTWARES:
 * 				1. Dynamixel Config, centering, etc.
 *
 *
 * ELECTRONICS:
 *
 *
 *
 * MECHANICALS:
 * 				2. Dynamixel Hexapod mechanical
 *
 *
 * TROUBLES AND SOLUTIONS:
 *
 *
 * ==================================================================================================
 */
