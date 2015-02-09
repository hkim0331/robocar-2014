#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define MI 142

void beep(int pitch) {
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(500);
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

void color(void) {
	int i, j, k, n;

	for (;;) {
		Wait(1000);
		n = average(10);
		for (i=0; i<n; i += 100) {
			beep(DO);
		}
		Wait(300);
		for (j=0; j<((n/10)%10); j++) {
			beep(RE);
		}
		Wait(300);
		for (k=0; k<(n%10); k++) {
			beep(MI);
		}
	}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}
//黒 944 灰色 274 緑 207 赤 197 青 197 黄色 196 白 196
