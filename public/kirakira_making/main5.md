## 楽曲を配列で

関数 kirakira() 内の配列 notes[] に注目。

配列の要素は音のピッチを表す整数(int)。

配列中に XX が現れるまで、配列要素を引数に関数 play()を呼出す。

````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100
#define VOL 100

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define XX    0

void play(int pitch)
{
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(DURATION);
	BuzzerStop();
	Wait(PAUSE);
}

void kirakira(void)
{
	int notes[]={DO,DO,SO,SO,RA,RA,SO,XX};
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kirakira();

	return 0;
}
````
