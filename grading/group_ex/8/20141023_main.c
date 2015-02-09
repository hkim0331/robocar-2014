#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void straight(void)
{

	 Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(1800);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);


}

void turn(void)

{
	Mtr_Run_lv(20000, 0, 0, 0, 0, 0);
		  Wait(320);
		  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	straight();
	turn();
	straight();
	turn();
	straight();
	turn();
	straight();


	return 0;
}

