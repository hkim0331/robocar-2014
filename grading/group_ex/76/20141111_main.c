#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE    0
#define RIGHT_EYE   1


void step(void)

{

	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}



void ex1_1(void)
{

    Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(5000);
    Mtr_Run_lv(0,0,0,0,0,0);
}
void ex2_4(void)


{Mtr_Run_lv(10000,10000,0,0,0,0);
    Wait(175);
    Mtr_Run_lv(0,0,0,0,0,0);
    Mtr_Run_lv(10000,-10000,0,0,0,0);
            Wait(50);
            Mtr_Run_lv(0,0,0,0,0,0);

    }


void ex2_3(void)
{
    Mtr_Run_lv(-10000,-10000,0,0,0,0);
    Wait(175);
    Mtr_Run_lv(0,0,0,0,0,0);
    Mtr_Run_lv(10000,-10000,0,0,0,0);
        Wait(50);
        Mtr_Run_lv(0,0,0,0,0,0);


    }

void group (void)
{
	unsigned short left;
	unsigned short right;
	for(; ;){
		step();
		left=ADRead(0);
        right=ADRead(1);

		if(left<500 && right<500)
		{
			;

		}else{
if(left<500 && right>500)
{
	ex2_3();
}
else{
	if(left>500 && right<500){
		 ex2_4();
}
	else{
		break;
	}

	}
	}


}
}














int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

group();

	return 0;
}

