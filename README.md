# Intelligent-IoT-Car-With-Dual-Control
A smart ESP32-based IoT robotic car with dual control modes: AI voice commands (via Teachable Machine) and Bluetooth app interface. Features intelligent obstacle detection, real-time LCD feedback, temperature/humidity sensing (DHT11), battery level monitoring, and autonomous decision-making support.

## 📌 Project Overview

The system includes:
1. ESP32 controller for motor control, sensor input, and communication.
2. Dual control interface:
   - Voice Control using Teachable Machine.
   - Mobile App Remote Control using MIT App Inventor.
3. Real-time obstacle detection via ultrasonic sensor.

## ⚙️ Alternate Version 
1️⃣ An advanced ESP32-powered robotic vehicle featuring gesture recognition, AI voice control (Teachable Machine), and mobile app interface.
2️⃣ Supports real-time obstacle avoidance, temperature/humidity monitoring, and dynamic LCD updates.
3️⃣ Enables both autonomous and manual navigation for smart embedded system applications.

---

## 🧰 Hardware Requirements

### For ESP32 Robot Car
- ESP32 Dev Board
- L298N Motor Driver
- 2x DC Motors with wheels
- Ultrasonic Sensor (HC-SR04)
- IR Sensor (optional for edge detection)
- LCD Display (16x2 with I2C)
- DHT11 Sensor (for temp & humidity)
- Buzzer
- Battery Pack (7.4V-12V)
- Jumper wires

---

## 💻 Software Requirements

### Host Computer
- Arduino IDE
- Teachable Machine (for voice model export)
- MIT App Inventor (for mobile app design)

### ESP32
- Libraries:
  - LiquidCrystal_I2C
  - BluetoothSerial
  - WiFi
  - NewPing (optional)

---

## 🚀 Setup Instructions

### 1. ESP32 Setup

- Connect your motors and sensors as per schematic in `Assembly/PCB/`
- Upload `main_firmware.ino` from `Firmware/`
- Update WiFi or Bluetooth credentials in code

```cpp
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
```

---

### 2. App Control

- Load `App.aia` in MIT App Inventor
- Open App.aia at MIT App Inventor
- Build app and install APK on your phone
- Pair your ESP32 via Bluetooth
- Use remote or voice interface to send commands
- 

### 4. ESP32 Wiring (refer schematic)

Motors to GPIOs 27/14 (A) and 12/13 (B)
Enable pin = GPIO 22
Ultrasonic = Trig (GPIO 5),
Echo (GPIO 18)
DHT11 = GPIO 15
LCD I2C = SDA (GPIO 21),
SCL (GPIO 22)
Battery = GPIO 34 via voltage divider

### 5. Upload Firmware

Open main_firmware.ino
Install required libraries:
LiquidCrystal_I2C
BluetoothSerial
DHT
Upload to ESP32


## 📂 Project Structure

```
📁 Assembly/
    └── PCB/ (schematic files)

📁 Firmware/
    └── main_firmware.ino

📁 Software/
    └── App.aia
    └── VoiceModel/ (Teachable Machine model)
README.md
.gitignore
```
## Skills Gained

-Fabricating and testing of EDU-Robo IoT IDE,
-Gaining hands-on experience in prototyping, debugging, and Programming loT IDE with Bluetooth & Wi-Fi,
-Mobile APP development for EDU-Robo IDE,
-Application Development on: loT-Enabled Car with Obstacle Detection.


## 👤 Author

**Raj Rokade**  
🔗 www.linkedin.com/in/raj-rokade-b271a826a
📧 rajrokade2511@gmail.com
