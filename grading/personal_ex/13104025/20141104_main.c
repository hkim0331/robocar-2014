#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

int i; // 変数iでループを回った回数を数えたい。使う前に宣言。

for (i=0; i<6; i++) { // この書き方を覚えよ。
    step();
    Wait(500);
}
