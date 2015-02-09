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
#define DO2 90
#define NN 0
#define XX -1

void step(void){
	unsigned short right;
	for( ; ; ){
		right = ADRead(0);
		if(right>800){
			break;
		}
		else{
			Mtr_Run_lv(0,0,0,0,0,0);
			Wait(500);
			Mtr_Run_lv(10000,-10000,0,0,0,0);
			Wait(50);
		}
	}
	Mtr_Run_lv(0,0,0,0,0,0);
}

void play(int pitch){

	if (pitch==NN){
		BuzzerStop();
		Wait(400);
	}
	else{
		BuzzerSet(pitch, 100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(100);
	}

}

void kaeru(void){

	int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,
			NN,DO,NN,DO,NN,DO,NN,DO,NN,DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,XX};
	int i;
	for (i=0;notes[i]!=XX;i++){
			play(notes[i]);
	}

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step();
	kaeru();

	return 0;
}

