#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void Run(int a, int b, int t){

	Mtr_Run_lv(a, b, 0, 0, 0, 0); //モーターを最大6個載せられるから６つ
	Wait(t);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(500); /*1-2*/

	Run(10000,-10000,1000);


	return 0;
}

