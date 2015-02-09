#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER -10000
#define LEFT    1
#define RIGHT   0

#define MM 20
#define BLACK 800
#define GREY 300


void motor(short left, short right) {
    Mtr_Run_lv(left, right, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
}

void forward(int mm) {
    motor(LEFT_POWER, RIGHT_POWER);
    Wait(MM * mm);
    stop();
}

void turn(int dir) {
    if (dir == LEFT) {
        motor(-LEFT_POWER,RIGHT_POWER);
    }
    else if (dir == RIGHT){
        motor(LEFT_POWER,-RIGHT_POWER);
    }
}

void step(int n) {
    forward(n);
    stop();
}

int is_black(int n) {
    return ADRead(n) > BLACK;
}

int is_white(int n) {
    return ADRead(n) < GREY;
}

int is_grey(int n){
     return (ADRead(n) < BLACK) && (ADRead(n) > GREY);
}

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    int blacks=0;

    while(1) {
        if (is_white(LEFT) && is_white(RIGHT)){
            motor(LEFT_POWER,RIGHT_POWER);
            blacks=0;
        }
        else if(is_grey(LEFT) && is_grey(RIGHT)){
            motor(LEFT_POWER,RIGHT_POWER);
            blacks=0;
        }
        else if (is_black(LEFT) && is_black(RIGHT)){
            step(17);
            Wait(500);
            blacks+=1;
            if(blacks == 3) break;
        }
        else if (is_black(LEFT)) {
            turn(LEFT);
            blacks=0;
        }
        else if (is_black(RIGHT)) {
            turn(RIGHT);
            blacks=0;
        }
        else if(is_grey(RIGHT)){
            turn(RIGHT);
            blacks=0;
        }
        else if(is_grey(LEFT)){
            turn(LEFT);
            blacks=0;
        }
        else{
            blacks=0;
        }
        if(blacks == 4){
            break;
        }
    }

    stop();

    return 0;

}


