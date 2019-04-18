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
  swing(100);
  drive(12);
  swing(0);
  delay(500);
  shoot();
  drive(-10);
  turn(30);
  drive(-6);
  turn(-90);
  drive(-14);
  //to first cap
  delay(500);
  drive(38);
  intakeDrive();
  intake();
  drive(-6);
  stopIntake();
  drive(15);
  drive(-5);
  //line up and grab second cap
  turn(90);
  drive(-13);
  driveHard(-5);
  swing(100);
  drive(8);
  turn(90);
  //close post
  drive(20);
  turn(90);
  drive(14);
  drive(5);
  //stack cap
  swingSlow(192);
  delay(2000);
  swing(190);
  drive(-10);
  swing(0);
  //wall align
  turn(100);
  adjust(0);
  intake();
  drive(24);
  turn(90);
  stopIntake();
  drive(-16);
  //shoot bottom flag then middle flag if ball was intook
  drive(8);
  turn(-27);
  shoot();
  delay(250);
  intake();
  adjust(1);
  delay(3000);
  shoot();

}

void blue()
{
  //first shot and wall align
  swing(100);
  drive(12);
  swing(0);
  delay(500);
  shoot();
  drive(-10);
  turn(-30);
  drive(-6);
  turn(90);
  drive(-14);
  //to first cap
  delay(500);
  drive(38);
  intakeDrive();
  intake();
  drive(-6);
  stopIntake();
  drive(15);
  drive(-5);
  //line up and grab second cap
  turn(-90);
  drive(-13);
  driveHard(-5);
  swing(100);
  drive(8);
  turn(-90);
  //close post
  drive(20);
  turn(-90);
  drive(14);
  drive(5);
  //stack cap
  swingSlow(192);
  delay(2000);
  swing(190);
  drive(-10);
  swing(0);
  //wall align
  turn(-100);
  adjust(0);
  intake();
  drive(24);
  turn(-90);
  stopIntake();
  drive(-16);
  //shoot bottom flag then middle flag if ball was intook
  drive(8);
  turn(27);
  shoot();
  delay(250);
  intake();
  adjust(1);
  delay(3000);
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
