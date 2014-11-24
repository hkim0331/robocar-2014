#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void MOTOR(short a,short b,int c){
	Mtr_Run_lv(a, b, 0, 0, 0, 0);
    Wait(c);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}


void MASSUGU(void){
	MOTOR(12000,-10000,2200);
}
void MAGARU(void){
	MOTOR(10000,10000,500);
}
void TOMARU(void){
	MOTOR(0,0,1000);
}
int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);
  int i;
  for(i=0;i<4;i++){
  TOMARU();
  MASSUGU();
  TOMARU();
  MAGARU();
  }
  return 0;
}
