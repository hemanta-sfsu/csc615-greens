#include <stdio.h>
#include <pigpio.h>
#include <time.h>
#include <unistd.h>
#define  LINE_L 17
#define LINE_C 27
#define LINE_R 22
int main (int argc, char *argv[])
{
    //left, right, and middle line sensor with their gpio numbers 

    int breaker = 0;

    if (gpioInitialise() < 0) 
    {
	fprintf(stderr, "pigpio initialization failed \n");
	return 1;
    }
 
    gpioSetMode(LINE_L, PI_INPUT);
    gpioSetMode(LINE_C, PI_INPUT);
    gpioSetMode(LINE_R, PI_INPUT);
    while(breaker != 1){
	printf("%d",gpioRead(LINE_L));
	printf("%d",gpioRead(LINE_C));
	printf("%d",gpioRead(LINE_R));
	if( (gpioRead(LINE_L)==1)  ){
		printf("\n......................\nFollowing the line\n.........................\n");
		
	}else{
		printf("\n..................nRunning out of line\n.....................\n");
	}
    	

	/*if( (gpioRead(LINE_L)==0) && (gpioRead(LINE_R)==0) && (gpioRead(LINE_C) == 1)  ){
		printf("\n......................\nFollowing the line\n.........................\n");
		
	}else{
		printf("\n..................nRunning out of line\n.....................\n");
	}*/
    	/*if( (gpioRead(DO1) ==1)|| (gpioRead(DO2) ==1) || (gpioRead(DO2) ==1)  ){
		printf("\n**********************\nRunning out of line\n**********************\n");
    	}else {
		printf("\n--------------------\nFollowing the line\n");
    	}*/

//   	sleep(1);

    //	if (gpioRead(OUT) ==0){
//		printf("\n**************\nThere is an obstacle ahead\nStopping\n***************\n");
//		breaker = 1;
  //  	}else if (gpioRead(OUT) ==1){
//		printf("\nNo Obstacle\n-------------------------\n");
  //  	}
	sleep(1);
  }


    return 0;
}
