#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void fw(void)
{
	Mtr_Run_lv(5000,-5000,0,0,0,0);
			Wait(300);
}

void turnR(void){
	Mtr_Run_lv(7000,0,0,0,0,0);
				Wait(300);
}

void turnL(void){
	Mtr_Run_lv(0,-7000,0,0,0,0);
				Wait(300);
}

void stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
				Wait(300);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short ADRead(unsigned char n);

	unsigned short r,l;

	for (;;) {
		fw();
		r=ADRead(0);
		l=ADRead(1);
		if((r>700) && (l>700)){
			stop();
		}  else if (l>700){
			turnL();
			LED(1);
		} else if (r>700){
			turnR();
			LED(2);
		} else{
			fw();
		}
		}

}

