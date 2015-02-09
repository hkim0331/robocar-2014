#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define VOL 100
#define SO    120
#define SI    95



void play(int pitch)
{

	BuzzerSet(pitch, VOL);
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
	for(i=0;i<100;i++){
		LED(i%2+1);
		if( (i%2)= 0){
			BuzzerSet(95, 100);
			BuzzerStart();
			Wait(100);
			BuzzerStop();
			Wait(100);
		};
		else( (i%2)= 1){
			BuzzerSet(120, 100);
			BuzzerStart();

		};
	}
	BuzzerStop();
	LED(0);

	return 0;
}

