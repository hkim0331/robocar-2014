#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

//定義
#define l 8000
#define r 6000
#define s 0
#define a 100


void motor(short left, short right)
{
	Mtr_Run_lv(left, -right,0,0,0,0);
}

void go(int t,int x,int y,int z)
{
	LED(t);
	motor(x,y);
	Wait(z);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short bw, ri;

	for(;;)
	{
		bw = ADRead(0);
		ri = ADRead(1);
		if((bw < 500)&&(ri < 500)){
			go(3,l,l,a);
		}
		else if((bw > 500)&&(ri < 500)){
			go(2,r,s,a);
		}
		else if((bw < 500)&&(ri > 500)){
			go(1,s,r,a);
		}
		else{
			break;
		}

	}
	LED(0);
	motor(0,0);

	return 0;
}

