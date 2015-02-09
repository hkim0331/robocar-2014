#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void st(void){

	Mtr_Run_lv(0,0,0,0,0,0);
}

void step(void){

	Mtr_Run_lv(20000,-20000,0,0,0,0);
			Wait(35);
			Mtr_Run_lv(0,0,0,0,0,0);

}

void ex5(void){
	/*arc20*/
	Mtr_Run_lv(12000,0,0,0,0,0);
				Wait(100);
				Mtr_Run_lv(0,0,0,0,0,0);

}

void ex6(void){
	/*arc20*/
	Mtr_Run_lv(0,-12000,0,0,0,0);
				Wait(100);
				Mtr_Run_lv(0,0,0,0,0,0);

}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	unsigned short left;
	unsigned short right;

		for(;;){

		step();
		Wait(500);

		left = ADRead(0);
        right = ADRead(1);


		if(500>left && right<500){

			step();

		}



		else{ if(500>right && left>500){

				ex5();
			}




		else {if(500<right && left<500){
				ex6();

			}


		else {
				break;


			}





		}}}
	return 0;
}

