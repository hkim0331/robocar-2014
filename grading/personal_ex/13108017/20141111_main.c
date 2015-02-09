#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 120
#define SI 95

void play(int pitch)
{

	BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		Wait(100);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	for(i=0; i<10; i++){
		LED((i % 2) + 1);
	    Wait(100);
	  if(i%2 == 0){
		play(SI);
	  }else if(i%2 == 1){
		play(SO);
	  }

	}
	LED(0);

	return 0;
}

