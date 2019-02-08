#include "main.h"

Motor arm(8, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);


void armOP()
{
  if(controller.get_digital(DIGITAL_R1))
  {
    arm.move_velocity(200);
  }
  else if(controller.get_digital(DIGITAL_R2))
  {
    arm.move_velocity(-200);
  }
  else
  {
    arm.move_velocity(0);
  }
}

void swing(int pos)
{
  if(pos > 0)
  arm.move(100);

  else
  arm.move(-100);

  int target = pos;
  while(!((arm.get_position() < target+3) && (arm.get_position() > target-3)))
    {
      delay(2);
    }
}
