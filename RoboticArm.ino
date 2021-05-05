#include <Arduino.h>
#include "RoboticArm.h"


void setup() {
    Serial.begin(9600);

    delay(1000);

    RoboticArm::Setup();
}


void loop() {
    while(Serial.available())  {
        Serial.find('<');
        int baseAngle = Serial.parseInt();
        int shoulderAngle = Serial.parseInt();
        int elbowAngle = Serial.parseInt();
        int wristAngle = Serial.parseInt();
        int forearmAngle = Serial.parseInt();
        int clawAngle = Serial.parseInt();
        
        RoboticArm::SetBaseAngle(baseAngle);
        RoboticArm::SetShoulderAngle(shoulderAngle);
        RoboticArm::SetElbowAngle(elbowAngle);
        RoboticArm::SetWristAngle(wristAngle);
        RoboticArm::SetForearmAngle(forearmAngle);
        RoboticArm::SetClawAngle(clawAngle);
    }

    RoboticArm::UpdateArmPosition();
}
