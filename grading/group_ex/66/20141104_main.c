#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void) //5mm前進
{
    Mtr_Run_lv(10000, -10500, 0, 0, 0, 0);
    Wait(50);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}
#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define DO2 90
#define XX (-1)

void play(int pitch)
{
	BuzzerSet(pitch,100);
    BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(100);
}

void kaeru(void)
{
	int notes[]={DO,RE,MI,FA,MI,RE,DO,
			MI,FA,SO,RA,SO,FA,MI,
			DO,DO,DO,DO,
			DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,XX};
	int i;

	for(i=0; notes[i] !=XX; i++)
	{
		play(notes[i]);
	}

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;

	for( ; ; ){
		step();
		Wait(500);
		left=ADRead(0);
		if(800<left && left<1000){
			kaeru();
		}
		else{
			;
		}
	}
	return 0;
}

