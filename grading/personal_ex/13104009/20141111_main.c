#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DO 179
#define MI 142

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	Wait(1000);
	int i;
	for(i=0;i<10;i++){
		LED((i%2)+1);
		Wait(100);
	}
	void play(int pitch)
	{
		BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(1000);
		BuzzerStop();
		Wait(100);
	}
	int notes[] = {MI,DO,MI,DO,MI,DO,MI,DO,MI,DO,XX};

	for(i=0;i<10;i++){
		play(note[i]);

	}
	LED(0);

	return 0;
}

