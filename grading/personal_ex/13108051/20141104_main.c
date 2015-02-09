#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int i;
int step(){
	Mtr_Run_lv(1000,1000,0,0,0,0);

}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	for(i=0;i<1000;i++){
		step();
		Wait(500);
		unsigned short left;
		left = AdRead(1000);

	}


	return 0;
}

