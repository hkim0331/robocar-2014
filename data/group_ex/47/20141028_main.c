#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void STOP(void)
{Mtr_Run_lv(0,0,0,0,0,0);
Wait(2000);
}

void STRAIGHT(void)
{Mtr_Run_lv(10000, -10000,0,0,0,0);
Wait(1700);
}
void CURVE(void)
{Mtr_Run_lv(0, -10000,0,0,0,0);
Wait(650);
}
void FINISH(void)
{Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	STOP();
    STRAIGHT();
    CURVE();
    STRAIGHT();
    CURVE();
    STRAIGHT();
    CURVE();
    STRAIGHT();
    FINISH();

    return 0;
}

