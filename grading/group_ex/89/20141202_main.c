#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define R_pw 10500
#define L_pw 10000

#define FF 0
#define RR 1
#define LL 2
#define BB 3

#define END (-1)


void base(int right, int left, int time)
{
    Mtr_Run_lv(right, -left, 0, 0, 0, 0);
    Wait(time);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void forward(int time)
{
	base(R_pw, L_pw, time);
}

void R_turn(int time)
{
	base(0, L_pw, time);
}

void L_turn(int time)
{
	base(R_pw, 0, time);
}

void back(int time)
{
	base(-R_pw, -L_pw, time);
}

void go(int course[], int time[])
{
    int i;
    for(i=0; course[i]!=END; i++){
        if(course[i] == FF){
            forward(time[i]);
        } else if (course[i] == RR){
            R_turn(time[i]);
        } else if (course[i] == LL){
            L_turn(time[i]);
        } else if (course[i] == BB){
            back(time[i]);
        }
    }
}

void run(void)
{
    int course[] = {FF, RR, LL, FF, BB, END};
    int time[] = {1000, 500, 1000, 500, 1000};

    go(course, time);
}


int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    Wait(1000);
    run();

    return 0;
}
