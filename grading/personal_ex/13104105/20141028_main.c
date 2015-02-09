// ロボカーを 5 秒前進させる。
// プログラム的にはあまり良くない。
// 先週の授業を思い出して改良せよ。
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(2000);
  Mtr_Run_lv(12000, -10000, 0, 0, 0, 0);
  Wait(1000);
  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

  return 0;
}
