#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	int n =(i%2)+1
	LED(3);
	Wait(1000);
	for(i=0;i<10;i++){
		LED((i % 2) + 1);
		Wait(100);
		if(n==1){BuzzerSet(120)}
		else(n==2){BuzzerSet(107);}
		}
	}
    LED(0);

    return 0;
}


