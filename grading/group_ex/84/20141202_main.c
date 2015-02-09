#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void beep100(void){
	BuzzerSet(200,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(300);
}

void beep10(void){
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(300);
}

void beep1(void){
	BuzzerSet(50,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(300);
}

int sum(int a[], int from, int to){
	int ret=0;
	int i;

	for(i=from; i<to; i++){
		ret += a[i];
	}
	return ret;
}

int average(void){
	int x[100];
	int i;

	for(i=0; i<5; i++){
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

		int i,a,b,c,d;
		int n=average();
			a=(n/100);
			b=n-(a*100);
			c=(b/10);
			d=b-(c*10);

		for(i=0; i<a; i++){
			beep100();
		}
		for(i=0; i<c; i++){
			beep10();
		}
		for(i=0; i<d; i++){
			beep1();
		}
	return 0;
}
//青=134
//黄=123
//灰=614
//赤=58
//緑=322

//灰、緑、青、黄、赤
