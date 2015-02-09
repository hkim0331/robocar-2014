#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define MI 142
#define SO 120

void play1(int pitch)
{
	BuzzerSet(142,400);
					BuzzerStart();
					Wait(400);
					BuzzerStop();

}

void play2(int pitch)
{
	BuzzerSet(120,400);
					BuzzerStart();
					Wait(400);
					BuzzerStop();

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);
	int i;
	for (i=0;1<100;i++) {
		LED(i%2+1);
		playi%2+1;
		Wait(400);

	}
LED(0);
	return 0;
}

