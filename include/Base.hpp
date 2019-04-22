#ifndef _BASE_H_
#define _BASE_H_

void driveOP();

void drive(int inches);
void driveNoPID(int inches);
void driveHard(int inches);
void turn(int degrees);
void turnNoPID(int degrees);

void resetDrive();

void brake();
void coast();

#endif
