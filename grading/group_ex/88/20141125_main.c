#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define BLACK 700
#define WHITE 300
#define CAPACITY_HIGH 7
#define CAPACITY_LOW 3
#define DO 179


void motor(void){

    Mtr_Run_lv(10000,-10000,0,0,0,0);
}
void stop(void){

    Mtr_Run_lv(0,0,0,0,0,0);
}
void Step(void){

    motor();
    Wait(100);
    stop();
    Wait(100);
}
void buzzer(void){

    BuzzerSet(DO,100);
    BuzzerStart();
    Wait(200);
    BuzzerStop();
    Wait(200);
}
void left_turn(void){

    Mtr_Run_lv(10000,0,0,0,0,0);
    Wait(200);
    stop();
    Wait(200);

}
void right_turn(void){

    Mtr_Run_lv(0,-10000,0,0,0,0);
    Wait(200);
    stop();
    Wait(200);

}

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    int count=0;
    unsigned short left;
    unsigned short right;

    for(;;){

        int i;

        Step();
        left=ADRead(0);
        right=ADRead(1);

        if((left>BLACK)&&(right>BLACK)){

            count += 1;
            for(i=0;i<count;i++){
                buzzer();
            }

        }if((left<WHITE)&&(right<WHITE)){

            if((count>CAPACITY_HIGH)||(count<CAPACITY_LOW)){

                count=0;

            }if((count<CAPACITY_HIGH)&&(count>CAPACITY_LOW)){

                stop();
                break;

            }
        }
        if((left>BLACK)&&(right<BLACK)){

                left_turn();

            }if((left<BLACK)&&(right>BLACK)){

                right_turn();

            }
        }
    return 0;
}
