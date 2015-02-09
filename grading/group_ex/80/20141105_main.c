#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define PAUSE 200
#define DURATION 400
#define VOL 100

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define Do 90
#define ZZ (-1)
#define NN (-10)


int pause=PAUSE;
int duration=DURATION;

void play(int pitch)
{
	if(pitch==NN) {
		Wait(400);
	}
	else {
	BuzzerSet(pitch,VOL);
BuzzerStart();
Wait(duration);
BuzzerStop();
Wait(pause);
}
}


void motor(short right, short left) {
	Mtr_Run_lv(right,-left,0,0,0,0);
}


void stop(void) {
	motor(0,0);
	Wait(500);
}


void step(void) {
	motor(10000,9500);
	Wait(50);
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int note1[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,NN,ZZ};
	int note2[]={DO,NN,DO,NN,DO,NN,DO,NN,ZZ};
	int note3[]={DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,ZZ};

	int i;


	unsigned short left;

	    for( ; ; ) {
	        step();
	        stop();

	        left = ADRead(0);

	        if (left>700) {
	        	for(i=0; note1[i] != ZZ; i++)
	        		{
	        			play(note1[i]);
	        		}

	        		duration=450;

	        		for(i=0; note2[i] != ZZ; i++)
	        			{
	        				play(note2[i]);
	        			}
	        		duration=200;

	        		for(i=0; note3[i] != ZZ; i++)
	        			{
	        				play(note3[i]);
	        			}
	        	}

	        	else if (300<left && left<=700) {
	        		;
	        	}

	        	else {
	        		;
	        	}

	    }


	return 0;
}

