#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define TURN 8

int i;
int a[4] = {1000, 1000, 500, 500};
int b[4] = {0, 90, 240, 180};

void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void){
	motor(0,0);
	stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(i = 0; i < 4; i++){
		motor(LEFT, 0);
	    Wait(TURN * b[i]);
		motor(LEFT, RIGHT);
		Wait(a[i]);
	}
	stop();
	return 0;
}

