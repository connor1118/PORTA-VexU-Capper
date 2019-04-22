#include "main.h"

Motor arm(8, MOTOR_GEARSET_36, 0,  MOTOR_ENCODER_DEGREES);

void lift(int vel)
{
  arm.set_brake_mode(MOTOR_BRAKE_BRAKE);
  arm.move_velocity(vel);
}
void armOP()
{
  if(controller.get_digital(DIGITAL_UP))
  {
    if(arm.get_position() < 550)
    lift(100);
    else
    lift(75);
  }
  else if(controller.get_digital(DIGITAL_DOWN))
  {
    lift(-100);
  }
  else
  {
    arm.move_velocity(0);
    if(arm.get_position() < 50)
      arm.set_brake_mode(MOTOR_BRAKE_COAST);
    else
      arm.set_brake_mode(MOTOR_BRAKE_BRAKE);
  }
}

void swing(int pos)
{
  arm.set_brake_mode(MOTOR_BRAKE_BRAKE);
  pos *= 5;
  arm.move_absolute(pos, 100);
}

void swingSlow(int pos)
{
  arm.set_brake_mode(MOTOR_BRAKE_BRAKE);
  pos *= 5;
  arm.move_absolute(pos, 50);
}
