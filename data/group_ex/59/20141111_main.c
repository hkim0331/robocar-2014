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
#define OFF 0


int t;



void play(int pitch){

	t=200;
	if (pitch == OFF){
		BuzzerStop();
		Wait(t);
	}else{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	}
}

void kaeru(void)
{


	int notes[]={DO,RE,MI,FA,MI,RE,DO,OFF,MI,FA,SO,RA,SO,FA,MI,XX};
	int i;
	for(i=0; notes[i] !=XX; i++)
	{
		play(notes[i]);
	}

}


void GO(void){
	Mtr_Run_lv(6000, -6000, 0, 0, 0, 0);
}
void STOP(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void migi(void){
	Mtr_Run_lv(-5000, -5000, 0, 0, 0, 0);
}

void hidari(void){
	Mtr_Run_lv(5000, 5000, 0, 0, 0, 0);
}

void slalom(void){

	Wait(100);

		unsigned short left;
		unsigned short right;

		   for( ; ; ) {
		       left = ADRead(0);
		       right = ADRead(1);
		       if (right>500 && left>500){
		    	   STOP();
		    	   kaeru();
		    	   break;

		   } else if (right > 500) {
			   migi();
			   Wait(50);
		   } else if (left > 500){
			   hidari();
			   Wait(50);
		   }else {
			   GO();
		   }

		}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	slalom();

	return 0;
}

