#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 9600


void motor(short left, short right){

	Mtr_Run_lv(left, -right,0,0,0,0);
}

void stop(void){
	motor(0,0);
}

void forward(void){
	motor(LEFT,RIGHT);
	Wait(500);
	stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

unsigned short bw;

	for(;;){
		forward();
		Wait(1000);
		stop();
        bw = ADRead(0);
     if(bw>300){
    	 break;}
     else{
    	;}
	}

BuzzerSet(160,100);
BuzzerStart();
Wait(1000);
BuzzerStop();

	return 0;
	}

