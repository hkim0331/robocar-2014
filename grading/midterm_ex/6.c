#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define R  1000
#define CM 70
#define PAUSE 0

#define LEFT 10000
#define RIGHT -11000

#define THRES 500



void forward(void)
{
	Mtr_Run_lv(15000,-15000,0,0,0,0);
}

void turn_left(void)
{
	Mtr_Run_lv(5000,0,0,0,0,0);
}

void turn_right(void)
{
	Mtr_Run_lv(0,-5000,0,0,0,0);
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}




void slalom(void)
{
	int x,y;

	while (1) {

		x = ADRead(0);
		y = ADRead(1);

		if (x>THRES&&y>THRES) {        ///黒黒
			stop();Wait(250); break;
		}
		if (x>THRES&&y<THRES) {         //黒白
			turn_left();Wait(50);

		}
		if (x<THRES&&y>THRES) {         //白黒
			turn_right();Wait(50);

		}
		if (x<THRES&&y<THRES) {         //白白
			forward();

		}


	}

}



int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);
	slalom();

	return 0;
}
