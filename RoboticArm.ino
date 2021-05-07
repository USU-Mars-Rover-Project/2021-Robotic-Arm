#include <Arduino.h>
#include "RoboticArm.h"
#include <SPI.h>
#include <RF24.h>


RF24 radio(2, 3);
const byte address[] = "00001";


void setup() {
    Serial.begin(9600);
    
    Serial.println(radio.begin());
    radio.openReadingPipe(0, address);
    radio.startListening();

    RoboticArm::Setup();
}

void CheckRadio() {
  if(radio.available())  {
        char payload[] = "";
        uint8_t payloadSize = radio.getPayloadSize(); 
        radio.read(&payload, payloadSize);
        String payloadString = String(payload);

        int startIndex = payloadString.indexOf('<');                //Parsing a string is apparently terrible in C++
        if( startIndex < 0) return;
        int comma1Index = payloadString.indexOf(',', startIndex+1);
        if( comma1Index < 0) return;
        int comma2Index = payloadString.indexOf(',', comma1Index+1);
        if( comma2Index < 0) return;
        int comma3Index = payloadString.indexOf(',', comma2Index+1);
        if( comma3Index < 0) return;
        int comma4Index = payloadString.indexOf(',', comma3Index+1);
        if( comma4Index < 0) return;
        int comma5Index = payloadString.indexOf(',', comma4Index+1);
        if( comma5Index < 0) return;
        int endIndex = payloadString.indexOf('>', comma5Index+1);
        if( endIndex < 0) return;
    
        int baseAngle = payloadString.substring(startIndex+1, comma1Index).toInt();
        int shoulderAngle = payloadString.substring(comma1Index+1, comma2Index).toInt();
        int elbowAngle = payloadString.substring(comma2Index+1, comma3Index).toInt();
        int wristAngle = payloadString.substring(comma3Index+1, comma4Index).toInt();
        int forearmAngle = payloadString.substring(comma4Index+1, comma5Index).toInt();
        int clawAngle = payloadString.substring(comma5Index+1, endIndex).toInt();

        Serial.print(baseAngle);
        Serial.print(shoulderAngle);
        Serial.print(elbowAngle);
        Serial.print(wristAngle);
        Serial.print(forearmAngle);
        Serial.println(clawAngle);
        //Serial.println(payloadString);
        
        RoboticArm::SetBaseAngle(baseAngle);
        RoboticArm::SetShoulderAngle(shoulderAngle);
        RoboticArm::SetElbowAngle(elbowAngle);
        RoboticArm::SetWristAngle(wristAngle);
        RoboticArm::SetForearmAngle(forearmAngle);
        RoboticArm::SetClawAngle(clawAngle);
    }
}


void loop() {
    CheckRadio();
    RoboticArm::UpdateArmPosition();
    delay(100);
}
