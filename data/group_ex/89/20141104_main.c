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
#define DO2   90
#define NN    0

#define XX    (-1)

#define fw 100 //1cm time



void SW(void)
{
	for(;;){
		if(getSW() == 1){
			Wait(1000);
			break;
		}
	}
}

void run(int right, int left, int time)
{
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
	Wait(time);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void step(void)
{
	run(10000, 10000, fw/2);
}

void stop(void)
{
	run(0,0,0);
}


void play(int pitch)
{
    if (pitch==NN) {
        BuzzerStop();
        Wait(PAUSE);
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





int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;

	SW();
	Wait(1000);

	for(;;){
		left = ADRead(0);
		if(left < 512){
			step();
			Wait(500);
		} else {
			stop();
			break;
		}
	}

	kaeru();


	return 0;
}

