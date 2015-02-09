#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void gostraight(void){

	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(5000);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}
void turnleft(void){

	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	Wait(1000);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}



//void set(int){

//	gostraight();
//	turnleft();

//}



int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  gostraight();
  turnleft();
  gostraight();
  turnleft();
  gostraight();
  turnleft();
  gostraight();
  turnleft();
  return 0;
}
//void setではうまく動かなかった
