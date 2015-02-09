#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	 Mtr_Run_lv(10030, -10000, 0, 0, 0, 0);
	void step(int step()){
		int i;
		for(i=0;i<6;i++){
			step();
			Wait(500);
		}
	}


	return 0;
}

