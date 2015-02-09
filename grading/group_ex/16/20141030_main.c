#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10025

#define EDGE 5

#define FW 40


void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void forward(int m)
{
  motor(LEFT, RIGHT);
  Wait(FW * m);
  stop();

}


unsigned short x;

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	  Wait(1000);
	  int i ;
	  for (i=0; i <50000 ; i++) {
	    forward(EDGE);
	    Wait(1000);
	    x=ADRead(0);
	    if (x > 300){
	    	break;
	   }else{;}

	    BuzzerSet(100,100);
	    BuzzerStart();
	    Wait(1000);
	    BuzzerStop();
	  }

	return 0;
}

