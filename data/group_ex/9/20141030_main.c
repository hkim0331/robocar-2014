#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Straight(void){
	Mtr_Run_lv(11000,-10000,0,0,0,0);
	 Wait(300);
}
void Stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(1000);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short bw;
  for(;;){
   Straight();
   Stop();
   bw = ADRead(0);
   if(bw>700){
	   break;
   }else{
   ;

  }
  }
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(5000);
  BuzzerStop();
	return 0;
}

