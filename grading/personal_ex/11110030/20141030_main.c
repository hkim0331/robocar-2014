#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 10000

#define ZE 50

#define N 10

#define EDGE 1

#define ST 1000
#define STOP 1
#define L 0

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);

}

void stop(int m)
{
	motor(0,0);
	Wait(ST * m);
}

void forward(int n)
{
	motor(LEFT, RIGHT);
	Wait(ZE * n);
	stop(L);
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
	int i;
	for(i = 0; i < N; i++){
		forward(EDGE);
		stop(STOP);
	}
	return 0;
}




