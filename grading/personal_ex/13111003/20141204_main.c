#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void motor(short left, short right){

	Mtr_Run_lv(left, -right, 0,0,0,0);

}


void stop(void){

	motor(0,0);

}


void forward(int mm){


	LED(LED_LEFT + LED_RIGHT);
	    motor(LEFT_POWER, RIGHT_POWER);
	    Wait(MM * mm);
	    stop();

	}

void turn(uint8_t dir){


	if(dir == LEFT){
		LED(LED_LEFT);
		motor(LEFT_POWER/3,RIGHT_POWER);
	} else if (dir ==)






	}



}






int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

