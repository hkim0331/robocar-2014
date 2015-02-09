#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void)
{
	Mtr_Run_lv(10600,-10000,0,0,0,0);
	Wait((5000/70)*30);//30cm分進む
}
void round(void)
{
	Mtr_Run_lv(-10500,-10000,0,0,0,0);//右まわりで回転
	Wait(500);//a角形の角度分回転する
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	/*Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);*/
	//Mtr_Run_lv(10600,-10000,0,0,0,0);//(右、左、その他拡張用モーター)
	/*Mtr_Run_lv(-10600,-10000,0,0,0,0);
	Wait(5000/8);右に90度回転*/
	/*Mtr_Run_lv(10600,10000,0,0,0,0);
	Wait(5000/2);
	Mtr_Run_lv(0,0,0,0,0,0);*/
	int i;

	for(i=0;i<4;i++){
		run();//4回繰り返す
		round();
	}
	return 0;
}

