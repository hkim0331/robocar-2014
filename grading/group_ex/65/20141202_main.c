#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void buzzer1(void)
{
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(300);
	BuzzerStop();
	Wait(300);
}

void buzzer2(void)
{
	BuzzerSet(179,100);
	BuzzerStart();
	Wait(300);
	BuzzerStop();
	Wait(300);
}

void buzzer3(void)
{
	BuzzerSet(120,100);
	BuzzerStart();
	Wait(300);
	BuzzerStop();
	Wait(300);
}
int sum(int a[], int from, int to)
{
	int ret=0;
	int i;

	for (i=from; i<to; i++)
	{
		ret += a[i];
	}
	return ret;
}

int average(void)
{
	int x[5];
	int i;

	for (i=0;i<5;i++)
	{
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}

void color(void)
{
	int i;
	int n=average();

	for (i=0; i<n; i+=100)
	{
		buzzer1();
	}
	int c=n%100;
	for (i=0; i<c; i+=10)
	{
		buzzer2();
	}
	int d=c%10;
	for (i=0; i<d; i+=1)
	{
		buzzer3();
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	color();
	return 0;
}

//赤色160
//白色173
//黄色187
//青色197
//緑色377
//灰色493
//黒色989

