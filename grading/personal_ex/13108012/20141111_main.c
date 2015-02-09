#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);//緑のLED点滅
	Wait(1000);
	for(i=0;i<10;i++){
		LED((i%2)+1);
		if(i%2+1==2){
			BuzzerSet(95,100);
			BuzzerStart();
			Wait(1000);
		}else if(i%2+1==3){
			BuzzerSet(120,100);
			BuzzerStart();
			Wait(1000);
		}else{
			;
		}

		BuzzerStop();
	}
	LED(0);
	return 0;
}

