#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define BLACK 500
#define LEFT_EYE    0
#define RIGHT_EYE   1

		void runl()
		{
			Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
						Wait(100);
		}

		void runr()
			{
			Mtr_Run_lv(0, -10000, 0, 0, 0, 0);
						Wait(100);
			}

		void run()
			{
				Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
				Wait(100);
			}





int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);

	int i;
	for(;;)
	{
		if(ADRead(LEFT_EYE)>BLACK){
			if(ADRead(RIGHT_EYE)>BLACK){
				break;
			}
			else{
				LED(2);
				runl();
			}
		}
		else{
			if(ADRead(RIGHT_EYE)>BLACK){
			LED(1);
			runr();
			}
			else{
				LED(3);
				run();
			}
		}


	}

	Mtr_Run_lv(0, 0, 0, 0, 0, 0);


	return 0;

}

