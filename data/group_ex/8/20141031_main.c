#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define FW 100

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
	int i ;
    unsigned short bw;
	for( ; ; ){
       forward();
		stop();
	   bw = ADRead(0);

if (bw > 700){
	break ;
}
else{
	;
}

}

   return 0;
}



void motor(short left, short right)
{
	Mtr_Run_lv(left,-right,0,0,0,0);
}
void stop(void)
{
  motor(0,0);
  Wait(300);
}
void forward(int n)
{
	motor(LEFT,RIGHT);
	Wait(FW);
	stop();
}



