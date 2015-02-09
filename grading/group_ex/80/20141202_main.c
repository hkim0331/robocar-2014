#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define Do 90


void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
}


int sum(int a[], int from, int to)
{
	int ret=0;
	int i;

	for (i=from; i<to; i++)
	{
		ret += a[i];
	}
	return ret;
}

int average(int n)
{
	int x[n];
	int i;

	for (i=0;i<n;i++)
	{
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,n)/n;
}


int color(void)
{
	int n=5;
	int a,b,c,d,e,f,g,h;

	a=50; b=52; c=55;
	d=60; e=100; f=150;
	g=175; h=300;

	if(average(n)<a)
	{
		play(DO);
		play(SO);
	}
	else if(a<=average(n) && average(n)<b)
	{
		play(RE);
		LED(3);
	}
	else if(b<=average(n) && average(n)<c)
	{
		play(MI);
		LED(1);
	}
	else if(d<=average(n) && average(n)<65)
	{
		play(FA);
		LED(2);
	}
	else if(65<=average(n) && average(n)<70)
		{
			play(SO);
			LED(3);
		}
	else if(e<average(n) && average(n)<f)
	{
		play(RA);
		LED(1);
	}
	else if(f<average(n) && average(n)<g)
	{
		play(SI);
		LED(2);
	}
	else if(g<= average(n) && average(n)<h)
	{
		play(Do);
		LED(3);
	}
	else
	{
		play(Do);
		play(DO);
		LED(1);
	}
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();


	return 0;
}

//色の濃さ
//白<黄<赤<青<緑<灰
