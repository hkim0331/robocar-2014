#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void play(int pitch)
{ BuzzerSet(pitch, 100); // ピッチ 120、ボリュームは 100 だ。
BuzzerStart();       // ブザー鳴れ。
Wait(1000);          // 3秒待つ。
BuzzerStop();
}
void Do(void)
{
	play(179);
}
void Re(void)
{
	play(160);
}
void Mi(void)
{
	play(142);
}
void Hua(void)
{
	play(134);
}
void So(void)
{
	play(120);
}
void Ra(void)
{
	play(107);
}
void Shi(void)
{
	play(95);
}
void DO(void)
{
	play(90);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Do();
	Do();
	So();
	So();
	Ra();
	Ra();
	So();



	return 0;
}

