#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"





	void music(int x){
	BuzzerSet(x, 100); // ピッチ 120、ボリュームは 100 だ。
	  BuzzerStart();       // ブザー鳴れ。
	  Wait(1000);          // 3秒待つ。
	  BuzzerStop();        // 鳴りやめ。
	}








int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);






	int i;
	LED(3);
	Wait(1000);

	for(i=0;i<10;i++){
		music((i*25)+95);
		LED((i%2)+1);
		Wait(1000);
		}
	LED(0);
	Wait(1000);
	return 0;
}

