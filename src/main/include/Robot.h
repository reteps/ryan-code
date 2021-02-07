/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/*
*/
// #include <frc/TimedRobot.h>
// #include <frc/drive/DifferentialDrive.h>
// #include <frc/SpeedControllerGroup.h>
// #include <frc/XboxController.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

using namespace frc;

class Robot : public frc::TimedRobot {
 private:
    WPI_TalonSRX left_front{0};
    WPI_TalonSRX right_front{1};
    WPI_TalonSRX left_back{2};
    WPI_TalonSRX right_back{3};
    XboxController controller{0};
    SpeedControllerGroup left_side{left_front, left_back};
    SpeedControllerGroup right_side{right_front, right_back};
    DifferentialDrive drivetrain{left_side, right_side};
 public:
  void RobotInit() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;
  double deadzone(double val);
};
