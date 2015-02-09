#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  9300

#define FW 170

#define N 5

#define TN 8

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void step(int n)
{
  forward(n);
  Wait(10);
}

void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}

void turn(int deg)
{
  motor(LEFT, 0);
  Wait(TN * deg);
  stop();
}

void turn2(int deg)
{
  motor(0, RIGHT);
  Wait(TN * deg);
  stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i=0;
	unsigned short bw;
			while(1){
				i++;
				step(0.5);
				turn2(10);
				stop();
				bw=ADRead(0);
				if(bw>500){
					stop();
					turn(15);
					i=0;
				}
				if(i==10){
						break;
					}
				}
			stop();
			return 0;
}

