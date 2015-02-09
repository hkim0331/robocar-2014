#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int sound(int x)
{
	BuzzerSet(25*x+95,100);
	BuzzerStart();
}

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    LED(3);
    int i;
    for (i=0; i<100; i++) {
    	sound(i % 2);
        LED((i % 2) + 1);
        Wait(1000);
        BuzzerStop();
    }
    LED(0);
    return 0;
}
