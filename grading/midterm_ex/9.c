#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Straight(void){
	Mtr_Run_lv(11000,-10000,0,0,0,0);
}
void Stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(20000);
}
void Right(void){
	Mtr_Run_lv(0,-10000,0,0,0,0);
}
void Left(void){
	Mtr_Run_lv(11000,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short R;
	unsigned short L;
    for(;;){
    	R=ADRead(0);
    	L=ADRead(1);
   if((R>500)&&(L>500)){
	   Stop();

    }else if(R>500){
		   Left();
		   LED(1);
	}else if(L>500){
	      Right();
	      LED(2);

    }else{
		  Straight();
	   }
	  }
	return 0;
}

