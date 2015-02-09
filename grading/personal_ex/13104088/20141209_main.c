#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  3400
#define RIGHT_POWER 3400
#define SPEED       5000
#define RIGHT          1 //for_ADRead(n)
#define LEFT           0
#define GB           700 //border_between_brack_and_Gray
#define WB           300 //border_between_gray_and_White
void motor(short left, short right)
{
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}
void stop(void)
{
	motor(0,0);
}
void forward(void)
{
	motor(SPEED+1000,SPEED);
}
void step(void)
{
    motor(LEFT_POWER, RIGHT_POWER);
    Wait(150);
    stop();
}
void turn_right(void)
{
	motor(LEFT_POWER,0);
}
void turn_left(void)
{
	motor(0,RIGHT_POWER);
}
void run(void)
{
    unsigned short Left,Right,Left2,Right2;
    for(;;)
    {
    	Left = ADRead(LEFT);
    	Right = ADRead(RIGHT);
    	int c=0;

    	if((Left<GB) && (Right<GB))
    	{
    		step();
    	}
    	if((Left>GB) && (Right>GB))
    	{
    		stop();
    		for(;;)
    		{
    			Left2 = ADRead(LEFT);
    			Right2 = ADRead(RIGHT);
    			if((Left2>WB) && (Right2>WB))
    			{
    				step();
    				c +=1;
    			}else if((Left2<WB) && (Right2<WB))
    			{
    				forward();
    				break;
    			}else if((Left2<WB) && (Right2>WB))
    			{
    				turn_right();
    			}else if((Left2>WB) && (Right2<WB))
    			{
    				turn_left();
    			}
    		}
    		    if(c<15){
    		    	break;
    		    }
    	}else if((Left>=GB)&&(Right<GB))
		{
			turn_left();
		}else if((Left<GB)&&(Right>GB))
		{
			turn_right();
		}
	}
   stop();
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(500);
	run();

	return 0;
}

