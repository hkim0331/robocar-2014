#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define So 120
#define Si 95

void Play(int pitch){
	BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(1000);
		BuzzerStop();
		Wait(1000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	LED(3);
	Wait(1000);
	int i;
	for(i=0;i<100;i++){
		LED(i%2+1);
		Wait(100);

		if(i%2==0)
			Play(So);
		else
			Play(Si);

	}
LED(0);

	return 0;
}

