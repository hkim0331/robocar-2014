#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int a) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(a);
	BuzzerStop();
	Wait(100);
}

int sum(int a[], int from, int to) {
	int ret=0;
	int i;

	for (i=from; i<to; i++) {
		ret += a[i];
	}
	return ret;
}

int ave(void) {
	int x[5];
	int i;

	for (i=0;i<5;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}
int count100(int n)
{
	return n/100;
}

int count10(int n)
{
	return (n/10)-(n/100)*10;
}

void color(void) {
	int i;
	int n=ave();
	int h, d;
	h = count100(n);
	d = count10(n);
	for (i=0; i<h; i++) {
		beep(300);
	}
	for(i=0;i<d;i++){
		beep(100);
	}
	return 0;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(;;){
	Wait(1000);
	LED(3);
	color();
	LED(0);
	}
	return 0;
}

/*  黒=900　 グレー=260 　白=40 　 赤=40   　 緑=50  　 黄=40  　 青=40

明るい順　青＝白＝赤＝黄、緑、グレー、黒
*/
