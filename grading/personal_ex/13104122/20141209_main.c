#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void step(void)
{
	motor(8000,8000);
	Wait(100);

}


void LEFT(void){
	motor(5000, 0);
	Wait(100);

}
void RIGHT(void){
	motor(0, -5000);
	Wait(100);

}
void Read(void){
	unsigned short left,right;
	left = ADRead(0);
	right= ADRead(1);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
    Read();
    for( ; ; ){
    	Read();
		if(left>=700&&right>=700){

			motor(0,0);
		}else if(left>=500&&right>=500){
			motor(4000,4000);


		}else if(left>=500){
			LEFT();

		}else if(right>=500){
			RIGHT();
		}else{
			step();
		}
	}
	return 0;
}
