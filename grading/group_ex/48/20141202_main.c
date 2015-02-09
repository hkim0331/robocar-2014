#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}


int sum(int a[], int from, int to) {

	int ret=0;
	int i;

	 for (i=from; i<to; i++) {
	    ret += a[i];
	  }
    return ret;

}


int average(int n) {

	int x[n];
	int i;

	for (i=0;i<5;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}

	return sum(x,0,5)/5;
}

void color(void) {

	int i;
	int n=average(5);

	for(i=0;i<n;i+=5) {
		beep();
	}

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();
	return 0;
}

// 白=50　赤=50　黄=55　青=60　緑=155　灰=400　黒=900
