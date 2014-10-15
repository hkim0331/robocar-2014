## さらに関数

DO() や SO() は同じ構造をしている。それをもう一つ別の関数 play() に。

関数 play()はピッチ、ボリューム、音符の長さ、休止時間を引数に取る。

play(100, 100, 100, 100) はピッチ100、ボリューム100、音の長さ100ミリ秒、
鳴った後100ミリ秒無音となる。

play(200, 100, 400, 10) はピッチ200、ボリューム100、音の長さ400、
鳴った後に10ミリ秒無音となる。

````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch, int vol, int duration, int pause)
{
	BuzzerSet(pitch, vol);
	BuzzerStart();
	Wait(duration);
	BuzzerStop();
	Wait(pause);
}

void DO(void)
{
	play(179,100,400,100);
}

void SO(void)
{
	play(120,100,400,100);
}

void RA(void)
{
	play(107,100,400,100);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	DO();
	DO();
	SO();
	SO();
	RA();
	RA();
	SO();

	return 0;
}
````
