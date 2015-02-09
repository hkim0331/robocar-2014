#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define border 500

void forward(void){

	Mtr_Run_lv(10000,-10000,0,0,0,0); //about 16 mm GO!
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void turnL(void){

	Mtr_Run_lv(0,-10000,0,0,0,0);
	Wait(30);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void turnR(void){

	Mtr_Run_lv(10000,0,0,0,0,0);
	Wait(30);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void stop(void){

	Mtr_Run_lv(0,0,0,0,0,0);
}

void buzzer(void){
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(200);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short readL;
	unsigned short readR;
	int blacks=0;
	int i=0;

	for(;;){

		readL = ADRead(0);
		readR = ADRead(1);

		if(readR<=border&&readL<=border){

			if(blacks<3||blacks>7){
				forward();
				blacks = 0;
			}

			else{
				stop();
				while(i<blacks){
					buzzer();
					i++;
				}
				break;
			}
		}
		else if(border<=readL&&border>readR){
			turnR();
		}
		else if(border<=readR&&border>readL){
			turnL();
		}
		else {
			blacks++;
			buzzer();
			forward();
			Wait(500);

		}
	}

	stop();

	return 0;
}

