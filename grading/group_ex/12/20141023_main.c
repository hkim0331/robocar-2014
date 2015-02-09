#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int x,int y,int t){
 Mtr_Run_lv(x,y,0,0,0,0);
 Wait(t);
 Mtr_Run_lv(0,0,0,0,0,0);
}
void front(){
	play(10100,-10000,2916);
}
void left(){
	play(10000,0,900);
}
void fl(){
	front();
	Wait(1000);
	left();
	Wait(1000);
}
void finish(){
	BuzzerSet(120,100);
	BuzzerStart();
	Wait(750);
	BuzzerStop();

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	fl();
	fl();
	fl();
	front();
	finish();

	return 0;
}

