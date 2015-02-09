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

void forwardR(void){
	motor(LEFT,0);
	Wait(200);
	//stop();
}

void fowardL(void){
	motor(0,RIGHT);
		Wait(200);
		//stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

unsigned short bw;

	for(;;){
		forwardR();
		//Wait(1000);
		//stop();
        bw = ADRead(0);
       // wh = ADread(1);
     if(bw>500){
    	 fowardL();
         //Wait(1000);
    	 }


	}

BuzzerSet(160,100);
BuzzerStart();
Wait(1000);
BuzzerStop();

	return 0;
	}



