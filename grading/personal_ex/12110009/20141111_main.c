#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
#define NN (0)
	void play(int pitch)
	{
		if (pitch==NN){
			BuzzerStop();
			Wait(100);
		} else {
		BuzzerSet(pitch,100);
			BuzzerStart();
			Wait(400);
			BuzzerStop();
			Wait(100);
	}
	}

	void siso(void)
	{
		int note[]={(95),(120)};

	int i;
	LED(3);
	Wait(1000);
	for (i=0; i<10; i++) {
		LED((i % 2) + 1);
		Wait(100);

	}
	LED(0);

	return 0;
}
}

