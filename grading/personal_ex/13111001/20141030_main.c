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



void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(10);

}


void stop(void){

	motor(0,0);
}










int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	int i;

	for(i=0;i<10;i++){
		forward(EDGE);
		stop();
		}
	return 0;
}

