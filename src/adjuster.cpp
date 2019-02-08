#include "main.h"

Motor adjuster(7, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);

bool adjPos;
void adjusterOP()
{
  if(controller.get_digital(DIGITAL_L2))
  {
    if(adjPos)
    {
      adjuster.move_velocity(200);
      delay(300);
      adjuster.move_velocity(0);
    }
    else
    {
      adjuster.move_velocity(-200);
      delay(300);
      adjuster.move_velocity(0);
    }
    adjPos = !adjPos;
  }
}

void adjust(bool up)
{
  if(up)
  {
    adjuster.move_velocity(-200);
    delay(300);
    adjuster.move_velocity(0);
  }
  else
  {
    adjuster.move_velocity(200);
    delay(300);
    adjuster.move_velocity(0);
  }
}