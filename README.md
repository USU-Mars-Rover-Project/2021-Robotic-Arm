Very Basic Use
==============
This is here for team members who are less familiar with Arduinos and don't want to look it up.

Uploading code to Arduino
-------------------------
- Open the .ino file in Arduino IDE
- Plug in Arduino Mega through USB
- Confirm these under tools (only board and port will usually change):
  - **Board:** Arduino Mega or Mega2560
  - **Precessor:** ATmega2560 (Mega2560)
  - **Port:** COM1 or /dev/ttyACM0 or something similar
  - **Programmer:** AVRISP mkII should work
- Press the right arrow button to upload

Wiring
------

Mimic Arm 

The mimic arm has encoders with three pins: black, red, and yellow. Black is ground, red is 5V, and yellow is the signal. This code uses analog pins on the arduino (but it doesn't use them as analog pins). The pins for the mimic arm are found in MimicArm.h. Connect the yellow wires to these pins. 

Robotic Arm

The roboric arm reads PWM signals form the the wires labeled DOF0-DOF5 (degree of freedom) to determine its target position. This code uses the PWM pins on the arduino (for sending PWM signals). The pins used for the robotic arm are found in RoboticArm.h. Connect the DOF wires to these pins.

Code Overview
=============
This code has two sides to it. It measures the position of the mimic arm by reading the PWM signals sent by the encoders. It also generates its own PWM signal to tell the robotic arm the disired position. The code has one class for the robotic arm: RoboticArm. The code has two classes for the mimic arm: MimicArm and MimicJoint. MimicJoint is used by MimicArm. Currently this is written to all be put on the same

Mimic Arm
----------
The mimc arm encoders send PWM signals. This code uses pin change interupts to read the signals.

MimicArm

This class handles the settings for the mimic arm including these for each encoder (one for each joint):
  - pin
  - angle offset
  - angle minimum
  - angle maximum

The MimicArm object stores this data in the MimicJoint Objects

MimicJoint

This class handles communication with the encoders. It uses pin change interrups and callbacks to measure the length of each high and low pulse. It also calculates the angle, which is accessible through the GetAngle() member function.

Robotic Arm
-----------
The robotic arm receives PWM signals to determine the target position. This code uses the arduino's PWM pins to send these signals.

RoboticArm

This class handles the pin settings for the robotic arm. It also contains the Servo objects, which handle sending the PWM signals.
