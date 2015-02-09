#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_EYE    0
#define RIGHT_EYE   1

void forward(void)
{
 Mtr_Run_lv(5000,-5000,0,0,0,0);
 Wait(30);
 Mtr_Run_lv(0,0,0,0,0,0);
}

void turnright(void)
{
	Mtr_Run_lv(5000,-10000,0,0,0,0);
	 Wait(30);
	 Mtr_Run_lv(0,0,0,0,0,0);
}

void turnleft(void)
{
	Mtr_Run_lv(10000,-5000,0,0,0,0);
	 Wait(30);
	 Mtr_Run_lv(0,0,0,0,0,0);
 }

void stop(void)
{
 Mtr_Run_lv(0,0,0,0,0,0);
 }

void slalom(void)
{
 int i;
 LED(3);
 for(i=0;i<100000;i++){
  unsigned short right,left;
  right = ADRead(1);
  left = ADRead(0);

  if(right<=500){
   if(left<=500){
	forward();
    }else{
     LED(1);
     turnleft();
     }
   }else{
	if(left<=500){
	 turnright();
	 LED(2);
	}else{
	stop();
	}
   }
 }
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    slalom();

    return 0;
}
