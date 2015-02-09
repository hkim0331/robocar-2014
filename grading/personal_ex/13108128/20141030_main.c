#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Run(int Right, int Left, int time){

	Mtr_Run_lv(Right, Left, 0, 0, 0, 0); //モーターを最大6個載せられるから６つ
	Wait(time);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	Wait(500); /*1-2*/

	for(i=0;i<100;i++){
		Run(10000,-10000,50);
		Wait(1000);
	}

	return 0;
}
