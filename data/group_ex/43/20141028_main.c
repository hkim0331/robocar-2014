// ロボカーを 5 秒前進させる。
// プログラム的にはあまり良くない。
// 先週の授業を思い出して改良せよ。
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void kyori(cm){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(cm);		//cm=1500で30cm
	Mtr_Run_lv(0, 0, 0, 0, 0 ,0);
}

void turnL(radL){
	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	Wait(radL);		//radL=800で90度
	Mtr_Run_lv(0, 0, 0, 0, 0 ,0);
}


//10000 wait2000で100cm

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  int i;
  for(i=1;i<5;i++){
	  kyori(1500);
	  Wait(500);
	  turnL(800);
	  Wait(500);
  	};


  return 0;
}
