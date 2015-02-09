#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define DO2 178
#define DO3 177
#define DO4 176
#define RE 160
#define RE2 159
#define RE3 158
#define MI 142
#define MI2 141
#define MI3 140
#define FA 134
#define FA2 133
#define SO 120
#define RA 107
#define SI 95

#define XX (-1)
#define MM 0
#define NN 0


void play(int pitch){
	if(pitch==NN){
		BuzzerStop();
		Wait(200);
	}
	else if(pitch==MM){
		BuzzerStop();
		Wait(1000);
	}
	else if(pitch==DO2){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(500);
		BuzzerStop();
		Wait(250);
	}
	else if(pitch==DO3){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(25);
	}
	else if(pitch==RE2){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(25);
	}
	else if(pitch==MI2){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(25);
	}
	else if(pitch==FA2){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(25);
	}
	else if(pitch==DO4){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
	}
	else if(pitch==RE3){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
	}
	else if(pitch==MI3){
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
	}
	else{
		BuzzerSet(pitch,50);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(50);
	}
}



void kaeru(void){

	int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO2,MM,DO2,MM,DO2,MM,DO2,MM,
			DO3,DO3,RE2,RE2,MI2,MI2,FA2,FA2,MI3,NN,RE3,NN,DO4,XX};
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
	}

}

void step(void)
{
	Mtr_Run_lv(10000,-10700,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}


void ex1(void)
{
	int i;
	for(i=0; i<6; i++)
	{
		step();
		Wait(100);
	}
}


void ex2(void)
{
	unsigned short left;

	for(; ;)
	{
		step();
		Wait(500);
		left=ADRead(0);

		if(left>800 && left<1023)
		{
			kaeru();
			break;
		} else
		{
			;
		}
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex2();

	return 0;
}

