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
#define XX -1
#define NN -2

void play(int pitch)
{
	if(pitch==NN){
		BuzzerStop();
		Wait(300);
	}else if(pitch != NN){
		BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(100);
	}
}


void step(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Mtr_Run_lv(10000,-10000,0,0,0,0);

}

/*
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	for(i=0;i<6;i++){
		step();
		Wait(500);
	}
	Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

 */


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;
	for(;;){
		left=ADRead(0);
		if(left<300){
			step();
			Wait(100);
		}
		else{
			Mtr_Run_lv(0,0,0,0,0,0);
			int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
				MI,FA,SO,RA,SO,FA,MI,NN,
				DO,NN,DO,NN,DO,NN,DO,NN,
				DO,DO,RE,RE,MI,MI,FA,FA,
				MI,NN,RE,NN,DO,XX
		};

		int i;
		for(i=0;notes[i] != XX;i++){
			play(notes[i]);
		}
		}
	}


	return 0;
}











