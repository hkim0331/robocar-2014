#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define RA 107
#define SO 120

void step(void)
{
	Mtr_Run_lv(10000,-9000,0,0,0,0);
	Wait(5000/50);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void migimawari(void)
{
	Mtr_Run_lv(-7500,-7500,0,0,0,0);
	Wait(5000/50);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void hidarimawari(void)
{
	Mtr_Run_lv(7500,7500,0,0,0,0);
	Wait(5000/50);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void play(int x)
{
	BuzzerSet(x,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left,right;

	int j=0;

	for(;;){
		j++;
		left=ADRead(0);
		right = ADRead(1);

		if(left>700 && right>700){//黒の時
			Mtr_Run_lv(0,0,0,0,0,0);
			Wait(50);
			step();
			play(RA);
		}else if(left<700 && right <700){//白の時
			Mtr_Run_lv(0,0,0,0,0,0);
			Wait(50);
			step();
			play(SO);
			if(j<=60){
				;
			}else {
				break;
			}

		}else if(left>800){//左が黒
			hidarimawari();
		}else if(right>800){//右が黒
			migimawari();
		}
	}

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(100);
	return 0;
}
