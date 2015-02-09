#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
    LED(3);
    Wait(1000);

    for (i=0; i<20; i++) {
        LED((i%2)+1);
        Wait(800);

        if (i%2==0){
        BuzzerSet(95,100);
        BuzzerStart();
        Wait(1000);
        BuzzerStop();
        }
        eles{;
        BuzzerSet(120,100);
        BuzzerStart();
        Wait(1000);
        BuzzerStop();
        }

    }
    LED(0);

    return 0;
}
