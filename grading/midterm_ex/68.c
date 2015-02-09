#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int migi()
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
    susumu();
}


int hidari()
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
    susumu();
}


int step()
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}

int tomaru()
{
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int susumu()
{
    unsigned short left,right;
        int i;
	    for( ; ; ) {
		    step();
			Wait(50);
			left=ADRead(0);
			right=ADRead(1);
			    if(600<left){break;
                }else if(600<right){break;
                }else if(600<right && 600<left){break;
			    }else{;}
	    }
	if(500<right && 500<left){
	    tomaru();
	}else if(500<right){
		migi();
	}else if(500<left){
		hidari();
    }else{;}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

susumu();

		return 0;
}
