#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void step(void)
{
	Mtr_Run_lv (8000,-8000,0,0,0,0);
	Wait(100);

}
void LEFT(void){
	Mtr_Run_lv(5000, 0, 0, 0, 0, 0);
	Wait(100);

}
void RIGHT(void){
	Mtr_Run_lv(0, -5000, 0, 0, 0, 0);
	Wait(100);

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
	unsigned short left,right;
	left = ADRead(0);
	right= ADRead(1);
	for( ; ; ){
		if(left>=700&&right>=700){

			Mtr_Run_lv (0,0,0,0,0,0);
			left = ADRead(0);
			right= ADRead(1);
		}else if(left>=700){
			LEFT();
			left = ADRead(0);
			right= ADRead(1);
		}else if(right>=700){
			RIGHT();
			right= ADRead(1);
			left = ADRead(0);
		}else{
			step();
			right= ADRead(1);
			left = ADRead(0);
		}
	}
	return 0;
}

