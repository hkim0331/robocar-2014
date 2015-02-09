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

void forward()
{
  motor(LEFT, RIGHT);
  Wait(500);
  stop();

}

void right (){
	motor(LEFT,RIGHT/2);
	Wait(1200);
	stop();
}

void left (){
	motor(LEFT/2,RIGHT);
	Wait(1200);
	stop();
}


unsigned short x;
unsigned short y;
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	  int i ;
	  for (i=0; i <50000 ; i++) {
	    forward(EDGE);

	    x=ADRead(1);
	    y=ADRead(0);


	    if((x>700) && (y>700)){
	    	stop();
	    }
	    else if (x > 700){
	    	left();
	   }else if(y>700){

	   right();

	   }else{
		   forward();

	   }
	  }

	return 0;
	  }

