#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
int R;
int L;
int W;
void step(R,L,W){
	Mtr_Run_lv(R, -L, 0, 0, 0, 0);
	Wait(W);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	unsigned short right; // ADRead() の返す型の変数を用意
	for(;;){
		step(6000,6000,0);
		left = ADRead(0);    // 代入により受け取る。
		right = ADRead(1);
		if((left>800 ) && (right>800)){
			break;
		}
		if(left>800){
			step(12000,6000,30);
		}
		if(right>800){
			step(6000,12000,30);
		}

	}
	step(0,0,0);
	return 0;
}
