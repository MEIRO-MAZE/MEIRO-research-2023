# MEIRO – Autonomous Hexapod SAR Robot  
**KRSRI 2023 Edition**  
*Standarized Documentation of Research (SDR)*

---

## 📘 About the Research

- **Team / Division:** MEIRO  
- **Platform:** STM32  
- **Timeline:** 09 Aug 2022 – 24 Oct 2023  
- **Status:** ✅ Completed  

---

## 📚 Background

Search-and-Rescue (SAR) operations in disaster areas are often constrained by:

- **Hazardous terrain** (rubble, stairs, uneven surfaces) that is inaccessible to wheeled robots.  
- **Poor visibility & communication** after earthquakes or building collapses.  
- **Time-critical missions** where every minute reduces victim survival rates.

Post-earthquake environments are characterised by:

- **Non-flat terrain:** cracked floors, scattered debris, loose gravel (simulated by 3–5 cm white coral & 15 – 17 mm marbles).  
- **Slopes & stairs:** inclines up to 50 cm vertical in 90 cm horizontal.  
- **Victim localisation：** 5 orange-coloured 3-D printed victims (≈ 33 g each) randomly placed, no dummy in 2023.  

This research was conducted to design an **autonomous hexapod robot** capable of:

1. Traversing complex indoor environments without human intervention.  
2. Detecting and localizing **heat-emitting victims** via on-board sensors.  
3. Streaming **environmental & victim data** back to base for further rescue action.

The outcome directly contributes to the advancement of **legged robotics for real-world SAR tasks** and strengthens Indonesia’s participation in the **Kontes Robot SAR Indonesia (KRSRI) 2023**.

---

## 🎯 Objectives

| General Objectives | Specific Milestones |
|--------------------|---------------------|
| Build a fully autonomous hexapod that can map, navigate, and locate victims in a mock disaster arena. | • Finish mechanical design & gait generation by Nov 2022. |
| Achieve reliable victim detection and classification using low-cost sensors. | • Integrate CMPS11 + PING + TCS3200 suite by Dec 2022. |
| Finish top-3 placement in KRSRI 2023. | • Complete full mission runs ≥ 5× without human touch by Sep 2023. |

---

## 📁 Repository Structure

```
📦 MEIRO-research-2023    
├── 📂 Main Controller Maze    → Main Controller
│   ├── 📂 MEIRO_Library       → Inverse Kinematic, Gait, Navigation, PID, etc
│   ├── 📂 cmsis               → STM32 CMSIS core & DSP
│   ├── 📂 logs                → Flash-backed run-time logs
│   ├── 📂 syscalls            → Newlib system-call stubs
│   └── 📄 main.c              → Main Program
├── 📂 Rangefinder Maze        → Rangefinder Library
│   ├── 📂 Rangefinder_SYSLIB  →
│   ├── 📂 Rangefinder_SYSTEM  →
│   ├── 📂 cmsis               → 
│   ├── 📂 logs                → 
│   ├── 📂 syscalls            →
│   └── 📄 main.c              → 
├── 📂 Tracer Gripper Maze     → Tracer Library
│   ├── 📂 Tracer Library      →
│   ├── 📂 cmsis               → 
│   ├── 📂 logs                → 
│   ├── 📂 syscalls            →
│   └── 📄 main.c              → 
└── 📜 README.md               → SDR
```

---

## 🔬 Methodology

| Component | Description | Version / Model |
|-----------|-------------|-----------------|
| **MCU** | STM32F407VGT6 | STM32CubeMX 6.8.0 |
| **Actuators** | 18× Dynamixel AX-12A | Firmware v41 |
| **Power** | • 2× Li-Po 11.1 V 3-cell (main)  <br> • 1× Li-Po 2-cell (logic & servos) | 5000 mAh & 2200 mAh |
| **Distance Sensing** | 8× HC-SR04 “PING” | - |
| **Heading Reference** | CMPS11 tilt-compensated compass | v3.0 |
| **Victim Sensor** | TCS3200 colour sensor | - |
| **IDE** | CooCox CoIDE | 2.0.6 |
| **Language** | C (ARM GCC) | 10.3.1 |

