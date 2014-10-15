## 定数を別の場所で定義

DURATION, PAUSE, VAL を定数として定義(define)する。

ついでに 関数 kirakira()を導入。別の曲はきっと別の関数として定義されるのだろう。

main() はこれ以上短くならない。

````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100
#define VOL 100

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
	play(179, VOL, DURATION, PAUSE);
}

void SO(void)
{
	play(120, VOL, DURATION, PAUSE);
}

void RA(void)
{
	play(107, VOL, DURATION, PAUSE);
}

void kirakira(void)
{
	DO();
	DO();
	SO();
	SO();
	RA();
	RA();
	SO();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kirakira();

	return 0;
}
````
