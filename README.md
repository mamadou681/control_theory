# 🛰️ Filter Simulation for Drones & Robotics

This project is a **Qt/QML and C/C++ simulation tool** for experimenting with **signal filtering and sensor fusion** techniques, primarily for **drone and robotics applications**.  
It simulates sensor data (IMU, sonar, voltage) and visualizes the effect of different filters in real-time using **QCustomPlot** integrated into **QtQuick/QML**.  
Linear algebra operations (Kalman, EKF, Quaternion math) are implemented using **Eigen**.

---

## ✨ Features

- 📊 **Filtering algorithms implemented:**
  - Average Filter
  - Moving Average Filter
  - Low-Pass Filter (Exponential)
  - Kalman Filter (Linear, position/velocity)
  - Extended Kalman Filter (Quaternion-based orientation & bias)
  - Quaternion utilities for 3D rotations

- 📡 **Sensor data simulation:**
  - IMU (accelerometer + gyroscope, from CSV data)
  - Sonar altitude sensor (CSV-based + noise)
  - Voltage simulation with Gaussian noise

- 🎨 **Visualization:**
  - Real-time plotting with QCustomPlot inside QML
  - Multiple data series (raw vs filtered) with legends, labels, rescaling
  - Adjustable graph size and reset capability

- 🛠️ **Modular design:**
  - Reusable filter classes
  - Sensor data readers
  - QML-friendly wrappers
  - **Eigen-based math utilities for matrices, vectors, and quaternions**

## ⚙️ Cloning & Building

### Requirements
- **Qt 5.15+** or **Qt 6.x**

### Clone 

```bash
git clone https://github.com/mamadou681/control_theory.git
cd control_theory
```
### Build (qmake or QtCreator)
```bash
qmake
make -j4
```
