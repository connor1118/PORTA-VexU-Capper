#include "main.h"

Motor shooter(5, MOTOR_GEARSET_18, 1,  MOTOR_ENCODER_DEGREES);
Motor shooter1(6, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);

void shooterOP()
{
  if(controller.get_digital(DIGITAL_L1))
  {
    shooter.move_velocity(200);
    shooter1.move_velocity(200);
    delay(550);
    shooter.move_velocity(0);
    shooter1.move_velocity(0);
  }
}

void shoot()
{
  shooter.move_velocity(200);
  shooter1.move_velocity(200);
  delay(550);
  shooter.move_velocity(0);
  shooter1.move_velocity(0);
}
