#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


	void motor() {
	    Mtr_Run_lv(10000, -10500, 0, 0, 0, 0);
	    Wait(5000);
	}

	void stop(void) {
	    motor(0,0);
	}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


		motor();
		stop();

	return 0;
}

