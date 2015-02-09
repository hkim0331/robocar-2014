#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void oto1(void)
{
	BuzzerSet(179,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(100);
}
void oto2(void)
{
	BuzzerSet(120,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(100);
}

int sum(int x[],int start,int end)
{
	int total=0;
	int i;

	for( i=start; i<end; i++)
	{

		total+=x[i];
	}
	return total;

}
int average(void)
{
	int x[5];
	int i;

	for( i=0; i<5 ; i++ )
	{

		x[i]=ADRead(0);
		Wait(100);

	}

	return sum(x,0,5)/5;
}

void color(void)
{
	int i;
	int n=average();

	if(n>0 && n<200)
	{
		for( i=0; i<n ;i+=10)
		{
			oto1();

		}
	}
	else {
		for( i=0; i<n ;i+=100)
		{
			oto2();


		}
	}
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	color();
	return 0;
}

/*
暗い順に

黒 900
グレー 500
緑　300
青　100
黄　80
赤　70
白　60


 */
