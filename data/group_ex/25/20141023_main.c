
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(void)
{
	Mtr_Run_lv(20000, -20050, 0, 0, 0, 0);
	Wait(1100);
	Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0);
	Wait(500);
}
int main(void)
{
int i;

	const unsigned short MainCycle = 60;
	Init(MainCycle);
BuzzerSet(100,100);
BuzzerStart();
	for(i=0;i<4;i++){
		play();

	}
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	BuzzerStop();
	return 0;

}


