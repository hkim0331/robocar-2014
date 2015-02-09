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
	for(i=0;i<100;i++){
		LED((i%2)+1);
		Wait(200);
		if(i%2==0){
			BuzzerSet(95,100);
			BuzzerStart();
			Wait(200);
		}
		else{
			BuzzerSet(120,100);
			BuzzerStart();
			Wait(200);
		    BuzzerStop;
		}





	}
	LED(0);


	return 0;
}

