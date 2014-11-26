#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void str (void){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
    Wait(100);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void turL(void){
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
		  Wait(100);
		  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void turR(void){
	Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0);
		  Wait(100);
		  Mtr_Run_lv(0, 0, 0, 0, 0, 0);


}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
		unsigned short right;

	for(;;){

		left=ADRead(0);
		 right=ADRead(1);


    if((left<300)&&(right<300)){
    	str();
    }

    if((left>300)&&(right<300)){
    	turL();
    }
    if((left<300)&&(right>300)){
       	turR();
    }
    if((left>300)&&(right>300)){
        	break;
        }


	}
	 Mtr_Run_lv(0, 0, 0, 0, 0, 0);



	return 0;
}

