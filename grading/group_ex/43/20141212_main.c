#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
int R = 6000; //right motor voltage
int L = 6000; //left motor voltage
int r;
int l;
int colorblack = 800;
int colorwhite = 300;
int countb = 0;
int countB[] = {4,16};
unsigned short left;
unsigned short right;
void step(r,l){
    Mtr_Run_lv(r, -l, 0, 0, 0, 0);
}
void stop(){
    step(0,0);
}
void straight(){
    step(r,l);
}
void turnR(){
    step(r*2,0);
    Wait(30);
}
void turnL(){
    step(0,l*2);
    Wait(30);
}
//void crankR(){
//    step(r,0);
//    Wait(100);
//}
//void crankL(){
//    step(0,l);
//    Wait(100);
//}
void buzzer(int n){
    int i;
    for(i=0;i<n;i++){
        BuzzerSet(179,100);
        BuzzerStart();
        Wait(100);
        BuzzerStop();
        Wait(100);
    }
}
void turngray(){
    if(left<colorwhite){
        turnL();
    }
    if(right<colorwhite){
        turnR();
    }
}
void turnblack(){
    if(left>colorblack){
        turnR();
    }
    if(right>colorblack){
        turnL();
    }
}
void runwhite(){
    turnblack();
    straight();
}
void rungray(){
	LED(3);
    r==R*3/5;
    l==L*3/5;
    for(;;){
        left = ADRead(0);
        right = ADRead(1);
        if((left<colorwhite ) && (right<colorwhite)){
        	LED(0);
            r=R;
            l=L;
            break;
        }
        turngray();
        straight();
    }
}
void countblack(){
    countb++;
    buzzer(countb);
    if(countb>countB[1]){
        stop();
    }
    else if(countb==countB[0]){
        turnL();
    }
    straight();
    Wait(500);
}
void run(){
	r=R;
	l=L;
    for(;;){
    	LED(0);
        left = ADRead(0);
        right = ADRead(1);
        if(left>colorblack && right>colorblack){
            countblack();   //if black
        }
        if((left<colorblack && left>colorwhite) && (right<colorblack  && right>colorwhite)){
            rungray();  //if gray
        }
        runwhite();
    }
}
int main(void){
    const unsigned short MainCycle = 60;
    Init(MainCycle);
    run();
    return 0;
}
