#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define LEFT   10000
#define RIGHT  10000

// 一辺を何センチとするか?
#define EDGE 30

// 何回で一周するか?
#define N 4

// 1cm 進む時間と1度 回る時間(msec)

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

void turn_LEFT(int deg)
{
  motor(LEFT, 0);
  Wait(TN * deg);
  stop();
}
void turn_RIGHT(int deg)
{
  motor(0, RIGHT);
  Wait(TN * deg);
  stop();
}

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);
  int  bw1, bw2;
  while(1)
  {
	  bw1 = ADRead(0);
	  bw2 = ADRead(1);

	  if((bw1<500)&&(bw2<500))
	  {
		forward(2);

	  }

	  if(bw1>500)
	  {
		  turn_LEFT(2);

	  }
	  if(bw2>500)
	  	  {
	  		  turn_RIGHT(2);

	  	  }

	  if((bw1>500)&&(bw2>500)){

		  break;
	  }
  }

  stop();

  return 0;
}
