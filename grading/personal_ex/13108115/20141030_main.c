#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT	10000
#define RIGHT  10000

void motor(short left, short right)
{
	Mtr_Run_Lv(LEFT, -RIGHT, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0,0);
	Wait(1000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	motor(10000,10000);
	stop();

	return 0;
}

