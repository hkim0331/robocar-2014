#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define POWER 10000

void forward(int n)
{
	int i;

	for (i=0; i<n; i++) {
		Mtr_Run_lv(POWER,-POWER,0,0,0,0);
		Wait(60);
	}

}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

// wait * MainCycle must be greater than 1000.
void turn(int deg)
{
	int i;

	deg=deg/3;
	for (i=0; i<deg; i++) {
		Mtr_Run_lv(POWER,POWER,0,0,0,0);
		Wait(20);
	}
}

void run(int n, int l)
{
	int i;

	for (i=0;i<n;i++) {
		LED(i);
		Wait(1000);
	}
	for (i=0; i<n; i++) {
		forward(l);
		turn(360/n);
	}
	stop();
	for (i=3; i>=0; i--) {
		LED(i);
		Wait(1000);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run(4, 40);
	return 0;
}

