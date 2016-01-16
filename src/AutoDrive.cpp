/*
 * AutoDrive.cpp
 *
 *  Created on: Jan 16, 2016
 *      Author: James
 */
#include "Math.h"
#include "Joystick.h"
#include "CANTalon.h"
class AutoDrive{
public:
	AutoDrive(Joystick* ls,Joystick* rs,CANTalon* lm,CANTalon* rm):leftStick(ls),rightStick(rs),leftMot(lm),rightMot(rm){
		printf("Drive system inited");
	}
	void driveFeet(double feet=10,double speed=.5){
		leftMot->SetPosition(0);
		rightMot->SetPosition(0);
		rightMot->SetControlMode(rightMot->kFollower);
		rightMot->Set(4);
		double distance=abs(feet/(3.1415*width)*1000.0);
		while(abs(leftMot->GetEncPosition())<distance){
			leftMot->Set((feet>0?speed:-speed)*(1-(abs(leftMot->GetEncPosition())/distance)));
		}
		leftMot->Set(0);
	}
private:
	Joystick* leftStick;
	Joystick* rightStick;
	CANTalon* leftMot;
	CANTalon* rightMot;
	const double width=3.0;
};
