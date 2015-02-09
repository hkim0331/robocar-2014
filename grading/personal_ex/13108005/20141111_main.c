#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



SI(void)
{
	BuzzerSet(95,100);
	BuzzerStart();
	Wait(500);
	BuzzerStop();
	Wait(500);

}
SO(void)
{
	BuzzerSet(120,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(100);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	Wait(1000);
    for( i=0 ; i<10 ; i++ ){
    	LED(1);
    	Wait(300);
    	SI();
    	LED(2);
    	Wait(300);
    	SO();


    }


	return 0;
}

