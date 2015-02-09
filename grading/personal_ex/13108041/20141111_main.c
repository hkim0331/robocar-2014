#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SI 95
#define SO 120

void play(int pitch)
	    {  BuzzerSet(pitch, 100);
	        BuzzerStart();
	        Wait(800);
	        BuzzerStop();
	        Wait(100);
	    }


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	Wait(1000);
	for (i=0; i<100; i++) {
	        LED((i%2)+1);
	        Wait(100);
	}
	    LED(0);




   if(i%2 == 1){
	   play(SO);
   }
   else if(i%2 == 0){
	   play(SI);
   }

	return 0;
}

