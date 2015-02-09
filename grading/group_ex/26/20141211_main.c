#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#include <math.h>

#define  FROM   0
#define  TO     10   /*測定回数5*/

#define  DO   179
#define  SO   120

int judge(int y)
{
	if (y==10) return 10;
	else if (y==100) return 100;
}

int count(int x, int y)
{
	int a=0, b=0, c=0;

	b=judge(y);
	if (b==10)
	{
		a = x - 100*count(x, 100);
	}
	else if (b==100)
	{
		a = x;
	}

	while(a>=b)
	{
		a -= b;
		c ++;
	}

	return c;
}

int sum(int x[])
{
	int i, total=0;

	for (i=FROM; i<TO; i++)
	{
		total += x[i];
	}
	return total;
}

int average(void)
{
	int i, x[TO];

	for (i=0;i<TO;i++)
	{
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x)/TO;
}

void beep(int y)
{
	int i, k, pitch=0;

	switch(judge(y))
	{
		case 10:
			pitch=DO;
			break;

		case 100:
			pitch=SO;
			break;

		default:
			break;
	}
	k = count(average(), y);
	for (i=0; i<k; i++)
	{
		BuzzerSet(pitch, 100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		Wait(250);
	}
}

void color(void)
{
	beep(100);
	Wait(1000);
	beep(10);
	Wait(1000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}

/*測定結果*/
/*赤：40, 黄：40, 緑：60, 灰：220, 青：40*/
/*ちなみに*/
/*黒：890*/
/*それらしい値がでた．*/
