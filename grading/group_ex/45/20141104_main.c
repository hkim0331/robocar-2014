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
#define XX -1
#define NO 1

void step(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(29);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(500);
}

void play(int pitch)
{
	BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
}

void kaeru(void)
{
	int notes[]={DO,RE,MI,FA,MI,RE,DO,NO,MI,FA,SO,RA,SO,FA,MI,NO,
			DO,NO,DO,NO,DO,NO,DO,NO,DO,DO,RE,RE,MI,MI,FA,FA,MI,NO,RE,NO,DO,XX};
	int i;
	for(i=0;notes[i] !=XX;i++){
		play(notes[i]);
	}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;

	for(;;){
		step();
		left = ADRead(0);
	if(left>600	){
		Mtr_Run_lv(0,0,0,0,0,0);
		kaeru();
	}
	else{
		;
	}
	}


	return 0;
}

