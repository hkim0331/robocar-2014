#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179

int buzzer(int n)
{
	BuzzerSet(DO, 100);
	BuzzerStart();
	Wait(n);
	BuzzerStop();
	Wait(100);
}

int sum(int from, int to, int a[])
{
	int i, ret=0;

	for(i=from; i<to; i++)
	{
		ret+=a[i];
	}

	return ret;
}

int average()
{
	int x[10], i;

	for(i=0; i<10; i++)
	{
		x[i] = ADRead(0);
		Wait(100);
	}

	return sum(0, 10, x)/10;
}

int count(int n, int m)
{
	int i;

	for(i=0; i<n; i+=100)
	{
		buzzer(500);
	}
	Wait(500);
	for(i=0; i<m; i+=10)
	{
		buzzer(100);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int n, m;

	n = average();
	m = n-(n/100)*100;

	count(n, m);

	return 0;
}

/*
黒　９６０
灰　５９０
緑　３６０
黄色　２２０
青　１８０
赤　１６０
白　１６０
 */
