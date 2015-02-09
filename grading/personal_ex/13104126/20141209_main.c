#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

unsigned short left;
unsigned short right;

void step()
{
	  Mtr_Run_lv(7500, -7500, 0, 0, 0, 0);
	  Wait(150);
}

void hidari(){
	  Mtr_Run_lv(15000, 0, 0, 0, 0, 0);
	  Wait(50);
	  LED(1);
}

void migi(){
	  Mtr_Run_lv(0, -15000 , 0, 0, 0, 0);
	  Wait(50);
	  LED(2);
}

void stop(){
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void slow(){
	  Mtr_Run_lv(5000, -5000, 0, 0, 0, 0);
	  LED(3);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    int blacks =0;

	 for( ; ; ){
		        step();
		        left = ADRead(0);
		        right = ADRead(1);
		    if((left>300) && (right<300)){
		    	hidari();
		    }else{
		    	;
		    }
		    if((right>300) && (left<300)){
		    	migi();
		    }else{
		    	;
		    }
		    if((right>200) && (left>200)){
		   		 slow();
		    }else{
		   		;
		    }
		    if((right>500) && (left>500)){
		    	blacks += 1;
		    	if (blacks == 4) {
		    	    migi();
		    	}else{
		    		;
		    	}
		    	if (blacks > 8) {
		    		break;
		    	}
		        }else{
		    	    ;
		        }
		     }
	 stop();
	return 0;
}
