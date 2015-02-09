#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int a) {
	BuzzerSet(a,100);
	BuzzerStart();
	Wait(100);
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
	int i,j,k;
	int l=average(10);
	int m=l%100;
	int n=m%10;

	for (i=0; i<l; i+=100) {
		LED(1);
		beep(100);
	}
	Wait(500);
	for (j=0; j<m; j+=10) {
		LED(3);
		beep(200);
	}
	Wait(500);
	for (k=0; k<n; k++) {
		LED(2);
		beep(300);
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}
//白60
//赤40
//黄70
//青80
//緑280
//グレー460
//黒900
