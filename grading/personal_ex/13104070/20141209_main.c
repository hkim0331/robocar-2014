#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define RT 1
#define LT 0
#define BLACK 600
#define GRAY 300

int s=5000;//speed

void Motor(short right,short left)
{
	Mtr_Run_lv(right,left,0,0,0,0);
}

void stop(void)
{
	Motor(0,0);
}

void foward(void)
{
	Motor(s+500,-s);
}

void turn_left(void)
{
	Motor(s+2500,0);
}

void turn_right(void)
{
	Motor(0,-(s+2500));
}

void step(void)
{
	Motor(s+500,-s);
	Wait(100);
	stop();
	Wait(350);
}

void Run(void)
{
	unsigned short LEFT1,RIGHT1,LEFT2,RIGHT2,;

	for(;;){
		LEFT1=ADRead(LT);
		RIGHT1=ADRead(RT);
		int c=0,i;

		if((LEFT1<BLACK&&LEFT1>GRAY)&&(RIGHT1<BLACK&&RIGHT1>GRAY))
		{
			s=s/2;
		}else{
			;;
		}

		if((LEFT1<GRAY)&&(RIGHT1<GRAY))
		{
			foward();
		}else if((LEFT1>=GRAY)&&(RIGHT1>=GRAY))
		{
			stop();
			for(;;){//黒＆黒になるとこの無限ループにはいる
				LEFT2=ADRead(LT);
				RIGHT2=ADRead(RT);

				if(LEFT2>=GRAY && RIGHT2>=GRAY)
				{
					step();
					c +=1;
				}
				else if(LEFT2<GRAY && RIGHT2<GRAY)//白＆白でこのループから抜け出す
				{
					for(i=1;i<=c;i++)
					{
						LED((i%2)+1);//光って
					}
					LED(0);
					break;
				}
				else if(LEFT2<GRAY && RIGHT2>=GRAY)
				{
					turn_right();
				}
				else if(LEFT2>=GRAY && RIGHT2<GRAY)
				{
					turn_left();
				}
			}
			if(c>5&&c<17)
			{
				break;
			}else{
				;;
			}
		}else if((LEFT1>=BLACK)&&(RIGHT1<BLACK))
		{
			turn_left();
		}else if((LEFT1<BLACK)&&(RIGHT1>=BLACK))
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
	Run();

	return 0;
}

