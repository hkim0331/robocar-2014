#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void motor (short L,short R)
{
	 Mtr_Run_lv(L,R,0,0,0,0);
}

void forward(void)
{
	motor(10000,-10000);
}

void turn_left(void)
{
	motor(5000,0);
}

void turn_right(void)
{
	motor(0,-5000);
}

void stop(void)
{
	motor(0,0);
}

void run(void)
{
	int left;
	int right;

	for(;;){
		left=ADRead(0);
		right=ADRead(1);
		if (left>512 && right<512) {
			turn_left(); Wait(50);
		} else if (right>512 && left<512) {
			turn_right(); Wait(50);
		} else if(left>512 && right>512){
		  stop(); Wait(1000); break;
		}
		else {
			forward();
			}



		}

	}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}

