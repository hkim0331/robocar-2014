#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 120
#define SI 95
#define XX (-1)
#define NN 0

void play(int pitch)
{
	if(pitch==NN)
	{
		BuzzerStop();
		Wait(100);
	}
}

void oto(void)
{
	   int notes[]={SI,NN,SO,XX};
		    int i;

		   	    for (i=0; notes[i]!=XX; i++) {
		   	        play(notes[i]);
		   	    }
}

void ex1(void){
	int i;
	LED(3);
	Wait(1000);
	for(i=0; i<100; i++)
	{
		LED( (i % 2) + 1);
		Wait(100);
	}
	LED(0);
}

void ex2(void)
{
	int i;
	LED(3);
	Wait(1000);
	for(i=0; i<100; i++)
	{
		oto();
		LED( (i % 2) + 1);
		Wait(100);
	}
	LED(0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


oto();

	return 0;
}

