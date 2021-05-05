#include <Arduino.h>
#include <Servo.h>
#include "RoboticArm.h"


RoboticArm* RoboticArm::RoboticArmInstance;


void RoboticArm::Setup() {
    delete RoboticArmInstance;            //Much responsible. Wow.
    RoboticArmInstance = new RoboticArm();

    pinMode(SHOULDER_OUTPUT_PIN, OUTPUT);
    RoboticArmInstance->BaseServo.attach(BASE_OUTPUT_PIN);
    RoboticArmInstance->ShoulderServo.attach(SHOULDER_OUTPUT_PIN);
    RoboticArmInstance->ElbowServo.attach(ELBOW_OUTPUT_PIN);
    RoboticArmInstance->WristServo.attach(WRIST_OUTPUT_PIN);
    RoboticArmInstance->ForearmServo.attach(FOREARM_OUTPUT_PIN);
    RoboticArmInstance->ClawServo.attach(CLAW_OUTPUT_PIN);
}


void RoboticArm::SetBaseAngle(int baseAngle) {
    RoboticArmInstance->BaseAngle = (long)(baseAngle - BASE_ANGLE_MIN) * 180 / (BASE_ANGLE_MAX - BASE_ANGLE_MIN);
}


void RoboticArm::SetShoulderAngle(int shoulderAngle) {
    RoboticArmInstance->ShoulderAngle = (long)(shoulderAngle - BASE_ANGLE_MIN) * 180 / (BASE_ANGLE_MAX - BASE_ANGLE_MIN);
}


void RoboticArm::SetElbowAngle(int elbowAngle) {
    RoboticArmInstance->ElbowAngle = (long)(elbowAngle - BASE_ANGLE_MIN) * 180 / (BASE_ANGLE_MAX - BASE_ANGLE_MIN);
}


void RoboticArm::SetWristAngle(int wristAngle) {
    RoboticArmInstance->WristAngle = (long)(wristAngle - BASE_ANGLE_MIN) * 180 / (BASE_ANGLE_MAX - BASE_ANGLE_MIN);
}


void RoboticArm::SetForearmAngle(int forearmAngle) {
    RoboticArmInstance->ForearmAngle = (long)(forearmAngle - BASE_ANGLE_MIN) * 180 / (BASE_ANGLE_MAX - BASE_ANGLE_MIN);
}


void RoboticArm::SetClawAngle(int clawAngle) {
    RoboticArmInstance->ClawAngle = (long)(clawAngle - BASE_ANGLE_MIN) * 180 / (BASE_ANGLE_MAX - BASE_ANGLE_MIN);
}


void RoboticArm::UpdateArmPosition() {
    RoboticArmInstance->BaseServo.write(RoboticArmInstance->BaseAngle);
    RoboticArmInstance->ShoulderServo.write(RoboticArmInstance->ShoulderAngle);
    RoboticArmInstance->ElbowServo.write(RoboticArmInstance->ElbowAngle);
    RoboticArmInstance->WristServo.write(RoboticArmInstance->WristAngle);
    RoboticArmInstance->ForearmServo.write(RoboticArmInstance->ForearmAngle);
    RoboticArmInstance->ClawServo.write(RoboticArmInstance->ClawAngle);
}