#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

//int main(void)
//{


void beep(void) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

int average(void) {
	int x[5]; //x[0] から始まる５個。配列の最後はx[4]。

	x[0] = ADRead(0);
	Wait(100);
	x[1] = ADRead(0);
	Wait(100);
	x[2] = ADRead(0);
	Wait(100);
	x[3] = ADRead(0);
	Wait(100);
	x[4] = ADRead(0);

	return (x[0]+x[1]+x[2]+x[3]+x[4])/5;
}
void color(void) {
	int i;
	int n=average();

	for (i=0; i<n; i+=100) {
		beep();
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
		int n=average();

	for (i=0; i<n; i+=100) {
		beep();
	}

	return 0;
}




//}

