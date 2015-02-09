#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define s 20
#define t 20
#define N 4000

#define length 1


#define left_eye 0
#define right_eye 1

#define BLACK 500


int is_black_left(void)
{
	return ADRead(left_eye) > BLACK;
}

int is_black_right(void)
{
	return ADRead(right_eye) > BLACK;
}

int is_black(void)
{
	return is_black_left() && is_black_right();
}


void motor(short right, short left)
{
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
}

void straight(int a)
{
	motor(RIGHT, LEFT);
	LED(3);
	Wait(s*a);
}

void right_turn(int b)
{
	motor(RIGHT, 0);
	LED(1);
	Wait(s*b);
}

void left_turn(int b)
{
	motor(0, LEFT);
	LED(2);
	Wait(t*b);
}

void stop(void)
{
	motor(0, 0);
	LED(0);
	Wait(50);
}

void goal(void)
{
	int i;

	for(i=0; i<N; i++)
	{
		straight(length);
		if(is_black_right()){
			left_turn(2);
		} else if(is_black_left()){
			right_turn(2);
		}
		if(is_black()) {
			break;
		}
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(500);

	goal();

	stop();

	return 0;
}

