#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define Black 600
#define hai 150
#define l 10000
#define r 8500

void moter(int LEFT,int RIGHT){
	Mtr_Run_lv(-LEFT,-RIGHT,0,0,0,0);
	}

void stop(){
	moter(0,0);
}

void step(int a){
	moter(l/a,r/a);
	Wait(100);
	stop();
}

void Right(int b){
	moter(l/b,0);
    Wait(20);
    stop();
    Wait(100);
}

void Left(int c){
	moter(0,r/c);
    Wait(20);
    stop();
}

void slalom(){
	unsigned short left;
		unsigned short right;
		    for(;;){
		    	left=ADRead(0);
		    	right=ADRead(1);
		     if(left>Black && right>Black)
		    	    	step(1);
		     else if(left>Black)
		    	 Left(1);
		     else if(right>Black)
		    	 Right(1);
		     else
		    	 step(1);

		    }
		    stop();
}

void sslalom(){
	unsigned short left;
		unsigned short right;
	    for(;;){
	    	left=ADRead(0);
	    	right=ADRead(1);
	     if(left>hai && right>hai)
	    	    	step(2);
	     else if(left<hai)
	    	 Right(2);
	     else if(right<hai)
	    	 Left(2);
	     else
	    	 step(2);

	    }
	    stop();
}


void dec(){
	unsigned short left;
	unsigned short right;
	for(;;){
		if(hai<left && left<Black)
		sslalom();
		else if(left<hai && right<hai)
			slalom();
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(;;){
    slalom();
	}
	return 0;
}

