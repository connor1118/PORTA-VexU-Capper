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
  drive(15);
  drive(-5);
  //line up and grab second cap
  turn(90);
  drive(-10);
  driveHard(-5);
  swing(100);
  //drive(4);
  //delay(500);
  drive(5);  // was -2 for far post
  turn(90);
/*  drive(48);
  drive(6);*/
  //close post
  drive(22);
  turn(90);
  drive(16);
  drive(5);
  //both
  swingSlow(192);
  delay(2000);
  drive(-10);
  swing(0);
  turn(90);
  drive(-30);
  intake();
  drive(5);
  turn(82);
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
  drive(15);
  drive(-2);
  //line up and grab second cap
  turn(-92);
  drive(-10);
  driveHard(-5);
  swing(100);
  //drive(4);
  //delay(500);
  drive(5);  // was -2 for far post
  turn(-90);
/*  drive(48);
  drive(6);*/
  //close post
  drive(20);
  turn(-90);
  drive(16);
  drive(5);
  //both
  swingSlow(192);
  delay(2000);
  drive(-10);
  swing(0);
  turn(-90);
  drive(-30);
  intake();
  drive(5);
  turn(-82);
  stopIntake();
  adjust(0);
  shoot();
}

void test()
{
  turn(-90);
//  drive(30);
/*swing(150);
delay(2000);
swingSlow(185);
delay(1000);
//turn(90);
intakeDrive();
adjust(1);
shoot();
turn(180);
drive(-5);
swingSlow(10);
drive(-3);
swing(50);
delay(1000);
drive(20);
turn(180);
swing(0);*/


//drive(-20);

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
