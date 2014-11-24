#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define FW 70
#define N 50

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}
void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short bw;

	Wait(1000);
	int i;
	for (i = 0; i<N; i++){
		forward(1);
		Wait(1000);
		bw = ADRead(0);
		if (bw >600){
			break;
		} else {
			;
		}
	}
		BuzzerSet(100,100);
		BuzzerStart();




	return 0;
}

