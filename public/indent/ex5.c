#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define P 10000
#define THRES 512

void forward(int n)
{
	Mtr_Run_lv(P,-P,0,0,0,0);
	Wait(n);
}

void backward(int n)
{
	Mtr_Run_lv(-P,P,0,0,0,0);
	Wait(n);
}

void turn_left(int n)
{
	Mtr_Run_lv(P,0,0,0,0,0);
	Wait(n);
}

void turn_right(int n)
{
	Mtr_Run_lv(0,-P,0,0,0,0);
	Wait(n);
}

void stop(int n)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(n);
}

int left_is_black()
{
	if (ADRead(0) > THRES) {
		return 1; // true
	} else {
		return 0; // false
	}
}

int right_is_black()
{
	return ADRead(1) > THRES;
}

void run(void)
{
	
	for ( ; ; ) {
		if (left_is_black()) {
			turn_left(1000);
		} else if (right_is_black()) {
			turn_right(1000);
		} else if (left_is_black() && right_is_black()) {
			backward(1000);
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
