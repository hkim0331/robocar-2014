#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define s 10000
#define jadge 500

void forward(int n)
{
	Mtr_Run_lv(s,-s,0,0,0,0);
	Wait(n);
}

void turn_left(int n)
{
	Mtr_Run_lv(s,0,0,0,0,0);
	Wait(n);
}

void turn_right(int n)
{
	Mtr_Run_lv(0,-s,0,0,0,0);
	Wait(n);
}

void stop(int n)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(n);
}

int left_is_black()
{
	if (ADRead(0) > jadge) {
		return 1;
	} else {
		return 0;
	}
}

int right_is_black()
{
	return ADRead(1) > jadge;
}

void run(void)
{

	for ( ; ; ) {
		if (left_is_black()) {
			turn_left(1000);
		} else if (right_is_black()) {
			turn_right(1000);

		} else {
			foward(1000);
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
