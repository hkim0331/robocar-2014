#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
unsigned short left,right;
void step1(void){
Mtr_Run_lv(9000, -9000, 0, 0, 0, 0);
	 Wait(60);

}

void step2(void){
	Mtr_Run_lv(9000, 9000, 0, 0, 0, 0);
						  Wait(150);
						  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	 }

void step3(void){
	Mtr_Run_lv(-9000, -9000, 0, 0, 0, 0);
						  Wait(150);
						  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	 }

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for ( ; ; )
	{ step1();
	  left = ADRead(0);
	  right = ADRead(1);
	  if (left>500 && right>500)
	  { break;
	  		   }
	  else if (right>500)
	  { step3();
	  }
	  else if (left>500)
	  { step2();
	  }
	  else { ; }

	}
	 Mtr_Run_lv(0, 0, 0, 0, 0, 0);
 return 0;
}
