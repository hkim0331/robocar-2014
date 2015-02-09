#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT  10000
#define RIGHT 10000

#define CM 100

#define N 50000

void motor(short left, short right)
{
	Mtr_Run_lv(left,-right,0,0,0,0);
}

void stop(int i)
{
	motor(0,0);
	Wait(1000*i);
}

void step(short s)
{
	motor(LEFT,RIGHT);
	Wait(CM*s);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	unsigned short bw;

	for (i=0;i<N;i++) {
		step(1);
		stop(1);
	}
	BuzzerSet(100,100);
	BuzzerStart();

	return 0;
}

