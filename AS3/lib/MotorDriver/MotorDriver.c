/**************************************************************
* Class: CSC-615-01 Spring 2022
* Name: Hemanta Thapa
* Student ID: 920756574
* Github ID: heamnta-sfsu
* Project: Assignment 3 - Motors & Motor Shield
*
* File: <MotorDriver.c>
*
* Description:
   This file has the code for the behaviour for the motor to run and stop
*
**************************************************************/
#include "MotorDriver.h"

void Motor_Init(void)
{
	PCA9685_Init(0x40);
	PCA9685_SetPWMFreq(100);
}

void Motor_Run(UBYTE motor, DIR dir, UWORD speed)
{
	if (speed > MAX)
		speed = MAX;
	if (motor == MOTORA){
	        printf("MotorA Speed = %d\r\n\n", speed);
	   	PCA9685_SetPwmDutyCycle(PWMA, speed);
		switch (dir)
		{
		case FORWARD:
			printf("Running forward......\r\n");
			PCA9685_SetLevel(MA1, 0);
			PCA9685_SetLevel(MA2, 1);
			break;
		case BACKWARD:
			printf("Running backward......\r\n");
			PCA9685_SetLevel(MA1, 1);
			PCA9685_SetLevel(MA2, 0);
			break;
		default:
			printf("No valid direction given");
		}
	}
    else {
		printf("MotorB Speed = %d\r\n\n", speed);
		PCA9685_SetPwmDutyCycle(PWMB, speed);
		switch (dir)
		{
		case FORWARD:
			printf("Running forward......\r\n");
			PCA9685_SetLevel(MB1, 0);
			PCA9685_SetLevel(MB2, 1);
			break;
		case BACKWARD:
			printf("Running backward......\r\n");
			PCA9685_SetLevel(MB1, 1);
			PCA9685_SetLevel(MB2, 0);
			break;
		default:
			printf("No valid direction given");
		}
	}
}

// Motor stop rotation.
void Motor_Stop(UBYTE motor)
{
if (motor == MOTORA){
		PCA9685_SetPwmDutyCycle(PWMA, 0);
}else{
	PCA9685_SetPwmDutyCycle(PWMB, 0);
}
}
