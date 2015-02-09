#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SI (95)
#define SO (120)

void play(int pitch){
	BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	int i;
	LED(3);
	Wait(1000);
	for(i=0; i<10; i++){
	LED(1);
	Wait(400);
	play(SI);
	Wait(400);
	LED(2);
	Wait(400);
	play(SO);
	Wait(400);

	}
	return 0;
}





