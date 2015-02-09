#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define NN 1
#define XX 0

void play(int pitch,int VOL, int DURATION,int PAUSE){
		if(pitch == NN){
			BuzzerStop();
			Wait(PAUSE);
		}


		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(DURATION);
		BuzzerStop();
}

void kaeru(void){
	int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,NN,DO,NN,DO,NN,DO,NN,DO,DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO};
	int i;
	for(i=0;notes[i]!=XX;i++){
		play(notes[i],100,400,100);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kaeru();
	return 0;
}
