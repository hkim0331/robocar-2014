#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void MI(void){
	BuzzerSet(142,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}


void DO(void){
	BuzzerSet(90,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);

	int i;
	for (i=0; i<10; i++) {
		LED((i%2)+1);
		Wait(100);
		if(i%2+1==1){
			MI();
		}else{
			DO();
		}
  	    }
	LED(0);

	return 0;
}

