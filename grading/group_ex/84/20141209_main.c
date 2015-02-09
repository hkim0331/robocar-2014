#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define kuro 800
#define siro 300
#define haisita 300
#define haiue 700
#define nagasa 3

void susumu(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}

void susumu2(void)
{
	Mtr_Run_lv(5000,-5000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}

void migi(void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(90);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}

void hidari(void)
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(90);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}

void tomaru(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

unsigned short left;
unsigned short right;


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int kaisuu = 0;

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(1000);

	for( ; ; )
	{
		susumu();

		left = ADRead(0);
		right = ADRead(1);

		if((left>kuro)&&(right>kuro)){
			kaisuu += 1;
		}

		if((left<siro)&&(right<siro)){
			if(kaisuu<nagasa){
				kaisuu = 0;
			}
			if(kaisuu>nagasa){
				tomaru();
				break;
			}
		}

		if(((left>haisita)&&(left<haiue))&&((right>haisita)&&(right<haiue))){
			susumu2();
			LED(3);//緑＋オレンジ
		}

		if(((left>kuro)||((left>haisita)&&(left<haiue)))&&(right<siro)){
			hidari();
		}

		if(((right>kuro)||((right>haisita)&&(right<haiue)))&&(left<siro)){
			migi();
		}
	}
	return 0;
}
