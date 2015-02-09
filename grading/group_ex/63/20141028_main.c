#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int run(void){
	Mtr_Run_lv(9700,-10000,0,0,0,0);
	Wait(1875);
}

int turn(void){
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(550);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	  Init(MainCycle);
int i;
for(i=0;i<3;i++){
	  run();
	 turn();
}
	  run();
	  Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

