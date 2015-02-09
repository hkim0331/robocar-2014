#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define kuro 700
#define siro 300
#define nagai 8
#define mizikai 3

void susumu(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(100);
}

void migi(void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}

void hidari(void)
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(70);
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
		int i;

		susumu();

		left = ADRead(0);
		right = ADRead(1);

		if((left>kuro)&&(right>kuro)){
			kaisuu += 1;
			for(i=0;i<kaisuu;i++){
				 LED((i%2)+1);
				 Wait(100);
			}
		}

		if((left<siro)&&(right<siro)){

			if((kaisuu>nagai)||(kaisuu<mizikai)){
				kaisuu = 0;
			}

			if((kaisuu<nagai)&&(kaisuu>mizikai)){
				tomaru();
				break;
			}
		}

		if((left>kuro)&&(right<kuro)){
			hidari();
		}
		if((left<kuro)&&(right>kuro)){
			migi();
		}
	}
	return 0;
}
