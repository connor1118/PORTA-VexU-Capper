#include "main.h"

Controller controller (CONTROLLER_MASTER);

void opcontrol() {
	while(true)
	{

		driveOP();
		shooterOP();
		adjusterOP();
		armOP();
		intakeOP();

		if(controller.get_digital(DIGITAL_LEFT) && !competition::is_connected())
		{
			autonomous();
		}
		pros::delay(20);
	}
}
