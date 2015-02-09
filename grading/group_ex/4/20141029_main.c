#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 10000
#define KYORI 30
#define KAKUDO 90
#define N 4


#define CM1 50
#define TL1DO 8

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0,0);
}

void zensin(int n)
{
	motor(LEFT, RIGHT);
	Wait(CM1 * n);
	stop();
}

void turnl(int kakudo)
{
	motor(LEFT, 0);
	Wait(TL1DO * kakudo);
	stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Int i;
	for (i = 0; i < N; i++){
		zensin(KYORI);
		turnl(KAKUDO);
	}

	return 0;
}




