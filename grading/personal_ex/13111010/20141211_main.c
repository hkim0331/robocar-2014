#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define lefteye 0
#define orange 0
#define green 1
#define count 20

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}



int kai(int sum, int ave){
	int hyaku = 0;
	hyaku = sum/100;

	return hyaku;
}

int average(int a[], int from, int to) {
	int ave = 0;
	int sum = 0;
	int d = 0;

	for (d; d<count; d++) {
		sum = a[d];
	}
	ave = sum/count;

	return kai(sum,ave);
}

int color(int n) {
	int c[n];
	int i;

	for (i=0; i<n; i++) {
		c[i]=ADRead(lefteye);
	}

	return average (c, 0, n);
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int ten;

	ten = (average-(kai*100))/10;

	for (int i=0; i<hyaku; i++) {
		beep();
	}

	for (int i=0; i<ten; i++) {
		beep();
	}

	return 0;
}

