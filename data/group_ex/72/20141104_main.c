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
#define XX (-1)
#define OO 0

void play(int pitch)
{
	if (pitch==OO){
		BuzzerStop();
		Wait(500);
	}
	else
    BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}

void music(int notes[])
{
int i;
 for (i=0; notes[i]!=XX; i++){
	 play(notes[i]);
 }

}

void kaeru(void)
    {
	int notes[]={DO,RE,MI,FA,MI,RE,DO,XX};
	music(notes);
    }


void kirakira(void)
{
	int notes[]={DO,DO,SO,SO,RA,RA,SO,XX};
	music(notes);
}

void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
Wait(150);
Mtr_Run_lv(0,0,0,0,0,0);


	}

int i;
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;


	for(; ; ){
		step();
		Wait(500);
		left = ADRead(0);
		if(left>600)
		{
			kaeru();
		}

		if(250< left&&left <500)
		{
			kirakira();
		}
		else
		{
		;
		}
		}
	return 0;
}


