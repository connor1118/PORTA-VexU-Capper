#include "main.h"

Motor arm(8, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);

void lift(int vel)
{
  arm.set_brake_mode(MOTOR_BRAKE_HOLD);
  arm.move_velocity(vel);
}
void armOP()
{
  if(controller.get_digital(DIGITAL_UP))
  {
    lift(100);
  }
  else if(controller.get_digital(DIGITAL_DOWN))
  {
    lift(-100);
  }
  else
  {
    lift(0);
  }
}

void swing(int pos)
{
  arm.set_brake_mode(MOTOR_BRAKE_HOLD);
  pos *= 5;
  arm.move_absolute(pos, 200);
}

void swingSlow(int pos)
{
  arm.set_brake_mode(MOTOR_BRAKE_HOLD);
  pos *= 5;
  arm.move_absolute(pos, 60);
}
