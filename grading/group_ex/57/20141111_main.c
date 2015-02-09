#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

unsigned short left;
unsigned short right;

void step()
{
	  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(150);
}

void hidari(){
	  Mtr_Run_lv(15000, 0, 0, 0, 0, 0);
	  Wait(150);
	  LED(1);
}

void migi(){
	  Mtr_Run_lv(0, -15000 , 0, 0, 0, 0);
	  Wait(150);
	  LED(2);
}

void stop(){
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	  LED(3);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
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
		    if((right>300) && (left>300)){
		    	break;
		    }else{
		    	;
		    }
		    }
	 stop();
	return 0;
}
