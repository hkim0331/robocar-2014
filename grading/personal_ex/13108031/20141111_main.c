#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void SI(void)
{ BuzzerSet(95, 100);
BuzzerStart();
Wait(100);

}
void SO(void)
{ BuzzerSet(120, 100);
BuzzerStart();
Wait(100);


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
	LED (3);
	Wait (100);
	for(i=0;i<100;i++){
		LED(1);
		SI();
		LED(2);
		SO();

		}
	}

	return 0;
}

