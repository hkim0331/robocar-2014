#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define SX	 10200
#define SY	-10000

#define TX	10000
#define TY	10000


void Stop(int s) {
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(s);
}

void Turn(void) {

	Mtr_Run_lv(TX, TY, 0, 0, 0, 0);
	Wait(500);

}

void MoveSt(void){
	Mtr_Run_lv(SX, SY, 0, 0, 0, 0);
	Wait(2500);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	Stop(1000);
	int i;
	for (i=0; i<4; i++) {
		MoveSt();
		Turn();
	}
	Stop(1);

	return 0;
}

