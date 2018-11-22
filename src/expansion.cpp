#include "main.h"

Motor expansion(5, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);
Motor expansion1(6, MOTOR_GEARSET_18, 1,  MOTOR_ENCODER_DEGREES);

void expansionOP()
{
  if(controller.get_digital(DIGITAL_R1))
  {
    expansion.move_velocity(200);
    expansion1.move_velocity(200);
  }
  else if(controller.get_digital(DIGITAL_R2))
  {
    expansion.move_velocity(-200);
    expansion1.move_velocity(-200);
  }
  else
  {
    expansion.move_velocity(0);
    expansion1.move_velocity(0);
  }
}

void expand(int height)
{
  expansion.move_relative(height, 100);
  expansion1.move_relative(height, 100);

  int target = height;
  while(!((expansion.get_position() < target+3) && (expansion.get_position() > target-3)))
    {
      delay(2);
    }
}
