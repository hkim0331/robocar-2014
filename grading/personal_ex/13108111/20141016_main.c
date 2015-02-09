

#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DURATION 400
#define PAUSE 100
#define VOL 100

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95

#define NN    1

#define XX    0

void play(int pitch)
{
	if  (pitch== NN){
	BuzzerStop();
	Wait(DURATION+PAUSE);
	}else{
    BuzzerSet(pitch, VOL);
    BuzzerStart();
    Wait(DURATION);
    BuzzerStop();
    Wait(PAUSE);
	}
}

void gerogero(void)
{
    int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,FA,SO,FA,MI,NN,
    				DO,NN,DO,NN,DO,NN,DO,};
    int i;

    for (i=0; notes[i]!=XX; i++) {
        play(notes[i]);
    }
}

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    gerogero();

    return 0;
}
