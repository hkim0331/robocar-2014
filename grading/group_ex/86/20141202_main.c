#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep1(void){
	BuzzerSet(100,50);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(100);
}
void beep2(void){
	BuzzerSet(150,50);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

int sum(int a[], int from, int to){
	int ret=0;
	int i;

	for(i=from;i<to;i++){
		ret += a[i];
	}
	return ret;
}

int average(int n){
	int x[n];
	int i;

	for(i=0;i<n;i++){
		x[i]= ADRead(0);
		Wait(100);
	}
	return sum(x,0,n)/n;
}

void color(void){
	for(;;){
		int i;
		int n=average(10);
		LED(3);
		Wait(1000);
		LED(0);

		for(i=0;i<n;i+=100){
			beep1();
		}
		Wait(500);
		for(i=0;i<n%100;i+=10){
			beep2();
		}
	}
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	color();

	return 0;
}
/*黒:990　　赤:150　　黄:160　　緑:180　　青:160　　グレー:440   白:150*/
