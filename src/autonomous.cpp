#include "main.h"

ADIDigitalIn A ('A');
ADIDigitalIn B ('B');
ADIDigitalIn C ('C');
ADIDigitalIn D ('D');

void flipDrive()
{
  flip();
  drive(20);
  stopFlip();
}

void shortFlipDrive()
{
  flip();
  drive(10);
  stopFlip();
}

void intakeDrive()
{
  intake();
  drive(10);
  stopIntake();
}

void skills()
{
//I wish you could do skills with both bots
}

void red()
{
  //first shot and wall align
  shoot();
  turn(-70);
  driveHard(-5);
  //to first cap
  drive(38);
  intakeDrive();
  intake();
  drive(-6);
  stopIntake();
  drive(16);
  drive(-3);
  //line up and grab second cap
  turn(90);
  drive(-10);
  driveHard(-5);
  swing(100);
  drive(5);
  turn(90);
  //close post
  drive(20);
  turn(90);
  drive(16);
  drive(5);
  //stack cap, turn, align, and shoot middle flag
  swingSlow(192);
  delay(2000);
  drive(-10);
  swing(0);
  turn(90);
  drive(-30);
  intake();
  drive(5);
  turn(80);
  stopIntake();
  adjust(0);
  shoot();
}

void blue()
{
  //first shot and wall align
  shoot();
  turn(70);
  driveHard(-5);
  //to first cap
  drive(38);
  intakeDrive();
  intake();
  drive(-6);
  stopIntake();
  drive(16);
  drive(-3);
  //line up and grab second cap
  turn(-95);
  drive(-10);
  driveHard(-5);
  swing(100);
  drive(5);
  turn(-95);
  drive(25);
  turn(-95);
  drive(14);
  drive(5);
  //stack cap, turn, align, and shoot middle flag
  swingSlow(192);
  delay(2000);
  drive(-10);
  swing(0);
  turn(-90);
  drive(-30);
  intake();
  drive(5);
  turn(-80);
  stopIntake();
  adjust(0);
  shoot();
}

void test()
{
  turn(-90);

}

void autonomous()
{
  if(A.get_value())
  {
    test();
  }
  if(B.get_value())
  {
    skills();
  }
  if(C.get_value())
  {
    red();
  }
  if(D.get_value())
  {
    blue();
  }
}
