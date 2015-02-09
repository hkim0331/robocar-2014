#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void go(void){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);

}
void step(void){
	int i;
	for(i=0; i<4; i++){
		go();
	    }
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	step();
	return 0;
}

