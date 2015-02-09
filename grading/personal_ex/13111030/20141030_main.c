#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 10000
#define FW 40

void motor(short left, short right){

	Mtr_Run_lv(left, -right,0,0,0,0);
}

void stop(void){
	motor(0,0);
}

void forward(int n){
	motor(LEFT,RIGHT);
	Wait(FW*n);
	stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		forward();
		wait(1000);

	}

	return 0;
}

