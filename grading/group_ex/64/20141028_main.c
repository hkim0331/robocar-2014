#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


int exp1(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
    Wait(2000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}




int exp2(void)
{
int i;
for(i=0; i<4;i++)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(2344);


	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(800);
}


	Mtr_Run_lv(0,0,0,0,0,0);

return 0;

	}


int main(void)
{
	const unsigned short MainCycle = 60;
    Init(MainCycle);
exp2();



return 0;

}
