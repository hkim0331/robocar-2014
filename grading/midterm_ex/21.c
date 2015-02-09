#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void lt()
{
	motor(6000,2000);
}

void rt()
{
	motor(2000,6000);
}

void stop(void)
{
  motor(0, 0);
}

void step(void)
{
  motor(10000, 10000);
}

void go(void)
{	int bwr,bwl;
	unsigned short bw;
	bwl=ADRead(0);
	bwr=ADRead(1);

	if(bwl<500 && bwr<500){
		step();
	}else if(bwl<500 && bwr>500){
		rt();
	}else if(bwl>500 && bwr<500){
		lt();
	}else if(bwl>500 && bwr>500){
		stop();
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0;i<100;){
		go();
	}
	return 0;
}
