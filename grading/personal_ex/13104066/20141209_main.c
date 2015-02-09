#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define A 10000
#define B -10000
#define C 800
#define D 0


void move(int one,int two){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Mtr_Run_lv(one,two,0,0,0,0);
	Wait(100);

}
void step(void){
	move(A,B);
}
void stop(void){
	move(D,D);
}
void hidari(void){
	move(A,A);
}
void migi(void){
	move(B,B);
}
void slalom(void){

	unsigned short left;
	unsigned short right;

	int blacks=0;

	for(;;){
		step();

		left=ADRead(0);
	    right=ADRead(1);
	     if(right< C && left<C){
		    blacks=0;
	      }else if(right > C&& left>C){
	          blacks+=1;

	    	  if(blacks>15){
	    	  		break;
	    	  	}else {
                   ;
	    	  	}
			// LED(1);
		  }
			  else if(left > C){

			 hidari();
			// LED(2);
		  }else if(right>C){
			migi();
			// LED(3);
		  }
	}


	stop();
}

int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	slalom();

	return 0;
}

