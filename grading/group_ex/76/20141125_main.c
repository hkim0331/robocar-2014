#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM
#define BLACK 500
#define MI 142
#define VOL 100

void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);

}
void stop1(void) {
	motor(0,0);
	Wait(1000);
}






void step(void) {
	motor(10000,9500);
	Wait(100);
	stop1();

}


void Left(void)


{Mtr_Run_lv(10000,10000,0,0,0,0);
Wait(80);
Mtr_Run_lv(0,0,0,0,0,0);

}


void Right(void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);


}

void group(void)
{
	unsigned short left;
	unsigned short right;
	int blacks;
	for(; ;){
		left=ADRead(0);
		right=ADRead(1);

		step();
		stop1();
		if(left>BLACK && right>BLACK){
			blacks=0;
			for(;;){
				left = ADRead(0);
				right = ADRead(1);
				step();


				if(left>BLACK && right>BLACK){
					blacks +=1;
					BuzzerSet(MI,VOL);
					BuzzerStart();
					Wait(80);
					BuzzerStop();
					Wait(80);

				}


				else{

					if(blacks>20 )
					{


						BuzzerSet(MI,VOL);
						BuzzerStart();
						Wait(80);
						BuzzerStop();
						Wait(80);

						break;
					}
				}
				if(blacks>4)
				{stop();

				}

				if(blacks<=4){
					break;

				}}}

		else if(left<BLACK && right<BLACK){

			step();


		}else if(left>BLACK && right<BLACK){

			Left();



		}else if(left<BLACK && right>BLACK){
			Right();


		}

		else  {
			;

		}



	}




}





int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	group();


	return 0;
}

