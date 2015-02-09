#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

unsigned short left;
unsigned short right;

void ST()
{
	Mtr_Run_lv(10000, -9500, 0, 0, 0, 0);
	Wait(150);
}

void stop()
{
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void LF()
{
	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	Wait(150);
	LED(1);
}

void RT()
{
	Mtr_Run_lv(0, -9500, 0, 0, 0, 0);
	Wait(150);
	LED(2);
}

void slow()
{
	Mtr_Run_lv(5000, -5000, 0, 0, 0, 0);
	LED(3);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    unsigned short left;

	  for( ; ; ) {
	    ST();

	     left = ADRead(0);
         right= ADRead(1);

	    if((left>300)&&(right<300)){
          LF();
	     } else {
	       ;
	     }
	     if((left>300)&&(right<300)){
           RT();
         }else{
           ;
         }
	     if((left>200)&&(right>200)){
	        slow();
	     }else{
	                ;
         if((left>300)&&(right>300)){
            break;
         }else{
           ;
         }
         }
        stop();
	return 0;
}



