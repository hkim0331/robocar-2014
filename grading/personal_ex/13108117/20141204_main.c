#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define powerL 10000
#define powerR 10000

void motor(int motorL, int motorR)
{
	mtr(motorL, -motorR, 0, 0, 0, 0);
}

void go()
{
	motor(powerL, powerR);
}

void stop()
{
	motor(0, 0);
}

void step()
{
		Wait(100);
		go();
		Wait(25);
		stop();
		Wait(100);
}

void forward(int n)
{
	int i;

	for(;;)
	{
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

