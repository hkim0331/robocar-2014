#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void Run(int Right, int Left){

	Mtr_Run_lv(Right, Left, 0, 0, 0, 0); //モーターを最大6個載せられるから６つ


}

void Stop(){

	Run(0,0);

}

void Forward(int time){

	Run(500,-500);
	Wait(time);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	while(1){
		Forward(1000);
		Stop();
	}

	return 0;
}

