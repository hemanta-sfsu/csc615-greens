/**************************************************************
* Class: CSC-615-01 Spring 2022
* Name: Hemanta Thapa
* Student ID: 920756574
* Github ID: heamnta-sfsu
* Project: Assignment 3 - Motors & Motor Shield
*
* File: <MotorDriver.h>
*
* Description:
   This is the header file for MotorDriver
*
**************************************************************/
#ifndef __TB6612FNG_
#define __TB6612FNG_

#include "DEV_Config.h"
#include "PCA9685.h"

// GPIO config
#define PWMA PCA_CHANNEL_0
#define MA1 PCA_CHANNEL_1
#define MA2 PCA_CHANNEL_2
#define PWMB PCA_CHANNEL_5
#define MB1 PCA_CHANNEL_3
#define MB2 PCA_CHANNEL_4
//#define MOTORA       0
#define MOTORB 1
#define MOTORA 0
#define MAX  60

typedef enum
{
    FORWARD = 1,
    BACKWARD,
} DIR;

void Motor_Init(void);
void Motor_Run(UBYTE motor, DIR dir, UWORD speed);
void Motor_Stop(UBYTE motor);

#endif
