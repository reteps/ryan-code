/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::RobotInit() { // runs once when robot starts
    left_front.ConfigFactoryDefault();
    left_back.ConfigFactoryDefault();
    right_front.ConfigFactoryDefault();
    right_back.ConfigFactoryDefault();
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
    double forward_value = controller.GetX(frc::GenericHID::kLeftHand);
    double turn_value = controller.GetX(frc::GenericHID::kRightHand);
    double fixed_forward = deadzone(forward_value);
    double fixed_turn = deadzone(turn_value);
    drivetrain.ArcadeDrive(fixed_forward, fixed_turn, false);
}
double Robot::deadzone(double value) {
    if (value < 0.05) {
        return 0;
    }
    return value;
}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
