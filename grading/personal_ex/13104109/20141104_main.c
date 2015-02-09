#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void)
	{
	int i; // 変数iでループを回った回数を数えたい。使う前に宣言。
	for (i=0; i<6; i++) { // この書き方を覚えよ。
		Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	    Wait(500);
	    }
	}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step();

	return 0;
}

