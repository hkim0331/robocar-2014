#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 40
#define SI 95


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	Wait(1000);


	int i;
	for (i=0;1<100;i++){
		LED(i%2+1);
		Wait(100);


		if(i==1){

    BuzzerSet(40, 100);
    BuzzerStart();
    Wait(100);
		}else{
	BuzzerSet(95, 100);
	BuzzerStart();
	Wait(100);

		}








	}
	LED(0);

	return 0;
}

