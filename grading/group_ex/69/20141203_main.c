#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_EYE    0
#define RIGHT_EYE   1

void stop(void)
{
 Mtr_Run_lv(0,0,0,0,0,0);
 }

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


void slalom(void)
{
 unsigned short right,left;
  right = ADRead(1);
  left = ADRead(0);
 LED(3);

 for (;;)
 {
    if (right<=500 && left<=500) {
    	    forward();
    	    stop();
        } else if (right>=500 && left>=500) {
        	stop();
        } else if (left<500) {
        	 turnleft();
        	 stop();
        } else if (right<500) {
            turnright();
            stop();
        } else {
            ;
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
