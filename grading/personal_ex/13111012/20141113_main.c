#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100
#define VOL 100

#define SO    120
#define SI    95

#define XX    (-1)

int duration = DURATION;
int pause    = PAUSE;


void play(int pitch)
{
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(duration);
	BuzzerStop();
	Wait(pause);
	}
}

void music(int notes[])
{
	int i;

	 for (i=0; notes[i]!=XX; i++) {
	        play(notes[i]);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	Wait(1000);
	for (i=0;i<10;i++){
		LED( (i % 2) + 1 );
		Wait(100);
	}
	LED(0);

	return 0;
}

