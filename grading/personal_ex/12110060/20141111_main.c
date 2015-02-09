#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define VOL 100
#define SO    120
#define SI    95


void play(int pitch)
{
        BuzzerSet(pitch, VOL);
        BuzzerStart();
        BuzzerStop();
        Wait(PAUSE);
    }

void sairen(void)
{
    int notes[]={SI,SO};
    int i;
    for (i=0; notes[i]; i++) {
        play(notes[i]);
    }
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	for (i=0; i<10000; i++){
	LED( (i%2) +1);
	Wait(500);

	}

	LED(0);

	return 0;
}

