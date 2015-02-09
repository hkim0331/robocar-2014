#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define HUN 10
#define TEN 7
#define ONE 5
#define AVE 10

void beep(int time, int count) {
	int i;
	for(i=0; i<count; i++){
		BuzzerSet(100,100);
		BuzzerStart();
		Wait(100 * time);
		BuzzerStop();
		Wait(100);
	}
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

int count(int n, int m) {
	return n/m;
}

void count_beep(int n, int m){
	beep(n,m);
	beep(1,5);
	Wait(5000);
}


int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int hun, ten, one;

	hun = count(average(AVE), 100);
	ten = count(average(AVE)-100*hun, 10);
	one = count(average(AVE)-100*hun-10*ten, 1);

	count_beep(HUN,hun);
	count_beep(TEN,ten);
	count_beep(ONE,one);

	return 0;
}

/*
 	 ～計測結果～
 	 黒：870, 白：53, 灰：400, 赤：52, 青：56, 黄：53, 緑：100

 	 ～明るい順～
 	赤、 白、黄、緑、灰、黒
 */
