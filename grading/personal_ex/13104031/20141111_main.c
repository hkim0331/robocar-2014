#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);

	LED(3);
	int i;
	for(i=0;i<100;i++){
		LED((i%2)+1);
		Wait(500);
		if(i%2==0){
			BuzzerSet(142,100);
			BuzzerStart();
		}
		if(i%2==1){
			BuzzerSet(120,100);
			BuzzerStart();
		}
	}
	LED(0);


	return 0;
}

