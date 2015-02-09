#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  11000



#define N 100

// 1cm 進む時間と1度 回る時間(msec)
// これらの値は実験で求める。ロボカーによって異なる。
#define FW 40
#define TN 8

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
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}


int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);
  int i;

  unsigned short bw;

  for (i = 0; i < N; i++) {
    forward(1);
    Wait(1000);
    bw=ADRead(0);
    if (bw>500){break;}else
    {
    	;
    }

  }
BuzzerSet(100,100);
BuzzerStart();

  return 0;
}

