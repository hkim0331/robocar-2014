#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex11(void)
{
    Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
    Wait(5000);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex12(void)
{
    Wait(2000);
    Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
    Wait(5000);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex21(void) //1cm前進
{
    Wait(2000);
    Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
    Wait(50);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex22(void) //10cm前進
{
    Wait(2000);
    Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
    Wait(500);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex23(void) //5cm後退
{
    Wait(2000);
    Mtr_Run_lv(-10000, 10000, 0, 0, 0, 0);
    Wait(250);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex24(void) //右に90度回転
{
    Mtr_Run_lv(0, -10000, 0, 0, 0, 0);
    Wait(800);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex25(void) //左に360度回転
{
    Wait(2000);
    Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
    Wait(3200);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex31(void) //2倍の速度で10cm前進
{
    Wait(2000);
    Mtr_Run_lv(20000, -20000, 0, 0, 0, 0);
    Wait(250);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex32(void) //1/2倍の速度で10cm前進
{
    Wait(2000);
    Mtr_Run_lv(5000, -5000, 0, 0, 0, 0);
    Wait(250);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void ex4(void) //30cm前進

{
    Mtr_Run_lv(10000, -10200, 0, 0, 0, 0);
    Wait(1500);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	Wait(1000);
	   for(i=0;i<4;i++)
	   {
		   ex4();
		   ex24();

	   }



	 return 0;
}

