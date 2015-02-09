#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  7000
#define RIGHT_POWER 7000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20
#define BLACK 500
#define GRAY 80

void motor(short left, short right) {
 Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
 motor(0,0);
}


void forward1(int mm) {
 motor(LEFT_POWER, RIGHT_POWER);
 Wait(MM * mm);
 stop();
}

void forward2(int mm) {
 motor(LEFT_POWER*4/5, RIGHT_POWER*4/5);
 Wait(MM * mm);
 stop();
}


void turn1(uint8_t dir){
 LED(0);
 stop();
 Wait(40);
 if (dir == LEFT) {
  motor(-LEFT_POWER/3,RIGHT_POWER*4/3);
 }else if(dir == RIGHT){
  motor(LEFT_POWER*4/3,-RIGHT_POWER/3);
 }
 Wait(100);

}

void turn2(uint8_t dir){
 LED(LED_LEFT + LED_RIGHT);
 if (dir == LEFT) {
  motor(LEFT_POWER/3,RIGHT_POWER*2/3);
 }else if(dir == RIGHT){
  motor(LEFT_POWER*2/3,RIGHT_POWER/3);
 }
 Wait(100);
}

void turnright90(void){
 motor(-LEFT_POWER,RIGHT_POWER);
 Wait(800);
}
void step1(int n) {
 LED(0);
 forward1(n);
}

void step2(int n) {
 forward2(n);
 LED(LED_LEFT + LED_RIGHT);
}
 int is_black(uint8_t n) {
 return ADRead(n) > BLACK;
}

int is_gray(uint8_t n){
 return (ADRead(n)<BLACK)&&(ADRead(n)>GRAY);
}

int is_white(uint8_t n) {
 return ADRead(n)<GRAY;
}


void dec(){
 int i;
 int blacks;
 blacks=0;
 for(i=0;i<100000;i++){
  if(is_white(LEFT) && is_white(RIGHT)){
	step1(5);
   }else if (is_black(LEFT) && is_black(RIGHT)){
  	blacks += 1;
  	if(blacks==5){
  	turnright90();
    }else if(blacks>=15){
  	 stop();
  	}else{
  	 step1(5);
  	}
   }else if (is_black(LEFT)&&is_white(RIGHT)){
   	turn1(LEFT);
   }else if (is_white(LEFT)&&is_black(RIGHT)){
   	turn1(RIGHT);
   }else if(is_gray(LEFT)&&is_gray(RIGHT)){
  	 step2(5);
   }else if(is_gray(LEFT)&&is_white(RIGHT)){
	turn2(LEFT);
   }else if (is_white(LEFT)&&is_gray(RIGHT)){
	turn2(RIGHT);
   }else{
     ;
   }
 }
}

int main(void)
{
 const unsigned short MainCycle = 60;
 Init(MainCycle);
 dec();
 return 0;
}
