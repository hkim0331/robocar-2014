#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10	//取得したい回数
#define H_LONG 600	//百の位のブザーの長さ
#define D_LONG 300	//十の位のブザーの長さ


void beep(int t) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(100);
}

int count(int x, int y){
	int i;
	for(i=0;i<10;i++){
		if(x<y){
			break;
		}else{
			x -= y;
		}
	}
	return i;
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
	int x[N];
	int i;

	for (i=0;i<N;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,N)/N;
}

void output(int h, int d){
	int i;
	for (i=0; i<h; i++) {
			beep(H_LONG);
		}

		Wait(1000);

		for (i=0; i<d; i++) {
			beep(D_LONG);
		}
}

void color(void) {
	int h, d;
	int n=average();

	h = count(n, 100);
	d = count(n-100*h, 10);

	output(h, d);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}

/*
 white	50
 red	50
 yellow	50
 blue	60
 green	130
 gray	600
 black	810
 	 	 [point]
 */
