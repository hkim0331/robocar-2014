#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch){
	BuzzerSet(pitch, 100);
		BuzzerStart();
		Wait(1000);
		BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	Wait(2000);

    for (i=0; i<100; i++) {
        LED(1);
        play(95);
        LED(2);
        play(120);
    }
    LED(0);

	return 0;
}

