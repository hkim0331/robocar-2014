#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define RIGHT_Eye 1
#define LEFT_Eye 0
#define Normal_Speed 1
#define Half_Speed 2
#define Black 600
#define hai 150
#define l 8990
#define r 10000
#define Angle_Time 40
#define LED_Stop 0
#define LED_Right 1
#define LED_Left 2

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

void Right_Angle(){
	moter(l,-r);
	Wait(Angle_Time);
	stop();
}

void Turn_Right(){
	moter(l,-r);
	Wait(20);
	stop();
}

void Turn_Left(){
	moter(-l,r);
    Wait(20);
	stop();
}

void slalom(){
	int blacks;
	int count=0;//この関数を実行するたび初期化されるから意味はない?youkairyou
	unsigned short left;
		unsigned short right;
		LED(LED_Stop);
		    for(blacks=0;blacks<5;){
		    	left=ADRead(LEFT_Eye);
		    	right=ADRead(RIGHT_Eye);
		    	if(count==4)
		    		Right_Angle();
		     if(left>Black && right>Black){
		       	step(Normal_Speed);
		       	blacks +=1;
		     }
		     else if(left>Black)
		    	 Left(Normal_Speed);
		     else if(right>Black)
		    	 Right(Normal_Speed);
		     else if(left>hai || right>hai)
		     	 break;
		     else{
		    	 step(Normal_Speed);
		    	 if(blacks>0){
		    		 count +=1;
		    	     blacks=0;
		    	 }
		     }
		    }
		    stop();
			LED(LED_Left + LED_Right);
		    hai_slalom();
}

void hai_slalom(){
	unsigned short left;
		unsigned short right;
	    for(;;){
	    	left=ADRead(LEFT_Eye);
	    	right=ADRead(RIGHT_Eye);
	    if(left>Black && right>Black)
	    	break;
	    else if(left>hai && right>hai)
	    	    	step(Half_Speed);
	    else if(left<hai && right<hai)
	    	break;
	     else if(left<hai)
	    	 Right(Half_Speed);
	     else if(right<hai)
	    	 Left(Half_Speed);
	    }
	    stop();
}

void dec(){
		for(;;){
			slalom();
		}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
		dec();

	return 0;
}

