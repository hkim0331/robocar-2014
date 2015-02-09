#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define N 50000

#define FW 37

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void forward(void)
{
  motor(LEFT, RIGHT);
  Wait(FW);
  stop();
}


int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);
  int i;
  for (i = 0; i < N; i++) {
    forward();
  }

  return 0;
}
