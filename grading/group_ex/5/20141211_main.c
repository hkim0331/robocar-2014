#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define lefteye 0
#define orange 0
#define green 1
#define count 20
#define time 500


int average(int a[], int from, int to) {
	int ave = 0;
	int sum = 0;
	int i = 0;

	for (i=0; i<count; i++) {
		sum = sum + a[i];
	}
	ave = sum/count;

	return ave;
}

int color(int n) {
	int c[n];
	int i;

	for (i=0; i<n; i++) {
		c[i] = ADRead(lefteye);
		Wait(50);
	}

	return average (c, 0, n);
}






int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int c;
	int h;
	int d;

	while (1) {
		c = color(count);
		h = c / 100;
		d = c % 10;
		while (h>0) {
			LED(orange);
			Wait(time);
		}
		while (d>0) {
			LED(green);
			Wait(time);
		}
	}



	return 0;
}

