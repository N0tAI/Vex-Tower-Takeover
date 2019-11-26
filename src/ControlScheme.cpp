#include "vex.h"
// this comment is here because they auto format formats include lines by
// alphabetical order which fucks up some dependancies
#include "ControlScheme.h"

void ControllerInteraction::moveLeftSide() {
  LeftMotors.spin(fwd, Controller.Axis3.position(pct), pct);
}

void ControllerInteraction::moveRightSide() {
  RightMotors.spin(fwd, Controller.Axis2.position(pct), pct);
}

void ControllerInteraction::pushIntake() {
  // Intake Motor fwd 50% power
  IntakeMotors.spin(fwd, 50, pct);
}

void ControllerInteraction::pullIntake() {
  // Intake Motor rev 50% power
  IntakeMotors.spin(reverse, 50, pct);
}

void ControllerInteraction::liftArm() {
  // Arm Motor Forward
  ArmMotors.spin(fwd, 50, pct);
}

void ControllerInteraction::lowerArm() {
  // Arm Motor Reverse 50% power
  ArmMotors.spin(reverse, 50, pct);
}

void ControllerInteraction::extendPiston() {
  // Piston Motor Forward 50% power
  PistonMotors.spin(fwd, 50, pct);
}

void ControllerInteraction::retractPiston() {
  // Arm Motor Forward 50% power
  PistonMotors.spin(reverse, 100, pct);
}

void ControllerInteraction::stopIntake() {
  // Stopping Left Intake Motor
  IntakeMotors.stop();
}

void ControllerInteraction::stopArm() {
  // Stopping Arm Motor
  ArmMotors.stop();
}

void ControllerInteraction::stopPiston() {
  // Stopping  Piston Motor
  PistonMotors.stop();
}

void Driver::setDriverCieran() {

  // Robot Movement Setup
  // Tank Controls
  Controller.ButtonLeft.pressed(nothing);
  Controller.ButtonX.pressed(nothing);
  Controller.ButtonA.pressed(nothing);

  Controller.Screen.clearScreen();
  Controller.Screen.print("Hello Cieran!");

  // Set the left joystick Y Axis to move the left side of the robot
  Controller.Axis3.changed(ControllerInteraction::moveLeftSide);

  // Set the right joystick Y Axis to move the right side of the robot
  Controller.Axis2.changed(ControllerInteraction::moveRightSide);

  // Arm Movement Setup
  // Controls for the arm

  // Sets the left down button to lower the robot's arms
  Controller.ButtonDown.pressed(ControllerInteraction::lowerArm);
  Controller.ButtonDown.released(ControllerInteraction::stopArm);

  // Sets the right down button(B) to raise the robot's arm
  Controller.ButtonB.pressed(ControllerInteraction::liftArm);
  Controller.ButtonB.released(ControllerInteraction::stopArm);

  // Piston Control Setup
  // Controls for the piston

  // Sets the lowest front left button to lower the piston
  Controller.ButtonL2.pressed(ControllerInteraction::retractPiston);
  Controller.ButtonL2.released(ControllerInteraction::stopPiston);

  // Sets the lowest front right button to raise the piston
  Controller.ButtonR2.pressed(ControllerInteraction::extendPiston);
  Controller.ButtonR2.released(ControllerInteraction::stopPiston);

  // Intake Control Setup
  // Controls for the intake system

  // Sets the highest front left button to have the intake system pull
  // objects towards the bot
  Controller.ButtonL1.pressed(ControllerInteraction::pullIntake);
  Controller.ButtonL1.released(ControllerInteraction::stopIntake);

  // Sets the highest front right button to have the intake system push
  // objects away from the bot
  Controller.ButtonR1.pressed(ControllerInteraction::pushIntake);
  Controller.ButtonR1.released(ControllerInteraction::stopIntake);
}

void Driver::setDriverCharlie() {
  /*  TODO:
      - Get controls from charlie and update the callbacks with his desired
      control scheme
    */
  Controller.ButtonLeft.pressed(nothing);
  Controller.ButtonX.pressed(nothing);
  Controller.ButtonA.pressed(nothing);
}

void Driver::setDriverAndrew() {
  Controller.ButtonLeft.pressed(nothing);
  Controller.ButtonX.pressed(nothing);
  Controller.ButtonA.pressed(nothing);

  Controller.Screen.clearScreen();
  Controller.Screen.print("Hello Andrew!");

  // Set the left joystick Y Axis to move the left side of the robot
  Controller.Axis3.changed(ControllerInteraction::moveLeftSide);

  // Set the right joystick Y Axis to move the right side of the robot
  Controller.Axis2.changed(ControllerInteraction::moveRightSide);

  // ~~~ Arm Movement Setup ~~~

  // sets the down buttons pressed and released functions
  Controller.ButtonDown.pressed(ControllerInteraction::lowerArm);
  Controller.ButtonDown.released(ControllerInteraction::stopArm);

  // Sets the right down button(B) to raise the robot's arm
  Controller.ButtonB.pressed(ControllerInteraction::liftArm);
  Controller.ButtonB.released(ControllerInteraction::stopArm);

  // Piston Control Setup
  // Controls for the piston

  // Sets the highest front left button to have the intake system pull
  // objects towards the bot
  Controller.ButtonL1.pressed(ControllerInteraction::pullIntake);
  Controller.ButtonL1.released(ControllerInteraction::stopIntake);

  // Sets the lowest front left button to lower the piston
  Controller.ButtonL2.pressed(ControllerInteraction::retractPiston);
  Controller.ButtonL2.released(ControllerInteraction::stopPiston);

  // Sets the highest front right button to have the intake system push
  // objects away from the bot

  Controller.ButtonR1.pressed(ControllerInteraction::pushIntake);
  Controller.ButtonR1.released(ControllerInteraction::stopIntake);

  Controller.ButtonR2.pressed(ControllerInteraction::extendPiston);
  Controller.ButtonR2.released(ControllerInteraction::stopPiston);
}