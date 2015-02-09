#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);


    Wait(1000);

    LED(2);
/*
    int i;
    for (i=0; i<100; i++) {
        LED((i%2));
        Wait(500);

        	if((i%2) == 1 ){

        		  BuzzerSet(142, 100); // ピッチ 120、ボリュームは 100 だ。
        		  BuzzerStart();       // ブザー鳴れ。
        		  Wait(500);          // 3秒待つ。
        		  BuzzerStop();        // 鳴りやめ。
        	}
        	else{

      		  BuzzerSet(120, 100); // ピッチ 120、ボリュームは 100 だ。
      		  BuzzerStart();       // ブザー鳴れ。
      		  Wait(500);          // 3秒待つ。
      		  BuzzerStop();        // 鳴りやめ。
        	}



    } */
    LED(0);
    return 0;
}
