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

// 車輪にかけるパワー。ロボカーによって変える。
// 実験で求めるべし。コピペ不可。
#define LEFT   10000
#define RIGHT  10000

// 一辺を何センチとするか?
#define EDGE 30

// 何回で一周するか?
#define N 4

// これらの値は実験で求めた。ロボカーによって異なるはず。
// 1cm 進む時間と1度 回る時間(msec)
// コピペ不可。
#define FW 40
#define TN 8

int abs(int n)
{
  return  n > 0 ? n : -n;
}

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0, 0);
}

// forward n cm. if n < 0, backward.
void forward(int n)
{
	short left  = LEFT;
	short right = RIGHT;

	if (n < 0) {
		left  *= -1;
		right *= -1;
	}
	motor(left, right);
	Wait(FW * abs(n));
	stop();
}

// if deg > 0, turn right, else turn left.
void turn(int deg)
{
	if (deg > 0) {
		motor(LEFT, 0);
	} else {
		motor(0, RIGHT);
	}
	Wait(TN * abs(deg));
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
