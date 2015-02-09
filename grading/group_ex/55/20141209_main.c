#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define Rb 750
#define Lb 750
#define Rg 500
#define Lg 500
#define Go 11000,-10000,0,0,0,0
#define Slowgo 7300,-7000,0,0,0,0
#define Back -11000,10000,0,0,0,0
#define Left 5500,7500,0,0,0,0
#define Right -5500,-5500,0,0,0,0
#define Right2 -6500,-8000,0,0,0,0
#define Stop 0,0,0,0,0,0

int blacks = 0;

void move(void){
	unsigned short right , left;
	for( ; ; ){
		right = ADRead(1);
		left = ADRead(0);

		if(((Rg<right)&&(right<Rb))||((Lg<left)&&(left<Lb))){
			BuzzerSet(DO, 100);
			BuzzerStart();
			if(((Rg<right)&&(right<Rb))&&((Lg<left)&&(left<Lb))){

				Mtr_Run_lv(Slowgo);
			}
			else if((Rg<right)&&(right<Rb)){
				Mtr_Run_lv(Right2);
			}
			else{
				Mtr_Run_lv(Left);
			}
		}
		else{
			BuzzerStop();
		 if(right>Rb&&left>Lb){ //両見え
			LED(3);
			Mtr_Run_lv(Go);
			Wait(100);
			Mtr_Run_lv(Stop);
			Wait(250);
			blacks += 1;
		 }
		 else if(right>Rb){ //右見え
			Mtr_Run_lv(Right);
			LED(1);
		 }
		 else if(left>Lb){
			Mtr_Run_lv(Left);
			LED(2);
		 }
		 else{
			LED(0);
			if(blacks<5){
				Mtr_Run_lv(Go);
				blacks = 0;
			 }
			 else{
				Mtr_Run_lv(Stop);
			 }
		 }
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	move();

	return 0;
}

