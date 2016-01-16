#include "WPILib.h"
#include "AutoDrive.cpp"
class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	CANTalon* leftMotor;
	CANTalon* rightMotor;
	Joystick* leftJoystick;
	Joystick* rightJoystick;
	AutoDrive* drive;
	void RobotInit()
	{
		leftJoystick=new Joystick(0);
		rightJoystick=new Joystick(1);
		leftMotor=new CANTalon(4,1);
		drive=new AutoDrive(leftJoystick,rightJoystick,leftMotor,rightMotor);
	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit()
	{
		drive->driveFeet(10,.45);
	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		leftMotor->SetControlMode(leftMotor->kPercentVbus);
		rightMotor->SetControlMode(rightMotor->kPercentVbus);
		while(IsOperatorControl()&&IsEnabled()){
			leftMotor->Set(leftJoystick->GetY());
			rightMotor->Set(rightJoystick->GetY());
		}
		leftMotor->Set(0);
		rightMotor->Set(0);
	}

	void TeleopPeriodic()
	{

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
