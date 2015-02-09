#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void beep1(void) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(200);
}

void beep2(void) {
	BuzzerSet(200,100);
	BuzzerStart();
	Wait(200);
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

int average(void) {
	int x[5];
	int i;

	for (i=0;i<5;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}

void color(void) {
	int i;
	int n=average();

	for (i=0; i<n; i+=100) {
		beep1();
	}
	for (i=0; i<(n-100*(n/100)); i+=10) {
		beep2();
	}
}


int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();
	return 0;
}

//kuro 970 kiiro 170 gure- 570 midori 310 mizuiro 190 aka 160
