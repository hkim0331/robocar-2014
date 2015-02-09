#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000
#define FW 40
#define TN 8
#define EDGE 30

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}


void stop(void){

	motor(0,0);
}


void forward(int n)
{
  Wait(0);
  motor(LEFT, RIGHT);
  Wait(50);
  stop();
}


void music(void){

	BuzzerSet(120, 100); // ピッチ 120、ボリュームは 100 だ。
	  BuzzerStart();       // ブザー鳴れ。
	  Wait(3000);          // 3秒待つ。
	  BuzzerStop();        // 鳴りやめ。
}





int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);




	int i;

	for(i=0;i<1000;i++){
		forward(EDGE);
		Wait(1000);

		if(ADRead(0)>500)
			break;

		}

	music();
	return 0;
}

