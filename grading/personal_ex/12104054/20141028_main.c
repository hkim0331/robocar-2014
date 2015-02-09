#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void go(void){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);

}
void tleft(void){
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);

}
void back(void){
	Mtr_Run_lv(-10000, 10000, 0, 0, 0, 0);

}
void stop(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
	back();
	Wait(500);
	stop();
	 return 0;
}

