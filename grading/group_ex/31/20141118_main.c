#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT  8000
#define RIGHT 8000

#define WAIT 10

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	LED(0);
	motor(0, 0);
}

void forward(void)
{
	LED(3);
	motor(LEFT, RIGHT);
	Wait(WAIT);
}

void curve_left(void)
{
	LED(1);
	motor(LEFT, 0);
	Wait(WAIT);
}

void curve_right(void)
{
	LED(2);
	motor(0, RIGHT);
	Wait(WAIT);
}

void check (void)
{
	unsigned short bw;

	for(;;){
		if (ADRead(0) > 500 && ADRead(1) <= 500) {
			curve_left();
		} else if (ADRead(1) > 500 && ADRead(0) <= 500) {
			curve_right();
		} else if (ADRead(0) > 500 && ADRead(1) > 500) {
			break;
		} else {
			forward();
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	check();
	stop();

	return 0;
}
