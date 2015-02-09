#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void foward(int t){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(t);
}
void turn_right(void){
	Mtr_Run_lv(0,0,0,0,0,0);
}
void turn_left(void){
	Mtr_Run_lv(0,0,0,0,0,0);
}
void stop(int t){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(t);
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(2000);
	foward(5000);
	stop(0);
	return 0;
}
