#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define wa1   1000
#define wa2   1500
#define wa3   700
#define re    10000
#define le  -10000
#define NN    0



void play(int hi  )
{




		Mtr_Run_lv(0 , 0, 0, 0, 0, 0);
		Wait(wa1);
		Mtr_Run_lv(hi,le, 0, 0, 0, 0);
		Wait(wa2);
		Mtr_Run_lv(re ,0, 0, 0, 0, 0);
		Wait(wa3);
		Mtr_Run_lv(0, 0, 0, 0, 0,0);
		Wait(wa1);



}

void motor(void)
{
	int s[]={re,re,re,re,NN};


	int i;

	for (i=0; s[i]!=NN;i++){
		play(s[i]);
	}
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	motor();



	return 0;
}
