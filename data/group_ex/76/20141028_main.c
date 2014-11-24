#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex1_1(void)
{

    Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(5000);
    Mtr_Run_lv(0,0,0,0,0,0);
}
void ex1_2(void)
{   Wait(2000);
    Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(5000);
    Mtr_Run_lv(0,0,0,0,0,0);
}
void ex2_1(void)
{
    Wait(2000);
    Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(50);
    Mtr_Run_lv(0,0,0,0,0,0);

}
void ex2_2(void)
{
    Wait(2000);
    Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(500);
    Mtr_Run_lv(0,0,0,0,0,0);
    }
void ex2_3(void)
{
    Wait(2000);
    Mtr_Run_lv(-10000,10000,0,0,0,0);
    Wait(250);
    Mtr_Run_lv(0,0,0,0,0,0);

}
void ex2_4(void)
{
    Wait(2000);
    Mtr_Run_lv(10000,10000,0,0,0,0);
    Wait(353);
    Mtr_Run_lv(0,0,0,0,0,0);

    }
void ex2_5(void)
{
    Wait(2000);
    Mtr_Run_lv(10000,10000,0,0,0,0);
    Wait(1410);
    Mtr_Run_lv(0,0,0,0,0,0);


}
void ex3_1(void)
{
    Wait(2000);
    Mtr_Run_lv(20000,-20000,0,0,0,0);
    Wait(250);
    Mtr_Run_lv(0,0,0,0,0,0);
    }
void ex3_2(void)
{
    Wait(2000);
    Mtr_Run_lv(5000,-5000,0,0,0,0);
    Wait(1000);
    Mtr_Run_lv(0,0,0,0,0,0);

}
void group(void)
{

     Mtr_Run_lv(10000,-10000,0,0,0,0);
     Wait(1500);
     Mtr_Run_lv(0,0,0,0,0,0);

     Mtr_Run_lv(10000,10000,0,0,0,0);
     Wait(353);
     Mtr_Run_lv(0,0,0,0,0,0);


    }

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);
    int i;
Wait(2000);
for(i=0; i<4; i++){
group();
}
    return 0;
}
