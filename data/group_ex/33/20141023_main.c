#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void move(void)
{

	Wait(1000);
	Mtr_Run_lv(11400, -11900, 0, 0, 0, 0);
	Wait(2000);

	Mtr_Run_lv(11000, 0, 0, 0, 0, 0);
	Wait(800);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	move();
	move();
	move();
	move();







	return 0;
}

