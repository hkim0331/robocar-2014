#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



int step()
{
Mtr_Run_lv(10000,-10000,0,0,0,0);
Wait(300);
Mtr_Run_lv(0,0,0,0,0,0);
return 0;
	}

#define DURATION 500
#define PAUSE 100
#define VOL 100

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define NN   -2

#define XX    (-1)

int duration = DURATION;
int pause    = PAUSE;

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
	unsigned short left;

for(; ;)
{
	step();
Wait(200);

left = ADRead (0);

if(0<left && left<500)break;
}
	kaeru();


	return 0;
}

