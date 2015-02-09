#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define FW 100

void step (void){
    Mtr_Run_lv(10000, -10000,0,0,0,0);
	Wait(200);
	Mtr_Run_lv(0,0,0,0,0,0);
}
	return 0;
}

