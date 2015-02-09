#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int n, int m){
	BuzzerSet(n,100);
	BuzzerStart();
	Wait(m);
	BuzzerStop();
	Wait(m);
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
	for (i=0;i<n;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,n)/n;
}

void color(void) {
	int i;
	int n=average(30);
	for (i=0; i<n; i+=100) {
		beep(179,500);
	}

	for (i=0; i< (n%100); i+=10) {
		beep(142,300);
	}

	for (i=0; i< (n%10); i+=1) {
		beep(120,100);
	}
}
int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}
/*
 黒 862
 灰 420
 緑 190
 青 167
 赤 163
 黄 162
 白 150
 */

