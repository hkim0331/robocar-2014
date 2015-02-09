#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define VOL 100

#define SEC 1000

#define L_P  10100   // moterの出力
#define R_P  10000

#define TW   50  // turnの時間

#define L_E    0   //ADReadのため
#define R_E    1

#define LED_L  1   // LEDの点灯のため
#define LED_R  2

#define MM 3       // 5mm 進むための時間
#define BLACK 500   // 白黒判断の境界値

#define LONG   9   // 黒の長さを判別する基準
#define SHORT  5

#define MICHI  3   // 道のかたち

void play(int pitch)
{
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(SEC/4);
	BuzzerStop();
}

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0,0);
	Wait(SEC/2);
}

void forward(int times)
{
	LED(LED_L + LED_R);
	motor(L_P, R_P);
	Wait(MM * times);
	stop();
}

void turn (short a, short b, int n)
{
	LED(n);
	Mtr_Run_lv(a, -b, 0, 0, 0, 0);
	Wait(TW);

}

void step(int n)
{
	forward(n); // forward 5n[mm]
	stop();
}

int is_white_left(void)
{
	return ADRead(L_E) < BLACK;
}
int is_white_right(void)
{
	return ADRead(R_E) < BLACK;
}
int is_white(void)
{
	return is_white_left() && is_white_right();
}
int is_black_left(void)
{
	return ADRead(L_E) > BLACK;
}
int is_black_right(void)
{
	return ADRead(R_E) > BLACK;
}
int is_black(void)
{
	return is_black_left() && is_black_right();
}

void is_long(void)
{
	int blacks=0, i, j=0, reco[MICHI];

	while (1)
	{
			if (is_white())
			{
				if(blacks!=0)
				{
					reco[j] = blacks;
					j++;
				}
				if (blacks >= SHORT  && blacks <= LONG)
				{
					break;
				}
				blacks=0;
				step(1);
			}
			else if (is_black())
			{
						 blacks++;
						 step(1);
			}
			else if (is_black_right()) turn(L_P, R_P/3, LED_L);
			else if (is_black_left()) turn(L_P/3, R_P, LED_R);
			else ;
	}

	stop();
	Wait(SEC);

	for (j=0; j<MICHI; j++)
	{
		for (i=0; i<reco[j]; i++)
		{
			play(250); Wait(SEC/4);
		}
		Wait(SEC/2);
	}

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(SEC);

	is_long();

	Wait(SEC);

	return 0;
}
