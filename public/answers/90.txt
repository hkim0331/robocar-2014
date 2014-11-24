#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void step(void){
    Mtr_Run_lv(10000,-10000,0,0,0,0);
}


void R(void){
	Mtr_Run_lv(10000,10000,0,0,0,0);
}

void L(void){
    Mtr_Run_lv(-10000,-10000,0,0,0,0);
}

void stop(void){
	 Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);


    unsigned short left;
    unsigned short right;

    for ( ; ; ){

        left = ADRead(1);
        right = ADRead(0);

        if (left < 200 && right < 200){
        	step();
        }

        else if (left < 200 && right > 900 ){
        	R();
        }

        else if (left > 900 && right < 200 ){
			 L();
		 }

        else if (left > 900 && right > 900 ){
        	break;
        }
    }

    stop();
    return 0;
}
