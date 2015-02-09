#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void soundi(int a)
{
	if(a == 1){
		BuzzerSet(95,100)
		BuzzerStart()
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
    Wait(2000);
	for (i=0;i<30;i++) {
		LED(i%2+1);
		Wait(1000);


	}
	LED(0);


	return 0;
}

