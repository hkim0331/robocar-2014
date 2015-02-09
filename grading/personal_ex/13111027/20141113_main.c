#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void buzzer(){
	BuzzerSet(120,100);
	BuzzerStart();
	Wait(3000);
	BuzzerStop();

	BuzzerSet(142,100);
	BuzzerStart();
	Wait(3000);
	BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
    LED(3);
    Wait(1000);
    for (i=0; i<10; i++){
    	LED(( i%2 ) + 1 );
    	Wait(100);

    	buzzer();

    }
	return 0;
}

