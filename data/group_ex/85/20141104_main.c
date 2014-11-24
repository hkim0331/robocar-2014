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
#define NN    0

#define XX    (-1)
unsigned short left;

void play(int pitch)
{
    if (pitch==NN) {
        BuzzerStop();
        Wait(DURATION+PAUSE);
    } else {
        BuzzerSet(pitch, VOL);
        BuzzerStart();
        Wait(DURATION);
        BuzzerStop();
        Wait(PAUSE);
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
    int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,
            DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};

  music(notes);
}
void step(void)
{
	Mtr_Run_lv(17500,-20000, 0, 0, 0, 0);
	Wait(50);
	Mtr_Run_lv(0,0,0,0,0,0);

}

void step2(void)
{
	for ( ; ; )
	{
		step();
		Wait(500);
		left = ADRead(0);
		if(left > 700)
		{
			kaeru();
			break;
		}else
		{
			;
		}
	}

}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    step2();

	return 0;
}

