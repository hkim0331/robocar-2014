#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define	right	10000
#define	left	-10600
#define	gotime	2700
#define	righttime	1100


void Go(int wt)
{
	Mtr_Run_lv(right,left,0,0,0,0);
	Wait(wt);
}

void TurnRight(int wt)
{
	Mtr_Run_lv(0,left,0,0,0,0);
	Wait(wt);
}

void TurnLeft(int wt)
{
	Mtr_Run_lv(right,0,0,0,0,0);
	Wait(wt);
}
void Back(int wt)
{
	Mtr_Run_lv(-right,-left,0,0,0,0);
	Wait(wt);
}
void Stop(int wt)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(wt);
}

void Squar(void)
{
	int i;
	for(i=0;i<3;i++){
		Go(gotime);
		TurnRight(righttime);
	}
	Go(gotime);
	Stop(100);


}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Stop(1000);
	Squar();


	return 0;
}

