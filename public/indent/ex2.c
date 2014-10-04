#include "LPC13xx.h"
 #include "gpio.h"
  #include "vs-wrc103.h"
   #include "ixbus.h"

void forward(int n)
{
int i;
for(i=0;i<n;i++) {
    Mtr_Run_lv(10000,-10000,0,0,0,0);
        Wait(60);}

}

void stop(void) { Mtr_Run_lv(0,0,0,0,0,0);}

void turn(int deg)
{
int i;

	deg=deg/3;
for(i=0;i<deg;i++)
{
Mtr_Run_lv(10000,10000,0,0,0,0);
		Wait(20);
}}
