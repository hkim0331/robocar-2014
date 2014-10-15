## main.c

main() 中にコピーペースト。最初の２小節のみ。

コメント入れるなどして可読性のアップに努力しているが、
これがキラキラ星を演奏するプログラムとは一見してわからない。

音符の長さ、休止時間の長さを変えるときは、音符の数だけ、変更する箇所が発生する。

別の曲をプログラムするにも相当の労力がいる。

````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	// ド
	BuzzerSet(179, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);

	// ド
	BuzzerSet(179, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);

	// ソ
	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);

	// ソ
	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);

	// ラ
	BuzzerSet(107, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);

	// ラ
	BuzzerSet(107, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);

	// ソ
	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);

	return 0;
}
````
