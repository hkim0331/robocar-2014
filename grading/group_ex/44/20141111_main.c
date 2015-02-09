#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left, right;

	 for(;;){
		    left = ADRead(0);
		 	right = ADRead(1);

	    	 if((left>600)&&(right>600)){
	    	 			break;
	    	 		}
	    	 else if(left>600){
	    		 Mtr_Run_lv(7500, 7500, 0, 0, 0, 0);
	    		     LED(2);

			 }
			 else if(right>600){
				 Mtr_Run_lv(-7500, -7500, 0, 0, 0, 0);
					 LED(1);

			 }

		     else {
		    	 Mtr_Run_lv(7500, -7500, 0, 0, 0, 0);
		    	 Wait(50);
		    			  LED(0);

		     }
	     }

	     Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	     LED(3);

	return 0;
}


