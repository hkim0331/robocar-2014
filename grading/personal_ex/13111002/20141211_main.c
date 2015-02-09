#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void beep(int length) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(length);
  BuzzerStop();
  Wait(100);
}

int average(int a[], int from, int to) {
	int ret=0;
	int i;
	for (i=from; i<to; i++) {
		 a[i] = ADRead(0);
	     Wait(100);
	     ret += a[i];
	     }
	return ret/(to-from);
}

void color(int n) {
      int c[n];
      int i;
      for (i=0;i<n;i++) {}
        c[i] = ADRead(0);
        Wait(100);
       )

int main(void)
{	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int c;
	int d;
	int h;
	while(1)
	{Wait(100);
	LED(3);
	c=color(N);
	d=a/100;
	h=a%10;
 Wait(100);
	  for (i=0; i<d+1; i+=100) {
	    beep(); }
	}
	}

	return 0;
}

