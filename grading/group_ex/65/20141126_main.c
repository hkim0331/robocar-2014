#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define BLACK 500
void migi(void)
{
	Mtr_Run_lv(15000,-5000,0,0,0,0);
	Wait(150);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(100);

}
void hidari(void)
{
	Mtr_Run_lv(5000,-15000,0,0,0,0);
	Wait(150);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(100);
}

void step1(void)
{
	Mtr_Run_lv(11000,-10000,0,0,0,0);
	Wait(150);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(100);
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}
int black(int n){
	return ADRead(n) > BLACK;
}
int white(int n){
	return ! black(n);
}
int blacks=0;
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;
	left = ADRead(0);
	unsigned short right;
	right = ADRead(1);
	for(;;){
		if(white(0) && white(1)){
			step1();
			LED(0);
		}
		else if(white(0) && black(1)){
			hidari();
		}
		else if(black(0) && white(1)){
			migi();
		}
		else if(black(0) && black(1)){
			step1();
			LED(1);
			Wait(150);
			LED(0);
			Wait(200);
			blacks += 1;
		}if(blacks >15){
			if (black(0) && black(1)) {
				step1();
				LED(1);
				Wait(150);
				LED(0);
				Wait(200);

			}else{
				stop();
				break;
			}
		}else{
			;
		}

	}
	return 0;
}

