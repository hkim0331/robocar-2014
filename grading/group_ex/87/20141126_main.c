#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define BLACK 600

void moter(void)
{
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(500);
}

void step(void)
{
	Mtr_Run_lv(10100,-10000,0,0,0,0);
	moter();
}
void turnLeft(void)
{
	Mtr_Run_lv(10000,-3000,0,0,0,0);
	moter();
}
void turnRight(void)
{
	Mtr_Run_lv(3000,-10000,0,0,0,0);
	moter();
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

void Buzzer(void)
{
	BuzzerSet(179,100);
	BuzzerStart();
	Wait(70);
	BuzzerStop();
	Wait(500);
}

void ex1(void){

	unsigned short left, right;
	int blacks=0;

	for(; ;) {
		left=ADRead(0);
		right=ADRead(1);

		if(left<BLACK && right<BLACK) {
			step();

			if (blacks >20) {
				blacks=0;
			} else if (blacks <4) {
				blacks=0;
			} else if(blacks >=4 && blacks <=20) {
				break;
			} else {
				;
			}
		} else if(right>BLACK && left>BLACK)
		{
			blacks += 1;
			step();
			Buzzer();
		} else if(right<BLACK && left>BLACK) {
			turnLeft();
		} else if(right>BLACK && left<BLACK) {
			turnRight();
		} else {
			;
		}
	}

	stop();

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex1();

	return 0;
}

