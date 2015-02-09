#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 90
#define UN 0
#define XX (-1)

int duration = DURATION;
int pause = PAUSE;

void play(int pitch)
{
	 if (pitch == UN) {
	        BuzzerStop();
	        Wait(duration + pause);
	    } else {
	        BuzzerSet(pitch, 100);
	        BuzzerStart();
	        Wait(duration);
	        BuzzerStop();
	        Wait(pause);
	    }
}

void listen(int notes[])
{
	int i;

	for (i=0; notes[i]!=XX; i++) {
	         play(notes[i]);
	     }
	 }

void kaeru(void)
{
	int notes1[]={DO,RE,MI,FA,MI,RE,DO,UN,
			MI,FA,SO,RA,SO,FA,MI,UN,
			DO,UN,DO,UN,DO,UN,DO,UN,XX};

	int notes2[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};

	int notes3[]={MI,RE,DO,XX};

	listen(notes1);

	duration = DURATION/2;
	pause = PAUSE/2;
	listen(notes2);

	duration = DURATION;
	pause = PAUSE;
	listen(notes3);

}



void step(void)
{
	Mtr_Run_lv(10000,-17000,0,0,0,0);
	Wait(200);
	Mtr_Run_lv(0,0,0,0,0,0);

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;

	for(;;){
    step();
    Wait(500);
    left = ADRead(0);
    if(left>600)
    {
    	kaeru();
    	break;
    }
    else
    {
    	;
    }

    }


	return 0;
}

