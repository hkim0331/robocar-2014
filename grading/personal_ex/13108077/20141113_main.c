#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void sound(int p){
	Buzzerset(g,100);
	Buzzerstart();
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
	while(1){
		LED(1);

		Wait(1000)
	return 0;
}

