#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
unsigned short left;
unsigned short right;

void ST(){
Mtr_Run_lv(10000,-10000, 0, 0, 0, 0);
}
void TUL(){
Mtr_Run_lv(100000,0, 0, 0, 0, 0);
Wait(30);
Mtr_Run_lv(0,0, 0, 0, 0, 0);
}
void TUR(){
Mtr_Run_lv(0,10000, 0, 0, 0, 0);
Wait(30);
  Mtr_Run_lv(0,0, 0, 0, 0, 0);
}
int main(void)
{
const unsigned short MainCycle = 60;
Init(MainCycle);
Wait(1000);
for(;;){
  ST();
  left = ADRead(0);
  right = ADRead(1);
  if(300<left){
  TUR();
  }
  if(300<right){
    TUL();
  }
  if((300<left)&&(300<right)){
  break;
  }
  }
Mtr_Run_lv(0, 0, 0, 0, 0, 0);
return 0;
}
