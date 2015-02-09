#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void migi(void)
{
	LED(1);
	Wait(100);
	BuzzerSet(120,100);//so
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
}

void hidari(void)
{
	LED(2);
	Wait(100);
	BuzzerSet(95,100);//shi
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	/*int i;
	LED(3);//LED両方点灯
	for(i=0;i<10;i++){
		LED(1);//LED片方点灯
		Wait(100);
		LED(2);//LED片方点灯
		Wait(100);
		//LED( (i%2) + 1 );LEDが片方ずつ点灯を一行で書くと
	}
	LED(0);*/
	int i;

	for(i=0; i<100; i++){
		migi();
		hidari();
	}


	return 0;
}

