#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define T 30
#define BLACK 300

unsigned short left;
unsigned short right;

void motor(short LEFT, short RIGHT)
{
	Mtr_Run_lv(LEFT, -RIGHT, 0,0,0,0);
}

void stop(void)
{
	motor(0,0);
}

void forward()
{
	motor(10000,10000);
}

void turnright()
{
	motor(10000,0);
	Wait(T);
	stop();
}

void turnleft()
{
	motor(0,10000);
	Wait(T);
	stop();
}

void run()
{
	right = ADRead(0);
	left = ADRead(1);

	for( ; ; )
	{
		forward();
		if((left>BLACK)&&(right>BLACK)){
			break;
		} else if(left>BLACK){
			turnleft();
		} else if(right>BLACK){
			turnright();
		} else {
			;
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	run();
	stop();

	return 0;
}

