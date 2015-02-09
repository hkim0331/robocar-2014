#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define MI 142
#define SO 120

#define Rb 700
#define Lb 700
#define Go 11000,-10000,0,0,0,0
#define Back -11000,10000,0,0,0,0
#define Left 7000,0,0,0,0,0
#define Right 0,-7000,0,0,0,0
#define Stop 0,0,0,0,0,0

int blacks = 0;
int white;

void step(void){
	unsigned short right , left;
	for( ; ; ){
		right = ADRead(1);
		left = ADRead(0);

		if((white>1)&&(blacks>8)&&(blacks<16)){
			break;
		}
		else if(right>Rb&&left>Lb){ //両見え
			Mtr_Run_lv(Stop);
			Wait(500);
			Mtr_Run_lv(Go);
			Wait(70);
			blacks +=1;
			white = 0;
			LED(3);
		}
		else if(right>Rb){ //右見え
			Mtr_Run_lv(Right);
			LED(1);
		}
		else if(left>Lb){ //左見え
			Mtr_Run_lv(Left);
			LED(2);
		}
		else{
			Mtr_Run_lv(Stop);
			Wait(500);
			Mtr_Run_lv(Go);
			Wait(100);
			white += 1;
			LED(0);
			if(white>2){
				blacks = 0;
			}
		}
	}
	Mtr_Run_lv(Back);
	Wait(150);
	Mtr_Run_lv(Stop);
	BuzzerSet(DO, 100);
	BuzzerStart();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step();

	return 0;
}

