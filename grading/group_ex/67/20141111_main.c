#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Run(){
	Mtr_Run_lv(7200,-9000,0,0,0,0);

}
void TurnR(){
	Mtr_Run_lv(7200,0,0,0,0,0);
	Wait(180);
	Mtr_Run_lv(0,0,0,0,0,0);
    Mtr_Run_lv(7200,-9000,0,0,0,0);
    Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void TurnL(){
	Mtr_Run_lv(0,-9000,0,0,0,0);
	Wait(180);
	Mtr_Run_lv(0,0,0,0,0,0);
    Mtr_Run_lv(7200,-9000,0,0,0,0);
    Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void Stop(){
	Mtr_Run_lv(0,0,0,0,0,0);


}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	for( ; ; ){

		Run();
		unsigned short left;
		unsigned short right;
		left=ADRead(0);
		right=ADRead(1);
		 if(left>500 && right<500)
		{
			TurnR();
		}

		else if(left<500 && right>500)
		{
			TurnL();

		}
		else if(left>500 && right>500){
			break;
		}
		}

Stop();


	return 0;
}
