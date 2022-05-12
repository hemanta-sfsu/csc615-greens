/**************************************************************
* Class: CSC-615-01 Spring 2022
* Name: Hemanta Thapa
* Student ID: 920756574
* Github ID: heamnta-sfsu
* Project: Assignment 3 - Motors & Motor Shield
*
* File: <assignment3.c>
*
* Description:
   This file has implemetation for motor run which makes the motor
   run, slow down to 15%, stop and start running backwards upto the max speed
*
**************************************************************/
#include "assignment3.h"
//#include <pigpio.h>

//#define BUTTON 2

void Handler(int signo)
{
    // System Exit
    printf("\r\nStop requested. Stopping motor....\r\n");
    Motor_Stop(MOTORB);
    Motor_Stop(MOTORA);
    DEV_ModuleExit();
    exit(0);
}

void turn_right(){
	printf("\r\nTurning right\n");
	printf("\r\nStopping motor B\n");
	Motor_Stop(MOTORB);
	printf("\r\nMoving forward\n");
	Motor_Run(MOTORA,FORWARD, 40);
}
void turn_left(){
	printf("\r\nTurning left\n");

	printf("\r\nStopping motorA\n");
	Motor_Stop(MOTORA);
	printf("\r\nMoving forward\n");
	Motor_Run(MOTORB,FORWARD, 40);
}

int main(void)
{
    // 1.System Initialization
    if (DEV_ModuleInit())
        exit(0);

    /*GPIO initializatin
    int status = gpioInitialise();
    if (status < 0){
    fprintf(stderr, "pigpio initialisatin failed\n");
    return 1;
    }
    //Set button for input
    gpioSetMode(BUTTON, PI_INPUT);
    printf("Read from button gpio: %d\n", gpioRead(BUTTON));
    */

    // while (gpioRead(BUTTON)==1) {

    // 2.Motor Initialization
    Motor_Init();

    // 3. Motor runs forward with decreasing speed from 100 to 15 and stops
    Motor_Run(MOTORB, FORWARD, 50);
    sleep(2);
    Motor_Run(MOTORA, FORWARD, 50);
    sleep(2);
    
    for (UWORD i = 50; i > 0; i = i - 5)
    {
        if (i > 15)
        {
            Motor_Run(MOTORB, FORWARD, i);
	    Motor_Run(MOTORA, FORWARD, i);
            usleep(350000);
        }
        else if (i < 16)
        {
	turn_right();
          //  printf("\r\n.....Stopping motor.....\r\n");
//            Motor_Stop(MOTORB);

//	    Motor_Stop(MOTORA);

            break;
        }
    }

    sleep(1);

   // printf("Motor initialized again\n");
   // Motor_Init();

    // 4. Motor runs backwards with increasing speed from 15 to 100 and stops on CTRL + C
/*    Motor_Run(MOTORB, BACKWARD, 15);
    sleep(1);
    Motor_Run(MOTORA, BACKWARD, 15);
    for (UWORD i = 15; i < 60; i = i + 5)
    {

        Motor_Run(MOTORB, BACKWARD, i);
	Motor_Run(MOTORA, BACKWARD, i);
        usleep(350000);
    }*/
    //}
    // 5.Handling Ctrl + C
    do
    {
        signal(SIGINT, Handler);
    } while (1);

    // 6.System Exit
    //  gpioTerminate();
    DEV_ModuleExit();

    return 0;
}
