#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 170
#define RE 160
#define MI 142

#define N  5  //読み込み回数

void beep(int p,int q) {
	BuzzerSet(p,100);
	BuzzerStart();
	Wait(q);
	BuzzerStop();
	Wait(200);
}

int sum(int a[], int from, int to) {

	int s=0;
	int i;

	for (i=from; i<to; i++) {
		s += a[i];
	}
	return s;
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

void color(int n) {

	int i,a,b,c;
	int k=average(n);

	a = k/100;
	b = (k%100)/10;
	c = (k%10);

	for (i=0; i<a; i++) {
		beep(DO,200);
	}

	Wait(1000);

	for (i=0; i<b; i++) {
		beep(RE,150);
	}

	Wait(1000);

	for (i=0; i<c; i++) {
		beep(MI,100);
	}

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color(N);

	return 0;
}

/* 黒:863, グレー:485, 緑:238 青:98, 黄色:67, 赤:57, 白:54 */
