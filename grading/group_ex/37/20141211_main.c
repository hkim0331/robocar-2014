#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int n) {
  BuzzerSet(100,300);
  BuzzerStart();
  Wait(n);
  BuzzerStop();
  Wait(200);
}

int sum(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret;
}

int average (void)
{
	int i,x[5];

	for(i=0; i<5; i++)	{
		x[i] = ADRead(0);
		Wait(100);
	}

	return sum(x,0,5)/5;

}

int count(int m,int x)
{
	int i=0,a;
	while(i<x)	{
		i += m;
	}
	a = i/m - 1;

	return a;

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int AED,a,b,i;

	AED = average();

	a = count(100, AED);
	b = count(10, AED - a * 100);


	for(i=0; i<a; i++)	{
		beep(200);
	}

	Wait(1000);

	for(i=0; i<b; i++)	{
		beep(400);
	}


	return 0;
}

