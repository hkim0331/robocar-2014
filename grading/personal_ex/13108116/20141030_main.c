#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define right 10000
#define left right*1.06
#define EDGE 30
#define FW 40

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void forward(int n)
{
  motor(left, right);
  Wait(FW/2);
  stop();
}



int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);
  while(0){
  motor();
  Wait(FW);
  stop();
  Wait(FW);
  }


  return 0;
}
