#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

 void run(){
	Mtr_Run_lv(14000,-14000,0,0,0,0);
    Wait(50);
	Mtr_Run_lv(0,0,0,0,0,0);
	}

 void right(){
	 Mtr_Run_lv(5000,0,0,0,0,0);
	 Wait(50);
	 Mtr_Run_lv(0,0,0,0,0,0);
   }

 void left(){
 	 Mtr_Run_lv(0,-5000,0,0,0,0);
 	 Wait(50);
 	 Mtr_Run_lv(0,0,0,0,0,0);
    }
void sound(){
	BuzzerSet(120,100);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
	Wait(2000)
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    int i;
	for(i=0;i<100000000;i++){
	if((ADRead(1)<500)&&(ADRead(0)<500)){
	    run();
	}
	else if((ADRead(1)>500)&&(ADRead(0)>500)){
		Mtr_Run_lv(0,0,0,0,0,0);
        sound();
	    break;
		}
	else if(ADRead(1)>500){
	 left();
	}
	else if(ADRead(0)>500){
	  right();
	}
	}


	return 0;
}

