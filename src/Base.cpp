#include "main.h"

static int maxBaseVelocity = 200;
static int highBaseVelocity = 150;
static int medBaseVelocity = 100;
static int slowBaseVelocity = 50;
static int brakeBaseVelocity = -20;

static int distance = 0;

//DEFINING MOTORS
Motor leftDrive(1, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);
Motor leftDrive1(2, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);

Motor rightDrive(3, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);
Motor rightDrive1(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);



void driveOP()
{
  leftDrive.move(controller.get_analog(ANALOG_LEFT_Y));
  leftDrive1.move(controller.get_analog(ANALOG_LEFT_Y));
  rightDrive.move(controller.get_analog(ANALOG_RIGHT_Y));
  rightDrive1.move(controller.get_analog(ANALOG_RIGHT_Y));
}

void resetDrive()
{
  leftDrive.tare_position();
  leftDrive1.tare_position();
  rightDrive.tare_position();
  rightDrive1.tare_position();
}


void left(int speed)
{
  leftDrive.move(speed);
  leftDrive1.move(speed);
}

void right(int speed)
{
  rightDrive.move(speed);
  rightDrive1.move(speed);
}

bool isDriving()
{
  static int count = 0;
  static int last = 0;
  static int lastTarget = 0;

  int leftPos = leftDrive.get_position();
  int rightPos = rightDrive.get_position();

  int curr = (abs(leftPos) + abs(rightPos))/2;
  int thresh = 2;
  int target = distance;

  if(abs(last-curr) < thresh)
    count++;
  else
    count = 0;

  if(target != lastTarget)
    count = 0;

  lastTarget = target;
  last = curr;

  //not driving if we haven't moved
  if(count > 6)
    return false;
  else
    return true;
}


void leftSlew(int slewSpeed, bool decel)
{
  int step;
  static int speed = 0;
  if(abs(speed) < abs(slewSpeed))
  {
    step = 5;
  }
  else
  {
    if(decel)
    {
    step = 10;
    }
    else
    {
    step = 256; // no slew
    }
  }
  if(speed < slewSpeed - step)
  {
    speed += step;
  }
  else if(speed > slewSpeed + step)
  {
    speed -= step;
  }
  else
  {
    speed = slewSpeed;
  }

   left(speed);
}

void rightSlew(int slewSpeed, bool decel)
{
  int step;
  static int speed = 0;
  if(abs(speed) < abs(slewSpeed))
  {
    step = 5;
  }
  else
  {
    if(decel)
    {
    step = 10;
    }
    else
    {
    step = 256; // no slew
    }
  }


  if(speed < slewSpeed - step)
  {
    speed += step;
  }
  else if(speed > slewSpeed + step)
  {
    speed -= step;
  }
  else
  {
    speed = slewSpeed;
  }

   right(speed);
}

//drive
void drive(int inches)
{
  resetDrive();
    distance = inches*(360/14.125);
    int prevError = 0;
    int sp = distance;

    double kp = .35;
    double kd = 0.5;

    do
    {
      int ls = leftDrive.get_position();
      int rs = rightDrive.get_position();
      int sv = ls;

      //speed
      int error = sp-sv;
      int derivative = error - prevError;
      prevError = error;
      int speed = error*kp + derivative*kd;

      if(speed > highBaseVelocity)
      {
        speed = highBaseVelocity;
      }
      if(speed < -highBaseVelocity)
      {
        speed = -highBaseVelocity;
      }

      leftSlew(speed, 0);
      rightSlew(speed, 0);
      printf("%d\n", error);
      delay(20);
    }
    while(isDriving());
}

void driveHard(int inches)
{
  resetDrive();
  int distance = inches*(360/14.125);
  if(distance > 0)
  {
    leftDrive.move_velocity(maxBaseVelocity);
    leftDrive1.move_velocity(maxBaseVelocity);
    rightDrive.move_velocity(maxBaseVelocity);
    rightDrive1.move_velocity(maxBaseVelocity);

    while(leftDrive.get_position() < distance)
    {
      delay(2);
    }

    leftDrive.move_velocity(brakeBaseVelocity);
    leftDrive1.move_velocity(brakeBaseVelocity);
    rightDrive.move_velocity(brakeBaseVelocity);
    rightDrive1.move_velocity(brakeBaseVelocity);

    delay(10);

    leftDrive.move_velocity(0);
    leftDrive1.move_velocity(0);
    rightDrive.move_velocity(0);
    rightDrive1.move_velocity(0);
  }
  if(distance < 0)
  {
    leftDrive.move_velocity(-maxBaseVelocity);
    leftDrive1.move_velocity(-maxBaseVelocity);
    rightDrive.move_velocity(-maxBaseVelocity);
    rightDrive1.move_velocity(-maxBaseVelocity);

    while(leftDrive.get_position() > distance)
    {
      delay(2);
    }

    leftDrive.move_velocity(-brakeBaseVelocity);
    leftDrive1.move_velocity(-brakeBaseVelocity);
    rightDrive.move_velocity(-brakeBaseVelocity);
    rightDrive1.move_velocity(-brakeBaseVelocity);

    delay(10);

    leftDrive.move_velocity(0);
    leftDrive1.move_velocity(0);
    rightDrive.move_velocity(0);
    rightDrive1.move_velocity(0);
  }
}

void turn(int degrees)
{
  resetDrive();
    distance = degrees*3.4;
    int prevError = 0;
    int sp = distance;

    int kboost;
    double kp = 1;
    double kd = 2.5;

    if(distance>0)
      kboost = 10;
    else
      kboost = -10;

    do
    {
      int ls = leftDrive.get_position();
      int rs = rightDrive.get_position();
      int sv = (rs-ls)/2;

      //speed
      int error = sp-sv;
      int derivative = error - prevError;
      prevError = error;
      int speed = error*kp + derivative*kd;

      if(speed > medBaseVelocity)
        speed = medBaseVelocity;

      if(speed < -medBaseVelocity)
        speed = -medBaseVelocity;


      leftSlew(-speed, 0);
      rightSlew(speed, 0);
      printf("%d\n", error);
      delay(20);
    }
    while(isDriving());
  resetDrive();
}
