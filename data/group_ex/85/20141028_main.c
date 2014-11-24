#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void EX0(void)
{

	Wait(2000);
}
void EX1(void)
{

	Mtr_Run_lv(17500,-20000, 0, 0, 0, 0);
	Wait(3500);
	Mtr_Run_lv(0,0,0,0,0,0);

}
void EX2(void)
{
	Mtr_Run_lv(30000,30000, 0, 0, 0, 0);
	Wait(300);
	Mtr_Run_lv(0,0,0,0,0,0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	EX0();
    EX1();
    EX2();
    EX1();
    EX2();
    EX1();
    EX2();
    EX1();

	return 0;
}

