#pragma once

#include <Arduino.h>
#include <Servo.h>


#define BASE_OUTPUT_PIN 8
#define SHOULDER_OUTPUT_PIN 9
#define ELBOW_OUTPUT_PIN 10
#define WRIST_OUTPUT_PIN 11
#define FOREARM_OUTPUT_PIN 12
#define CLAW_OUTPUT_PIN 13


#define BASE_ANGLE_MIN 0
#define SHOULDER_ANGLE_MIN 0
#define ELBOW_ANGLE_MIN 0
#define WRIST_ANGLE_MIN 0
#define FOREARM_ANGLE_MIN 0
#define CLAW_ANGLE_MIN 0

#define BASE_ANGLE_MAX 360
#define SHOULDER_ANGLE_MAX 360
#define ELBOW_ANGLE_MAX 360
#define WRIST_ANGLE_MAX 360
#define FOREARM_ANGLE_MAX 360
#define CLAW_ANGLE_MAX 360


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
