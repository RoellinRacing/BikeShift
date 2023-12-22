#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int buttonUp = 2;
const int buttonDown = 3;
int gear = 0;  // Aktueller Gang
int neutralPWM = 375;  // PWM-Wert für die neutrale Position

void setup() {
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pwm.begin();
  pwm.setPWMFreq(60);  // 60 Hz
  pwm.setPWM(0, 0, neutralPWM);  // Start in neutraler Position
}

void loop() {
  if (digitalRead(buttonUp) == LOW) {
    gear++;
    shiftGear(600);  // Werte müssen kalibriert werden
    delay(500);  // Entprellzeit
  }
  
  if (digitalRead(buttonDown) == LOW) {
    gear--;
    shiftGear(150);  // Werte müssen kalibriert werden
    delay(500);  // Entprellzeit
  }
}

void shiftGear(int pwmValue) {
  pwm.setPWM(0, 0, pwmValue);
  delay(200);  // Zeit für den Schaltvorgang
  pwm.setPWM(0, 0, neutralPWM);  // Zurück in die neutrale Position
}