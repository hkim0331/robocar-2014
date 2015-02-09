#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define SO 120
#define SI 95


void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(500);
	BuzzerStop();
}

int duration=60;


void motor(short right, short left) {
	Mtr_Run_lv(right,-left,0,0,0,0);
}


void stop(void) {
	motor(0,0);
	Wait(1000);
}

void end(void) {
	motor(0,0);
}

void step(void) {
	motor(10000,9500);
	Wait(duration);
}

void Left(void) {
	motor(10000,0);
	Wait(duration);
}

void Right(void) {
	motor(0,9500);
	Wait(duration);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	unsigned short left;
	unsigned short right;

	int i,n;
	int kuro;

	kuro=300;


	for( ; ; ) {


		left = ADRead(0);
		right = ADRead(1);

		step();
		stop();
		LED(0);

		if(left>kuro && right>kuro) {
			i=0;

			for(; ;) {

				left = ADRead(0);
				right = ADRead(1);

				step();
				stop();

				if(left>kuro && right>kuro)
				{
					i +=1;  //チャージ
					LED(2);  //オレンジ
					play(DO);
				}
				else //黒以外
				{

					if(i>25) //長いテープ 解放
							{
						stop();
						for(n=0; n<i; n++) //i回LED点灯
						{
							LED(3);  //緑＋オレンジ
							play(SI);
						}
						break;
							}
					if(i>10) //中くらい 解放
					{
						stop();
						LED(3);  //緑＋オレンジ
						for(n=0; n<i; n++)
						{
							play(SO);
						}
						end();
					}
					if(i<=10)
					{
						break;
					}

				}
			}

		}
		else if(left>=kuro && right<kuro) {  //左に行きます
			LED(1);  //緑
			Left();
		}

		else if(left<kuro && right>=kuro) {  //右に行きます
			LED(1);  //緑
			Right();
		}
	}


	return 0;
}