**Algorithms & Theory**  
- **Gait:** Tripod wave gait with adaptive stride length (≤ 12 cm/s forward speed).  
- **Navigation:** Vector Field Histogram (VFH) on occupancy grid built from PING data.  
- **Victim Detection:** Colour-to-frequency mapping of TCS3200 → HSV thresholding → blob centroid.  
- **Orientation Fusion:** Complementary filter between CMPS11 yaw & gyro integration.

---

## ⚙️ System Design

<p align="center">
  <img src="docs/img/system_overview.png" width="600" alt="High-level block diagram"/>
</p>

| Module | Responsibility | Interfaces |
|--------|----------------|------------|
| **Main Controller** | Mission state machine, high-level path planning | UART2, I²C3 |
| **Gait Engine** | Joint angle generation, trajectory interpolation | Dynamixel bus |
| **Rangefinder Node** | 360° sonar mapping, obstacle avoidance | USART3 |
| **Trace-Gripper Node** | Colour-based victim detection & object retrieval | UART5, PWM |
| **Telemetry** | Stream debug data to laptop over HC-05 | via LCD |

---

## 🧪 Experiments & Evaluation

### Test Scenarios

| Scenario | Description | Result (2023) |
|----------|-------------|---------------|
| **S1 – Mixed Terrain** | 360 cm × 120 cm arena: cracked board, marble “mud”, coral “rubble”, 2 cm steps | Best run: 4 victims rescued, failed on R5 marble pile |
| **S2 – Stairs** | 90 cm horizontal, 50 cm vertical, 2 cm step height | Ascent 100 %, descent slipped 2/5 runs |
| **S3 – Victim Search** | 5 orange victims, no dummy, randomised K-1…K-5 | Detection 100 %, grasp success 60 % |
| **S4 – Full Mission** | 300 s time limit | **Not achieved** – max 4/5 victims, no finish |

### Key Parameters Measured

- **Localization RMSE** vs ground-truth (optical motion capture): 6.2 cm.  
- **Power consumption** during walk: 3.4 A @ 11.1 V average.  
- **Victim detection latency** (sensor trigger → classification): 320 ms.

### Data & Logs  
All raw logs (CSV) are stored in `Main Controller Maze/logs/`, `Rangefinder Maze/logs/`, and `Trace Gripper Maze/logs/`.

---

## 📊 Analysis & Discussion

- **Gait instability on marbles** caused foot sinkage → added passive ankle compliance.  
- **Stair descent slip** → reduced COG velocity & tuned foot clearance to 3 cm.  
- **Victim drop** → gripper torque insufficient; upgraded to MG90S servos.  
- **Navigation drift** → CMPS11 magnetic error ±7°; added gyro yaw fusion.

---

## ✅ Conclusion & Future Work

❌ **Mission NOT accomplished:**  
- Did **not place** in Wilayah or Nasional 2023.  
- Only 4/5 victims rescued; failed to finish within 300 s.

🔍 **Key Lessons**  
- Need **robust foot-ground interaction** for loose media.  
- **Vision-only victim detection** too slow; will add Jetson Nano + OpenCV in 2024.  
- **PID gait** tuned offline; real-time terrain adaptation required.

🚀 **Next Steps (2024 Road-map)**  
- **Keep existing PID** → migrate to Jetson Nano for **on-board computer vision** (YOLO-NAS + depth estimation).  
- **Sensor fusion** → VL53L0X for better rangefinder + IMU for better localisation.  
- **Mechanical** → wider footpads & silicone sole for marble traction.  
- **Firmware** → refactor into **task-based scheduler** on STM32, leave ROS2 for later.

---

## 🕒 Revision History

| Version | Date | Description | Author |
|---------|------|-------------|--------|
| 1.0 | 2023-06-14 | Final release for KRSRI Region 2023 | Alun Darma |
