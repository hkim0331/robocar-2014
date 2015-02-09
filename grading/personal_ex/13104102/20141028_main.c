#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void strait(int time){
	 Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(time);
	  Mtr_Run_lv(0,0, 0, 0, 0, 0);

}
void trcR (int time){
	 Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
		  Wait(time);
		  Mtr_Run_lv(0,0, 0, 0, 0, 0);
}
void trcL (int time){
	 Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0);
			  Wait(time);
			  Mtr_Run_lv(0,0, 0, 0, 0, 0);
}
void back(int time){
	 Mtr_Run_lv(-10000, 10000, 0, 0, 0, 0);
			  Wait(time);
			  Mtr_Run_lv(0,0, 0, 0, 0, 0);
}
void stop(int time){
	Mtr_Run_lv(0,0, 0, 0, 0, 0);
	Wait(time);
}
int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);



  return 0;
}
