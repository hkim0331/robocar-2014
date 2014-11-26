#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	  Mtr_Run_lv(10000, -9600, 0, 0, 0, 0);/*真っ直ぐ*/
	  Wait(2500);
	  Mtr_Run_lv(0, 0, 0, 0, 0 ,0);

	  Wait(1000);

	  Mtr_Run_lv(10000, 0, 0, 0, 0, 0);/*回転*/
	  Wait(1265);
	  Mtr_Run_lv(0, 0, 0, 0, 0 ,0);



	  Mtr_Run_lv(10000, -9600, 0, 0, 0, 0);
	 	  Wait(2500);
	 	  Mtr_Run_lv(0, 0, 0, 0, 0 ,0);

	 	  Wait(1000);

	 	  Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	 	  Wait(1265);
	 	  Mtr_Run_lv(0, 0, 0, 0, 0 ,0);

	 	 Mtr_Run_lv(10000, -9600, 0, 0, 0, 0);
	 		  Wait(2500);
	 		  Mtr_Run_lv(0, 0, 0, 0, 0 ,0);

	 		  Wait(1000);

	 		  Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	 		  Wait(1265);
	 		  Mtr_Run_lv(0, 0, 0, 0, 0 ,0);

	 		 Mtr_Run_lv(10000, -9600, 0, 0, 0, 0);
	 			 		  Wait(2500);
	 			 		  Mtr_Run_lv(0, 0, 0, 0, 0 ,0);






	return 0;
}

