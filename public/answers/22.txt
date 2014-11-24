#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int right1()
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(200);
	Mtr_Run_lv(0,0,0,0,0,0);
	go();
}

int left1()
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(200);
	Mtr_Run_lv(0,0,0,0,0,0);
	go();
}

int straight()
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(80);
		Mtr_Run_lv(0,0,0,0,0,0);
}
int stop()
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

int go()
{
	unsigned short left,right;
	int i;
	for( ; ; )
	{
		straight();
		Wait(30);
		left=ADRead(0);
		right=ADRead(1);

		if(500<left)
		{break;}
		else if(500<right){break;}
		else if(500<right && 500<left){break;}
		else{;}
	}
if(300<right && 300<left)
{stop();}
else if(300<right)
{right1();}
else if(300<left)
{left1();}
else{;}
}

int main(void)
{
	const unsigned short MainCycle=60;
	Init(MainCycle);
	go();
	return 0;
}





