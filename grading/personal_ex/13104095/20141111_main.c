#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DO    179
#define MI    142

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	 LED(3);
	 Wait(1000);//1秒間点灯
	    int i;
	    for (i=0; i<100; i++) {
	        LED(i%2+1)&BuzzerSet(120, 100); // ピッチ 120、ボリュームは 100 だ。
	        BuzzerStart();       // ブザー鳴れ。
	        Wait(3000);          // 3秒待つ。
	        BuzzerStop();   ;//2で割ったときの余り＋１
       Wait(100);
       BuzzerSet(179, 100); // ピッチ 179、ボリュームは 100 だ。
         BuzzerStart();       // ブザー鳴れ。
         Wait(3000);          // 3秒待つ。
         BuzzerStop();
	    }
	    LED(0);
	return 0;
}

