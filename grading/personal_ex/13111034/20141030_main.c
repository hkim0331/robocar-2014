#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define RIGHT 10000
#define LEFT 10000
#define EDGE 1
#define FW 100


/*unsigned int ADRead(unsigned char n);
n=0,1;*/

void motor(short right,short left){
	Mtr_Run_lv(right,-left,0,0,0,0);
}

void stop(void){
	motor(0,0);
	Wait(100);
}

void step(){
	motor(RIGHT,LEFT);
	Wait(FW);
	stop();
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	for(i=0; i<10; i++){
		step(EDGE);
	}

	return 0;
}

