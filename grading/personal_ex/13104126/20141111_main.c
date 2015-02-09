#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define MI  142
#define DO  179

void play(int pitch)
{
	BuzzerSet(pitch, 100);
	BuzzerStart();
    Wait(3000);
    BuzzerStop();
}

void pipo(void)
{
	int notes[]={MI,DO,XX};
	int j;
	for(j=0; notes[j]!=XX; j++){
		play(notes[j]);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    LED(3);
    Wait(1000);
    int i;
    for (i=0; i<100; i++) {
    	LED((i % 2) + 1);
    	pipo();
    	Wait(1000);
    }
    LED(0);
	return 0;
}
