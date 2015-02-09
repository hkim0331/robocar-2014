#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#difine
#difine DO 179


void play(int pitch)
{
    if (pitch == NN){
    	BuzzerStop();
    	Wait(DURATION + PAUSE);
    }else{
	BuzzerSet(pitch, VOL);
    BuzzerStart();
    Wait(DURATION);
    BuzzerStop();
    Wait(100);
}

void DO(void)
{    
    play(179)
    }

void SO(void)
{    
    play(120)
    }

void RA(void)
{    
    play(107)
    }


void kirakira(void)
{
		int s[]={DO,RE,MI,FA,MI,RE,DO,XX};
		int i;

		for(i=0; s[i]!=XX; i++)
		{
			play(s[i]);
		}

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    kirakira();

    return 0;
}

