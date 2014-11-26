#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO  179
#define RE  160
#define MI  142
#define FA  134
#define SO  120
#define RA  107
#define SI  95
#define DO2 90
#define YY  0

#define XX -1

unsigned short left;

void step()
{
	  Mtr_Run_lv(10000, -9500, 0, 0, 0, 0);//5mm前進
	  Wait(100);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void play(int pitch)
{
	if(pitch == YY){
		BuzzerStop();
		Wait(300);
	}
	BuzzerSet(pitch, 100);
	BuzzerStart();
    Wait(300);
    BuzzerStop();
}

void kaeru(void)
{
	int notes[]={DO,RE,MI,FA,MI,RE,DO,YY,MI,FA,SO,RA,SO,FA,MI,YY,DO,YY,DO,YY,DO,YY,DO,YY,DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,XX};
		int i;
		for(i=0;notes[i]!=XX;i++){
			play(notes[i]);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;

	Init(MainCycle);
	    for( ; ; ){
	        step();
	        Wait(500);
	        left = ADRead(0);
	    if(left>800){
	    	break;
	    }else{
	    	;
	    }
	    }
	    kaeru();

	    return 0;
	}
