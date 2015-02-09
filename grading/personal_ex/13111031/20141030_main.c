#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Straight(void){
	Mtr_Run_lv(10000,-7000,0,0,0,0);
}
void Stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
  for(;;){
   Straight();
    Wait(100);
   Stop();
    Wait(1000);

  }

	return 0;
}

