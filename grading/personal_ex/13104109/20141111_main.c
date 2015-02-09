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
	LED((i%2)+1);//i/2のあまりつまり０か１に１をたすから交互に１と２

	if((i%2)+1==1){
		BuzzerSet(142,100);//ミ
			BuzzerStart();
			Wait(500);
			BuzzerStop();
	}else{
		BuzzerSet(179,100);//do
			BuzzerStart();
			Wait(500);
			BuzzerStop();
	}

    Wait(100);
	}
	LED(0);


	return 0;
}

