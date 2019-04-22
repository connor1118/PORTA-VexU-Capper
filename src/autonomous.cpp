#include "main.h"

ADIDigitalIn A ('A');
ADIDigitalIn B ('B');
ADIDigitalIn C ('C');
ADIDigitalIn D ('D');

ADIDigitalIn Park ('H');

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
  drive(38);
  swing(100);
  intakeDrive();

  drive(-24);
  swing(0);
  //line up and grab second cap
  turn(130);
  drive(-28);
  swing(120);
  //to post
  drive(3);
  turn(45);
  drive(14);
  turn(90);
  drive(8);
  drive(5);
  //stack cap
  swingSlow(210);
  delay(2000);
  swing(208);
  drive(-10);
  swing(0);
  //wall align
  turn(90);
  adjust(0);
  drive(14);
  turn(87);
  drive(-10);
  //shoot bottom flag then middle flag if ball was intook
  delay(500);
  drive(8);
  turn(-33);
  shoot();
  delay(250);
  intake();
  adjust(1);
  delay(3000);
  shoot();
  if(Park.get_value())
  {
    turn(33);
    intake();
    drive(31);
    driveHard(23);
    stopIntake();
    brake();
    delay(500);
    coast();
  }

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
  drive(38);
  swing(100);
  intakeDrive();

  drive(-24);
  swing(0);
  //line up and grab second cap
  turn(-135);
  drive(-28);
  swing(120);
  //to post
  drive(3);
  turn(-42);
  drive(16);
  turn(-88);
  drive(8);
  drive(5);
  //stack cap
  swingSlow(210);
  delay(2000);
  swing(208);
  drive(-10);
  swing(0);
  //wall align
  turn(-90);
  adjust(0);
  drive(14);
  turn(-87);
  drive(-10);
  //shoot bottom flag then middle flag if ball was intook
  delay(500);
  drive(8);
  turn(39);
  shoot();
  delay(250);
  intake();
  adjust(1);
  delay(3000);
  shoot();
  if(Park.get_value())
  {
    turn(-39);
    intake();
    drive(31);
    driveHard(23);
    stopIntake();
    brake();
    delay(500);
    coast();
  }

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
