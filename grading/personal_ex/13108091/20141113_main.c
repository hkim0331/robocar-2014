#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define VOL 100
#define SI 95
#define SO 120

void play(int pitch)
{
	BuzzerSet(pitch, VOL);
        BuzzerStart();
        Wait(duration);
        BuzzerStop();
        Wait(pause);
    }
}

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    LED(3);
    Wait(2000);
    int i;
    for (i=0; i<100; i++) {
        LED((i%2)+1);
        BuserSet
        Wait(1000);
    }
    LED(0);
    return 0;
}
