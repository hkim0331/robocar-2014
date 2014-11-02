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

// 車輪にかけるパワー。ロボカーによって違う。
// まっすぐ走る値を実験で求める。
#define LEFT   10000
#define RIGHT  10000

// 一辺を何センチとするか?
#define EDGE 30

// 何回で一周するか?
#define N 4

// 1cm 進む時間と1度 回る時間(msec)
// これらの値は実験で求める。ロボカーによって異なるはず。
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
