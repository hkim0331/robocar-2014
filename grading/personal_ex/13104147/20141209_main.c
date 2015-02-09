#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define T 30
#define BLACK 300
#define GRAY 200

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
	motor(8000,8000);
	Wait(T);
	stop();
}

void forwardg()
{
	motor(4000,4000);
	Wait(T);
	stop();
}

void curveright()
{
	motor(8000,0);
	Wait(T);
	stop();
}

void curverightg()
{
	motor(4000,0);
	Wait(T);
	stop();
}

void curveleft()
{
	motor(0,8000);
	Wait(T);
	stop();
}

void curveleftg()
{
	motor(0,4000);
	Wait(T);
	stop();
}

void turnright()
{
	motor(8000,-8000);
	Wait(T);
	stop();
}

void run1()
{
	right = ADRead(0);
	left = ADRead(1);

	for( ; ; )
	{
		forward();
		if((left<GRAY)&&(right<GRAY)){
			break;
		} else if(left>BLACK){
			curveleft();
		} else if(right>BLACK){
			curveright();
		} else {
			;
		}
	}
	stop();
}

void grayrun()
{
	for(;;)
	{
		forwardg();
		if((left<BLACK)&&(right<BLACK)){
			break;
		} else if(left<GRAY){
			curveleftg();
		} else if(right<GRAY){
			curverightg();
		}
	}
	stop();
}

void turn1()
{
	for(;;)
	{
		if(left<BLACK){
			turnright();
		} else if(left>BLACK){
			break;
		}
	}
	stop();
}

void turn2()
{
	for(;;)
	{

	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	run1();
	grayrun();
	run1();
	grayrun();
	run1();


	return 0;
}

