#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int sp = 10000;  //speed

void lc(void){//left_curve
	LED(2);
	Mtr_Run_lv(sp, 0, 0, 0, 0, 0);
	Wait(50);
}
void rc(void){//right_curve
	LED(1);
	Mtr_Run_lv(0, -sp, 0, 0, 0, 0);
	Wait(50);
}
void str(void){//straight
	LED(3);
	Mtr_Run_lv(sp, -sp, 0, 0, 0, 0);
	Wait(50);
}
void stop(void){//stop
	LED(0);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int l;
	int r;
	for( ; ; )
	{
		l  = ADRead(0);
		r = ADRead(1);
		if(l>500 && r<500)
		{   // when_left_brack
            lc();
		}else{
			;
		}
		if(l<500 && r>500)
		{  // when_right_brack
			rc();
		}else{
			;
		}
		if(l<500 && r<500)
		{   //w_w
			str();
		}else{
			;
		}
		if(l>500 && r>500)
		{   //w_b
			stop();
			break;
		}else{
			;
		}
	}
	return 0;
}

