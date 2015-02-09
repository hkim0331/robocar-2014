#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void forward(void)
{
	Mtr_Run_lv(6000,-6300,0,0,0,0);
}

void turn_left(void)
{
	Mtr_Run_lv(8000,0,0,0,0,0);
}

void turn_right(void)
{
	Mtr_Run_lv(0,-8000,0,0,0,0);
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

void run(void)
{
	int left;
	int right;

	int i;
	for(i=0; i<1000; i++){
		left=ADRead(0);
		right=ADRead(1);

                forward();

		if (left>512) {
			turn_left();Wait(1000);
                        LED(1);
		} else if (right>512) {
			turn_right();Wait(1000);
                        LED(2);
		} else if((left>512)&&(right>512)) {
			stop();
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
