#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値

int x=500;

void sub1(void)
{
	int x;
	x=3;
	printf("x=%d\n",x);
}
void sub2(void)
{
	x=300;
	printf("sub2=%d\n",x);
}
int main(void)
{
	printf("before:x %d\n",x);
	sub2();
	printf("qfter:x %d",x);
}
