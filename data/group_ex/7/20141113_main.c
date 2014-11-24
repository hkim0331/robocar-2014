#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define G_LED LED(1)//緑
#define D_LED LED(2)//橙
#define GD_LED LED(3)//両方
#define OFF_LED LED(0)//消灯
#define dtime 100
#define on 10000

void forword(short mtsp){
    Mtr_Run_lv(on,-on,0,0,0,0);
    Wait(dtime);
}

void right(short mtsp){
    Mtr_Run_lv(-on,-on,0,0,0,0);
    Wait(dtime);
}

void left(short mtsp){
    Mtr_Run_lv(on,on,0,0,0,0);
    Wait(dtime);
}

void qstop(short mtsp){
    Mtr_Run_lv(0,0,0,0,0,0);
    Wait(dtime);
}


void led_flash(int flash,long d_time){
        int i;
        for(i=0;i<flash;i++){
                GD_LED;
                Wait(d_time);
                OFF_LED;
                Wait(d_time);
        }
}


int main(void)
{

	unsigned short LSensor;
	unsigned short RSensor;

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	 led_flash(3,100);

	      while(1){
	        LSensor=ADRead(0);
	        RSensor=ADRead(1);
	        if (LSensor >=256 && RSensor >=256){//両センサ=黒=seisi
	       	       	          GD_LED;
	       	       	          qstop(100);
	       	       	          break;
	       	       	        }
	        if(LSensor> 256){//左カーブ
	          D_LED;
	          left(100);
	        }
	        if(RSensor>256){//右カーブ
	          G_LED;
	          right(100);
	        }
	        if (LSensor <=256 && RSensor <=256){//両センサ=白=直進
	          OFF_LED;
	          forword(100);
	        }


	     }//while
}//main
