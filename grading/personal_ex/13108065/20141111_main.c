#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Si(){
BuzzerSet(95, 100);       // ピッチ 95、ボリュームは 100
		  BuzzerStart();       // ブザー鳴れ。
		  Wait(1000);          // 1秒待つ。
		  BuzzerStop();        // 鳴りやめ。
}

void So(){
BuzzerSet(120, 100); // ピッチ 120、ボリュームは 100
		  BuzzerStart();       // ブザー鳴れ。
		  Wait(1000);          // 1秒待つ。
		  BuzzerStop();        // 鳴りやめ。
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0; i<10; i++){
		LED((i%2) +1);  //%は余りより+1でLEDは1か2
		Wait(100);

	if(i%2+1==1){
	Si();
	}
	else{
		So();
	}

	}









	return 0;
}

