#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void SI(void) {
	BuzzerSet(95, 100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int sum(int a[], int from, int to) {
		int ret = 0;
		int i;
		for (i = from; i < to; i++) {
			ret += a[i];
		}
		return ret;
	}
	int average(void) {
		int x[5];
		int i;
		for (i = 0; i < 5; i++) {
			x[i] = ADRead(0);
			Wait(100);
		}
		return sum(x, 0, 5) / 5;
	}
	void color(void) {
		int i;
		int n = average();
		for (i = 0; i < n; i+=1) {
			SI();

		}
	}
	color();
	return 0;
}
//白　　　50
//赤　　　53
//黄色　　56
//青　　　74
//緑　　　250
//グレー　400
//黒　　　950
