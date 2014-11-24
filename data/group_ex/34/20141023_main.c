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

	Wait(500); /*1-2*/

	/*Run(10000,-10000,1000);  22cm*/

	int i;

	for(i=1;i<=4;i++){
		Run(10000,-10000,980);/*直進*/
		Run(10000,0,700);/*左回転*/
	}



	return 0;
}

