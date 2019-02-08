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


}

void blue()
{

}

void test()
{

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
