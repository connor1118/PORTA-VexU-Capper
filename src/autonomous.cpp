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
/*  swing(100);
  drive(12);
  swing(0);
  delay(500);
  shoot();
  drive(-10);
  turn(33);
  drive(-6);
  turn(-90);
  drive(-10);*/
  //to first cap
  delay(500);
  swing(100);
  drive(38);
  swing(0);
  intakeDrive();

  drive(-6);
  drive(13);
  drive(-4);
  //line up and grab second cap
  turn(80);
  drive(-13);
  driveHard(-5);
  swing(100);
  drive(8);
  //wall align
  turn(-180);
  drive(18);
  drive(-12);
  //close post
  turn(-90);
  drive(22);
  turn(90);
  drive(10);
  drive(5);
  //stack cap
  swingSlow(194);
  delay(2000);
  swing(191);
  drive(-10);
  swing(0);
  //wall align
  turn(90);
  adjust(0);
  drive(14);
  turn(90);
  drive(-14);
  //shoot bottom flag then middle flag if ball was intook
  drive(8);
  turn(-35);
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
/*  swing(100);
  drive(12);
  swing(0);
  delay(500);
  shoot();
  drive(-10);
  turn(-33);
  drive(-6);
  turn(90);
  drive(-10);*/
  //to first cap
  delay(500);
  swing(100);
  drive(38);
  swing(0);
  intakeDrive();

  drive(-6);
  drive(13);
  drive(-4);
  //line up and grab second cap
  turn(-90);
  drive(-13);
  driveHard(-5);
  swing(100);
  drive(8);
  //wall align
  turn(180);
  drive(22);
  drive(-12);
  //close post
  turn(90);
  drive(22);
  turn(-90);
  drive(8);
  drive(5);
  //stack cap
  swingSlow(194);
  delay(2000);
  swing(191);
  drive(-10);
  swing(0);
  //wall align
  turn(-90);
  adjust(0);
  drive(14);
  turn(-90);
  drive(-14);
  //shoot bottom flag then middle flag if ball was intook
  drive(8);
  turn(34);
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
