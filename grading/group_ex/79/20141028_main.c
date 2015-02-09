#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void motor(int x,int y)
{
	Mtr_Run_lv(x,y,0,0,0,0);
}

void ex11(int a)//前進
{
	motor(10000,-9000);
	Wait(a);
}

void ex23(int b)//後退
{
	motor(-10000,9000);
	Wait(b);
}

void ex24(int c)//左回転
{
	motor(10000,10000);
    Wait(c);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=1;i<=4;i++)
		{
		ex11(3300);
		ex24(830);
		}

	Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

