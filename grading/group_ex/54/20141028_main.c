// ロボカーを 5 秒前進させる。
// プログラム的にはあまり良くない。
// 先週の授業を思い出して改良せよ。ｳｪｲ｡
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



int manco()
{
	  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(1420);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	  Wait(500);

	  Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	  Wait(460);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}


int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

 Wait(2000);

 int i;
 for(i=1;i<=4;i++){
	 manco();
 }

  return 0;
}
