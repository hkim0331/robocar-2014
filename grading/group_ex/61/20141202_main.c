#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160

void play(int pitch){
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}
int sum(int a[],int ku,int wa){
	int ta=0;
	int i;

	for(i=ku;i<wa;i++){
		ta += a[i];
	}
	return ta;
}

int average(int n){
	int x[n];
	int i;

	for(i=0;i<n;i++){
		x[i]=ADRead(0);
		Wait(100);
	}
	return sum(x,0,n)/n;
}

void color(void){
	int i,k;
	int n=average(10);

	for(i=0;i<n;i+=100){
		play(DO);
	}

	for(k=0;k<n%100;k+=10){
		play(RE);
	}
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(;;){
		color();
		Wait(200);
	}
	return 0;
}
//白=140、赤=150、黄色=150、青=150、緑=160、ぐれー=310、黒=860
