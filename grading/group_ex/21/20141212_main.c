#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



#define N 500
#define MM 20
#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT    1
#define RIGHT   0
#define LONG 7
#define SHORT 3
#define BLACK 700

void beep(int y)
{
int i;
for(i=0;i<y;i++){
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
	}
}

void motor(short left, short right)
{
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
    motor(0,0);
}

void forward(int mm)
{

    motor(LEFT_POWER, RIGHT_POWER);
    Wait(MM * mm);
    stop();
}

void turn(uint8_t dir)
{
    if (dir == LEFT) {

        motor(LEFT_POWER/3,RIGHT_POWER);
        Wait(MM);
        stop();
    } else if (dir == RIGHT) {

        motor(LEFT_POWER,RIGHT_POWER/3);
        Wait(MM);
        stop();
    }
}

void step(int n)
{
    forward(n);
    stop();
}

int is_black(uint8_t n)
{
    return ADRead(n) > BLACK;
}

int is_white(uint8_t n)
{
    return ! is_black(n);
}



void length (void)
{
	int i, blacks, x;
	blacks = 0;

	for(i=0; i<N; i++){

		if (is_white(LEFT) && is_white(RIGHT)){

			step(5);
			Wait(500);


		} else if(is_black(LEFT) && is_black(RIGHT)){

			for(x=0;x<N;x++){
				if(is_white(LEFT) || is_white(RIGHT)){
					break;
				} else {
					blacks += 1;
					step(5);
				}
			}

			if (blacks > LONG) {

				beep(blacks);

			} else if (blacks >= SHORT) {

				beep(blacks);
				break;

			} else {

				beep(blacks);

			}
			blacks=0;

		} else if (is_black(LEFT)){
			turn(LEFT);

		} else if(is_black(RIGHT)){
			turn(RIGHT);

		} else {
			step(1);
		}
	}
	stop();
}



int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

      Wait(1000);

      length();

  return 0;

}
