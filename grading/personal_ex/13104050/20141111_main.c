#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 120
#define SI 95


void play(int pitch){
	BuzzerSet(pitch,100);
			BuzzerStart();
			Wait(400);
			BuzzerStop();


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	 LED(3);
	    Wait(500);
	    for (i=0; i<100; i++) {
	    	play(SI);
	        LED(1);
	        Wait(100);
	        play(SO);
	        LED(2);
	        Wait(100);
	    }
	    LED(0);
         //音なる、光る、音なる・・・の繰り返しのような気がする。同時に実行されるのか。
	return 0;
}

