#include "main.h"

Motor claw(7, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);
Motor wrist(8, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);


void clawOP()
{
  bool clawPosition;
  if(controller.get_digital(DIGITAL_L1))
  {
    clawPosition = 1;
    claw.move_velocity(200);
  }
  else if(controller.get_digital(DIGITAL_L2))
  {
    clawPosition = 0;
    claw.move_velocity(-200);
  }
  else
  {
    if(clawPosition)
    {
      claw.move_velocity(10);
    }
    claw.move_velocity(0);
  }
}


void wristOP()
{
  bool wristPosition;
  if(controller.get_digital(DIGITAL_A))
  {
    if(wristPosition)
    {
      wrist.move_velocity(200);
      delay(500);
    }
    else
    {
      wrist.move_velocity(-200);
      delay(500);
    }
    wristPosition = !wristPosition;
  }
  else
  {
    wrist.move_velocity(0);
  }

}

void flip()
{
  wrist.move(127);
  delay(500);
}

void grab(int position)
{
  claw.move_relative(position, 200);
}
