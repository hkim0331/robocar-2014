## hkimura の motor/src/main.c

単純なコピーは火傷するぞ。
内容を理解するべし。
プログラムの下に問題がある。やれ。

````c
/*
 ============================================================================
 Name        : motor/src/main.c
 Author      : Hiroshi Kimura
 Version     : 1.0
 Copyright   : as you like. no warranty.
 Description : beuto runs along N-polygon edges.
 ============================================================================
 */
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

// 車輪にかけるパワー。ロボカーによって変わる。
// 実験で求めるべし。
#define LEFT   10000
#define RIGHT  10000

// 一辺を何センチとするか?
#define EDGE 30

// 何回で一周するか?
#define N 4

// 1cm 進む時間と1度 回る時間(msec)
// これらの値は実験で求める。ロボカーによって異なる。
#define FW 40
#define TN 8

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}

void turn(int deg)
{
  motor(LEFT, 0);
  Wait(TN * deg);
  stop();
}

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);
  int i;
  for (i = 0; i < N; i++) {
    forward(EDGE);
    turn(360/N);
  }

  return 0;
}
````

### 問題
プログラムは最初、

* forward(-10)で後ろに10cm移動するように。
* turn(-90)で右90度回転するように。

としていたが、簡単のために外した。
復活させよ。

[戻る](./index.html)
