#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define BLACK 500
#define LT 0
#define RT 1
#define SP 5000
#define SO 120

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
	Motor(SP+500,-SP);
}

void step(void)
{
	Motor(SP+500,-SP);
	Wait(100);
	stop();
	Wait(350);
}

void turn_left(void)
{
	Motor(SP+2500,0);
}

void turn_right(void)
{
	Motor(0,-(SP+2500));
}

void music(void)
{
	BuzzerSet(SO, 100);
	BuzzerStart();
	Wait(250);
	BuzzerStop();
	Wait(250);
}

void Run(void)
{
	unsigned short LEFT1,RIGHT1,LEFT2,RIGHT2;

	for(;;){
		LEFT1=ADRead(LT);
		RIGHT1=ADRead(RT);
		int c=0,i;

		if((LEFT1<BLACK)&&(RIGHT1<BLACK))
		{
			foward();
		}else if((LEFT1>=BLACK)&&(RIGHT1>=BLACK))
		{
			stop();
			for(;;){//黒＆黒になるとこの無限ループにはいる
				LEFT2=ADRead(LT);
				RIGHT2=ADRead(RT);

				if(LEFT2>=BLACK && RIGHT2>=BLACK)
				{
					step();
					c +=1;
				}
				else if(LEFT2<BLACK && RIGHT2<BLACK)//白＆白でこのループから抜け出す
				{
					stop();//止まって
					for(i=1;i<=c;i++)
					{
						LED((i%2)+1);//光って
						music();//音出して
					}
					LED(0);
					break;
				}
				else if(LEFT2<BLACK && RIGHT2>=BLACK)
				{
					turn_right();
				}
				else if(LEFT2>=BLACK && RIGHT2<BLACK)
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

