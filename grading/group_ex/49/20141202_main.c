#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
	BuzzerSet(100,100);
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

int average() {
	int x[100];
	int i;

	for (i=0;i<100;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,100)/100;
}

int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int n = average();
	int i;

	for (i=0; i<n; i+=15) {
		beep();
	}
	return 0;
}

//白　１５＊４＝６０
//赤　１５＊５＝７５
//黄　１５＊６＝９０
//青　１５＊７＝１０５
//緑　１５＊１９＝２８５
//灰　１５＊３６＝５４０
//黒　１５＊６０＝９００
