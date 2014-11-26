

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

	unsigned short color0,color1;

	int i=1;

	while(i){

		color0 = ADRead(0); //左
		color1 = ADRead(1);	//右

		if(color0 < 500 && color1 <500){
			Run(10000,-10000,20);
		}
		else if(color0 >500 && color1 <500){
			Run(10000,10000,20);
		}
		else if(color0 <500 && color1 >500){
			Run(-10000,-10000,20);
		}
		else if(color0 >500 && color1 >500){
			Run(0,0,20);
			break;
		}

	}
	return 0;
}
