#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void){

	Mtr_Run_lv(-30000,30000,0,0,0,0);
	Wait(300);

	}
void migi(void){
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(100);

}

void hidari(void){
	Mtr_Run_lv(10000,10000,0,0,0,0);
		Wait(100);

}

void stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(500);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	    unsigned short left,right;


		while(1){
			left=ADRead(1);
			right=ADRead(0);

			if(right>600 && left>600){
				stop();
			    break;
			}
			else if(left>600){
				hidari();
			}
			else if(right>600){
				migi();
			}
			else{
			    step();
			}




		}






	return 0;
}

