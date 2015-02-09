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
	if (pitch==NN) {
	BuzzerStop();
	Wait(DURATION+PAUSE);
	}
	else {
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(DURATION);
	BuzzerStop();
	Wait(PAUSE);
	}
}

void kaeru(void)
{
	int s[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,
            DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};
	int i;

	for (i=0; s[i]!=XX; i++) {
	        play(s[i]);

	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kaeru();

	return 0;
}

