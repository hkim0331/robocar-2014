#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100
#define VOL 100


#define DO	179
#define RE	160
#define MI	142
#define FA	134
#define SO	120
#define RA	107
#define SI	95
#define XX	0

#define NN	1

void play(int pitch){
	if(pitch == NN){
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

void kaeru(void)
{
	int notes[]={	DO,RE,MI,FA,MI,RE,DO,NN,
					MI,FA,SO,RA,SO,FA,MI,NN,
					DO,NN,DO,NN,DO,NN,DO,NN,
					DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,XX
	};
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
	}
}
/*
void DO(void) {
	play(179);
}
void LE(void) {
	play(160);
}
void MI(void) {
	play(142);
}
void FA(void) {
	play(134);
}
void SO(void) {
	play(120);
}
void LA(void) {
	play(107);
}
void SI(void) {
	play(90);
}
void DO(void) {
	play(90);
}
 */

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kaeru();
	/*
	DO();
	DO();
	SO();
	SO();
	LA();
	LA();
	SO();
	Wait(500);
	FA();
	FA();
	MI();
	MI();
	LE();
	LE();
	DO();
	Wait(500);
	 */
	return 0;
}

