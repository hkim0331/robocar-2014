#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DO 169
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define DO2 90
#define XX -1
#define YY 1

void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(500);
	BuzzerStop();

	Wait(100);
}

void kaeru(void)
{
	int notes[]={DO,RE,MI,FA,MI,RE,DO,YY,
				MI,FA,SO,RA,SO,FA,MI,YY,
				DO,YY,DO,YY,DO,YY,DO,YY,
				DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,XX
				};

	int i;
	for(i=0;notes[i]!=XX;i++){
		play(notes[i]);
	}
}
void step(void){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);//13cm/s
		  Wait(1000/13);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	    for( ; ; ) {
	        step();
	        Wait(1000);
	        left = ADRead(0);
	        if(left>300){
	        	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	        	kaeru();
	        	break;
	        }else{
	        	;
	        }
	    }
	    return 0;
	}
