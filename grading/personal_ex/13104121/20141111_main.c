#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);

	int i;
	for(i=0;i<10;i++){
		if((i%2)+1==1){
			LED(1);
			BuzzerSet(142, 100);
			BuzzerStart();
			Wait(300);
		}

		else{
			LED(2);
			BuzzerSet(179, 100);
			BuzzerStart();
			Wait(300);

		}

	}

	LED(0);

	return 0;
}

