#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void beep(int t)
{
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(100);
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

int average(int n)
{
	int x[n];
	int i;

	for (i=0;i<n;i++)
	{
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,n)/n;
}


int count100(int n)
{
	return n/100;
}

int count10(int n)
{
	return n/10;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	while (1) {
		int h,d,i;
		LED(3);
		h = count100(average(5));
		d = count10(average(5)-h*100);
		LED(0);
		for (i=0; i<h; i++)
		{
			beep(200);
		}
		for (i=0; i<d; i++)
		{
			beep(50);
		}
	}

	return 0;
}
/*

 */

