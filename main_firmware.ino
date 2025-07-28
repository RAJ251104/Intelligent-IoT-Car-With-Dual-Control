// Main firmware for IoT-Enabled Car
#include <BluetoothSerial.h> 
#include <LiquidCrystal_SR.h>  // For 74HC595 + LCD 
// === Motor Pins === 
#define MOTOR_EN 22 
#define MOTOR_A1 27 
#define MOTOR_A2 14 
#define MOTOR_B1 12 
#define MOTOR_B2 13 
 
// === Ultrasonic Sensor + Buzzer === 
#define TRIG_PIN 25 
#define ECHO_PIN 26 
#define BUZZER_PIN 15 
 
// === LCD using 74HC595 === 
LiquidCrystal_SR lcd(17, 16, 21);  // data, clock, enable 
 
BluetoothSerial SerialBT; bool obstacleDetected = false; void setup() { 
  Serial.begin(115200); 
  SerialBT.begin("ESP32-CarRap"); 
  Serial.println("Bluetooth Started"); 
 
  pinMode(MOTOR_EN, OUTPUT);   pinMode(MOTOR_A1, OUTPUT);   pinMode(MOTOR_A2, OUTPUT);   pinMode(MOTOR_B1, OUTPUT);   pinMode(MOTOR_B2, OUTPUT);   pinMode(TRIG_PIN, OUTPUT);   pinMode(ECHO_PIN, INPUT);   pinMode(BUZZER_PIN, OUTPUT); 
 
  // === LCD Init ===   lcd.begin(16, 2);         // 16 cols, 2 rows   delay(500);               // Let LCD power up properly   lcd.setCursor(0, 0);   lcd.print("ESP32 Car Ready");   Serial.println("LCD Ini alized");   delay(2000);  // Show welcome msg for 2 seconds 
  lcd.clear(); 
} 
void loop() {   checkObstacle();   if (SerialBT.available() && !obstacleDetected) {     char cmd = SerialBT.read(); 
    Serial.print("BT Command: "); 
    Serial.println(cmd); 
 
    lcd.setCursor(0, 0);     lcd.print("Cmd: ");     lcd.setCursor(5, 0);  // Set a er 'Cmd: '     switch (cmd) {       case 'F': moveForward(); lcd.print("Forward     "); break;       case 'B': moveBackward(); lcd.print("Backward    "); break;       case 'L': turnLe (); lcd.print("Le        "); break;       case 'R': turnRight(); lcd.print("Right       "); break;       case 'S': stopMotors(); lcd.print("Stop        "); break;       case 'C': clockwise(); lcd.print("Clockwise   "); break;       case 'X': an clockwise(); lcd.print("An Clockwise"); break; 
      default: 
        lcd.print("Unknown     ");         Serial.println("Unknown Command"); 
        break; 
    } 
  } 
} 
// === Motor Controls === void moveForward() {   digitalWrite(MOTOR_A1, HIGH); digitalWrite(MOTOR_A2, LOW);   digitalWrite(MOTOR_B1, LOW); digitalWrite(MOTOR_B2, HIGH);   analogWrite(MOTOR_EN, 255); 
} 
void moveBackward() {   digitalWrite(MOTOR_A1, LOW); digitalWrite(MOTOR_A2, HIGH);   digitalWrite(MOTOR_B1, HIGH); digitalWrite(MOTOR_B2, LOW);   analogWrite(MOTOR_EN, 255); 
} 
void turnLe () {   digitalWrite(MOTOR_A1, LOW); digitalWrite(MOTOR_A2, LOW);   digitalWrite(MOTOR_B1, LOW); digitalWrite(MOTOR_B2, HIGH);   analogWrite(MOTOR_EN, 255); 
} 
void turnRight() {   digitalWrite(MOTOR_A1, HIGH); digitalWrite(MOTOR_A2, LOW);   digitalWrite(MOTOR_B1, LOW); digitalWrite(MOTOR_B2, LOW);   analogWrite(MOTOR_EN, 255); 
} 
void stopMotors() {   digitalWrite(MOTOR_A1, LOW); digitalWrite(MOTOR_A2, LOW);   digitalWrite(MOTOR_B1, LOW); digitalWrite(MOTOR_B2, LOW);   analogWrite(MOTOR_EN, 0); 
} 
void clockwise() {   digitalWrite(MOTOR_A1, HIGH); digitalWrite(MOTOR_A2, LOW);   digitalWrite(MOTOR_B1, HIGH); digitalWrite(MOTOR_B2, LOW);   analogWrite(MOTOR_EN, 255); 
} 
void an clockwise() {   digitalWrite(MOTOR_A1, LOW); digitalWrite(MOTOR_A2, HIGH);   digitalWrite(MOTOR_B1, LOW); digitalWrite(MOTOR_B2, HIGH);   analogWrite(MOTOR_EN, 255); 
} 
// === Obstacle Detec on === void checkObstacle() {   long dura on; 
  int distance;   digitalWrite(TRIG_PIN, LOW);   delayMicroseconds(2);   digitalWrite(TRIG_PIN, HIGH);   delayMicroseconds(10);   digitalWrite(TRIG_PIN, LOW); 
 
  dura on = pulseIn(ECHO_PIN, HIGH, 30000);  // 30ms meout   distance = dura on * 0.034 / 2; 
 
  if (distance > 0 && distance < 20) {     if (!obstacleDetected) { 
      Serial.print("Obstacle: "); 
      Serial.print(distance);       Serial.println(" cm");       stopMotors();       digitalWrite(BUZZER_PIN, HIGH);       lcd.clear();       lcd.setCursor(0, 0);       lcd.print("Obstacle Ahead");       lcd.setCursor(0, 1);       lcd.print("Dist: " + String(distance) + " cm"); 
 
      delay(1000);       digitalWrite(BUZZER_PIN, LOW);       delay(2000); 
 
      obstacleDetected = true; 
    }   } else {     if (obstacleDetected) {       lcd.clear();       lcd.setCursor(0, 0);       lcd.print("Path Clear     "); 
    } 
    obstacleDetected = false; 
  } 
} 
 
