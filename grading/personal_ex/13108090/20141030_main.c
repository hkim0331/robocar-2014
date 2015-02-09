#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Motor(int Right, int Left){
	Mtr_Run_lv(Right, Left, 0, 0, 0, 0);
	Wait(1000/40);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(int i=0;i<100;i++){
		Motor(10000,-10000);
		i;
	}
	return 0;
}

