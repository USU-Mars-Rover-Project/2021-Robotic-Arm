#pragma once

#include <Arduino.h>
#include <Servo.h>


#define BASE_OUTPUT_PIN 8
#define SHOULDER_OUTPUT_PIN 9
#define ELBOW_OUTPUT_PIN 10
#define WRIST_OUTPUT_PIN 11
#define FOREARM_OUTPUT_PIN 12
#define CLAW_OUTPUT_PIN 13


class RoboticArm {
    public:
        static void Setup();

        static void SetBaseAngle(int baseAngle);
        static void SetShoulderAngle(int shoulderAngle);
        static void SetElbowAngle(int elbowAngle);
        static void SetWristAngle(int wristAngle);
        static void SetForearmAngle(int forearmAngle);
        static void SetClawAngle(int clawAngle);

        static void UpdateArmPosition();

    private:
        static RoboticArm* RoboticArmInstance;

        int BaseAngle;
        int ShoulderAngle;
        int ElbowAngle;
        int WristAngle;
        int ForearmAngle;
        int ClawAngle;

        Servo BaseServo;
        Servo ShoulderServo;
        Servo ElbowServo;
        Servo WristServo;
        Servo ForearmServo;
        Servo ClawServo;

        RoboticArm() {};
};