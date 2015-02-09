#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

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

	// 何回進むか？
#define N 50000

	// 1cm 進む時間(msec)
	// これらの値は実験で求める。ロボカーによって異なる。
#define FW 37

	void motor(short left, short right)
	{
		Mtr_Run_lv(left, -right, 0, 0, 0, 0);
	}

	void stop(void)
	{
		motor(0, 0);
	}

	void forward(void)
	{
		motor(LEFT, RIGHT);
		Wait(FW);
		stop();
	}

	int main(void)
	{
		const unsigned short MainCycle = 60;
		Init(MainCycle);

		Wait(1000);
		int i;
		for (i = 0; i < N; i++) {
			forward();
		}

		return 0;
	}
