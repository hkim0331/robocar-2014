#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define W 300
#define pitch 100
#define VOL 100
#define LEFT 0
#define LR 3
#define NONE 0
#define G 1

void beep(void) {
	BuzzerSet(pitch,VOL);
	BuzzerStart();
	Wait(W);
	BuzzerStop();
	Wait(W);
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

		x[i] = ADRead(LEFT);
		Wait(W);
	}
	return sum(x,0,5)/5;
}

void color(void) {
	int i;
	int n=average();

	while(n>=100) {
		LED(LR);
		Wait(W);
		LED(NONE);
		Wait(W);
		n-=100;
	}
	while(n>=10){
		LED(G);
		Wait(W);
		LED(NONE);
		Wait(W);
		n-=10;
	}
	for(i=0;i<n;i++){
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

//黒:800 , 灰色:282 , 緑:110 , 水色:51 , 赤:49 , 白:48 , 黄色:48
