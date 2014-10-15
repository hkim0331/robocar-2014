## 関数を利用

音符ごとに関数を利用する。

ドをならしたいときは DO() とすればよくなり、main()関数がずっと短く、見やすくなる。

void は「無し」の意味。　`void DO(void)` は、

	返り値なし　関数の名前は DO 引数なし　

と読む。返り値とか、引数とか、授業をよく聞くこと。


````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void DO(void)
{
	BuzzerSet(179, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}

void SO(void)
{
	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}

void RA(void)
{
	BuzzerSet(107, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
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
