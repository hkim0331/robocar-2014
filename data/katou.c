/*
 ================================================================================
 Name        : Sensor.c
 Author      : Team Kaitou
 Version     : 1.0
 Copyright   : as you like.
 Description : スレッドは実装してない　
 ================================================================================
 */
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


// 安定な動作を確認できた単位数値
#define V 10000 * speed_raito
#define TIME1 cm * 60
#define TIME2 5.4 * ang
#define TIME3 10 * ang
#define STEP 0.3
#define ANG 6

//　色の数値
#define BLACK 850
#define ASH 350
#define WHITE 0

//音階
#define B0 190
#define C1 179
#define D1 160
#define E1 142
#define F1 134
#define G1 120
#define A1 107
#define B1 95
#define C2 90
#define D2 80
#define E2 71
#define F2 67
#define G2 60
#define A2 54
#define S0 1

//音の長さ
#define N 2400
#define H 1200
#define Q 600
#define O 300
#define S 150
#define B 10


float total_msec = 0;
int dat[2][NUM];

float abs(float n) 
{
	return (n > 0) ? n : -n	;
}

int is_ADR(int col ,int n) 
{
	return abs(col - ADRead(n)) < RNG;
}

int is_both_ADR(int col) 
{
	return is_ADR(col, 0) && is_ADR(col, 1);
}

int is_either_ADR(int col) 
{
	return is_ADR(col, 0) || is_ADR(col, 1);
}


//
// bgm
//

int sound(int read) 
{
	short snd[1000] = {
				S0,H+Q,C1,O,D1,O,E1,O,E1,O,D1,O,C1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				E1,O,E1,O,F1,O,E1,S,D1,O,E1,O,E1,O+S,S0,O,
				E1,O,D1,O,C1,O,C1,O,C1,O,C1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				E1,O,E1,O,F1,O,E1,S,D1,O,C1,O,C1,O+S,S0,H+O,

				S0,H+Q,E1,O,D1,O,C1,O,C1,O,C1,O,C1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				E1,O,E1,O,F1,O,E1,S,D1,O,E1,O,E1,O+S,S0,O,

				E1,O,D1,O,C1,O,C1,O,C1,O,C1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				G1,O,G1,O,A1,O,G1,O,F1,O,A1,O,G1,O,S0,O,
				E1,O,E1,O,F1,O,E1,S,D1,O,C1,O,C1,O+S,S0,O,

				C1,O,C1,O,C1,O,B0,O,C1,O,B0,O,C1,O,S0,O,
				C1,O,C1,O,D1,O,D1,S,D1,O,E1,O,E1,S+O,S0,O,
				E1,O,F1,O,G1,O,E1,S,G1,O,C2,O,C2,S+O,S0,O,
				C2,O,C2,O,D2,O,D2,S,C2,O,D2,O,D2,S,C2,H+Q+S,B1,S,C2,O,B1,H,S0,Q,

				E2,O,C2,O,C2,Q,S0,O,C2,O,D2,O,D2,S,D2,O,D2,O,E2,O,E2,Q,S0,O,
				E2,O,G2,O,E2,S,G2,O,G2,O,A2,O,C2,S,C2,O,S0,O,
				C2,O,C2,Q,E1,O,D2,O,D2,O,E2,S,D2,S,C2,O,B1,O,C2,O,S0,O,

				E2,O,C2,O,C2,Q,S0,O,C2,O,D2,O,D2,S,D2,O,D2,O,E2,O,E2,Q,S0,O,
				E2,O,G2,O,E2,S,G2,O,G2,O,A2,O,C2,S,C2,O,S0,O,
				C2,O,C2,Q,E1,O,D2,O,D2,O,E2,S,D2,S,C2,O,B1,O,C2,O,S0,O,

				E2,O,C2,O,C2,H+Q,B1,O,C2,H+Q,S0,Q,
				E2,Q,F2,O,E2,S,C2,H+S,B1,O,C2,O+H,S0,Q,
				E2,Q,F2,Q,A2,Q,G2,Q,F2,O,E2,O,F2,O,E2,Q,D2,O,C2,Q,S0,O,
				G1,O,A1,O,C2,O,S0,O,C2,O,D2,O,C2,O,B1,Q,C1,H+O,S0,O,

				E1,O,D2,O,C2,O,C2,O,C2,O,C2,O,D2,O,C2,O,E2,Q,S0,H+O,
				E1,O,D2,O,C2,O,C2,O,C2,O,C2,O,A2,O,
				E1,O,D2,O,C2,O,C2,O,C2,O,C2,O,D2,O,C2,O,A1,O,G1,O,E2,Q,D2,O,C2,O,C2,Q,
				C1,O,C1,O,C1,O,D2,O,D2,O,C2,O,D2,O,E2,O,D2,O,S0,O
		};

	return snd[read];
}

void note(int pitch) 
{
	BuzzerSet(pitch,100);
	BuzzerStart();
}

void play_bgm() 
{
	static int next_r = 0, total_msec_bgm = 0;
	int time, pitch;

	if (total_msec > total_msec_bgm) {
		pitch = sound(num, next_r);
		time  = sound(num, next_r + 1);

		note(pitch);

		total_msec_bgm += time;
		next_r += 2;
		if (pitch == '\0'|| pitch == 0 )
			next_r = 0;
	}
}

//
//  以下、ロボカーの動作
//

void mtr(short m1, short m2, float msec) 
{
	Mtr_Run_lv(m1 * 1.05, m2, 0, 0, 0, 0);
	Wait((int)msec);
	total_msec += (int)msec;
}

void go(float cm) 
{
	mtr(V, -V, TIME1);
}

void turn_rig(float ang) 
{
	mtr(-V/3, -V, TIME2);
}

void turn_lef(float ang) 
{
	mtr(V/3, V, TIME2);
}

void stop() 
{
	mtr(0, 0, 100);
	LED(0);
}

int is_dif_col()
{
	return abs(ADRead(0) - ADRead(1)) > 200;
}


void turn_toward_black()
{
	int sgn = ADRead(0) -ADRead(1);

	if (sgn < 0) {
		turn_lef(ANG);
	} else {
		turn_rig(ANG);
	}
}


void arrive()
{
	BuzzerStop();
	stop();
}

void drive() 
{
	if (is_dif_col()) {
		turn_toward_black();
	} else {
		go(STEP)
	}
}

int is_on_the_way() 
{
	return is_either_ADR(WHITE);
}

void run() 
{	
	while (is_on_the_way()) 
	{	
		play_bgm();
		drive();
	}

	arrive();
}


void wait_sw() 
{
	while (getSW() != 1)
		;
	while (getSW() == 1)
		;
	Wait(1000);
}

int main(void)
 {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	wait_sw();

	run();

	return 0;
}

