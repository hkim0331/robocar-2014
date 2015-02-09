#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int n) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(n);
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

int average(void) {
	int x[5];
	int i;

	for (i=0;i<5;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
		return sum(x,0,5)/5;
}

int count(int m, int n)
{
	int i;
	for (i=0;i<10;i++){
		if (n<m){
			break;
		}else{
			n -= m;
		}
	}
	return i;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int x;
	int h;
	int d;
	int i,j;
	x = average();
	h = count(100,x);
	d = count(10,x-100*h);

	Wait(1000);
	for(i=0;i<h;i++)
	{
		beep(500);
	}
	for(j=0;j<d;j++)
	{
		beep(100);
	}

	return 0;
}

/* 白40、赤50、黄50、青50、緑140、グレー400、黒890 */
