#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 6000
#define RIGHT 5990
#define x 25
#define y 80
#define N 4000
#define CM 50
#define length 2
#define L_EYE 0
#define R_EYE 1
#define bw 500


void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop()
{
	motor(0, 0);
	LED(0);
	Wait(50);
}

void straight(int a)
{
	motor(LEFT, RIGHT);
	LED(3);
	Wait(x*a);
}

void turnR(int b)
{
	motor(RIGHT, 0);
	LED(1);
	Wait(y*b);
}

void turnL(int b)
{
	motor(0, LEFT);
	LED(0);
	Wait(y*b);
}

int bL(void)
{
	return ADRead(L_EYE) > bw;
}

int bR(void)
{
	return ADRead(R_EYE) > bw;
}

int b(void)
{
	return bL() && bR();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	Wait(1000);

	for(i=0; i<N; i++)
	{
		straight(length);
		if(bR()){
			turnL(2);
		}else if(bL()){
			turnR(2);
		}
		if(b()){
			stop();
			break;
		}
	}
	stop();

	return 0;
}

