## 前進 1cm!

今日のプロジェクトは motor 。
テーマは char, int, short, unsigned, signed の意味を知る、だ。
準備はいいか?

### Mtr_Run_lv()

* 関数 Mtr_Run_lv() はロボカーのモーターを制御する。
* ロボカーには最大６個のモータを乗せることが可能であるため、
関数 Mtr_Run_lv() も６つのモーターを制御できるようなプログラムになっている。
* しかし、授業で使うロボカーに搭載のモーターは二つ。
* 関数 Mtr_Run_lv()は６つの引数を取るが、授業のロボかーで使うのは最初の二つだけ。

````c
// ロボカーを 5 秒前進させる
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void)
{
  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
  Wait(5000);
  Mtr_Run_lv(0, 0, 0, 0, 0);
}

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  run();

  return 0;
}
````

### 問題 1
1. ロボカーを 1cm 前進させ、静止させよ。
2. ロボカーを 10cm 前進させ、静止させよ。
3. ロボカーを 5cm 後退させよ。

## Mtr_Run_lv() を調べる

関数 Mtr_Run_lv() はファイル vs-wrc103.c の 195 行目に定義されている。

````c
void Mtr_Run_lv(short m1,short m2,short m3,short m4,short m5,short m6)
````

short


