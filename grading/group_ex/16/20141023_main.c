#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define RIGHT 10000
#define LEFT  -10000
#define TIME  2000

int right = RIGHT;
int left  = LEFT;
int time  = TIME;

void go (void)
{

	Mtr_Run_lv(right, left, 0, 0, 0, 0);
		  Wait(time);
		  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void rotate(void)
{
	left=10000;
	time=400;
	go();
	left=-10000;
    time=2000;
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	go();
	rotate();
	go();
	rotate();
	go();
	rotate();
	go();


	return 0;
}

