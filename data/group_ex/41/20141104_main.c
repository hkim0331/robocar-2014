#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void STEP(void){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(50);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
}

unsigned short left;

#define DURATION 400
#define PAUSE 100
#define VOL 100

int duration = DURATION;
int pause    = PAUSE;



#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define NN    0

#define XX    (-1)

void play(int pitch)
{
    if (pitch == NN) {
        BuzzerStop();
        Wait(duration + pause);
    } else {
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


void kaeru(void)
{
    int notes1[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,XX};
    int notes2[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
    int notes3[]={MI,RE,DO,XX};

    music(notes1);

    duration = DURATION/2;
    pause    = PAUSE/2;
    music(notes2);

    duration  = DURATION;
    pause     = PAUSE;
    music(notes3);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(2000);
	for( ; ; ){
		STEP();
		Wait(500);
		left = ADRead(0);
		if(left>500){
			break;
		}
	}
   kaeru();
   stop();
	return 0;
}

