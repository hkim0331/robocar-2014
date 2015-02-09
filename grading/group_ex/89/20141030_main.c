#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define fw 100//1cm
#define tn 3//1度



void run(int right, int left, int time)
{
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
	Wait(time);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void str(int n)
{
    if( n > 0 ){
    	run(10000, 10000, fw * n);
    }else{
    	run(-10000,-10000, fw * -n);
    }
}

void turn(deg)
{
	if( deg > 0 ){
		run(10000, 0, tn * deg);
	}else{
		run(0, 10000, tn * -deg);
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	int i;
	for(i=0; i<4; i++){
		str(30);
		turn(90);
	}

	return 0;
}

