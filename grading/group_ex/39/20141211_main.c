#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*ADReadの左と右*/
#define Read_left 0
#define Read_right 1

/*継続時間*/
#define WAIT 100
#define WAIT_L 200
#define WAIT_S 100
#define WAIT_START 1000

#define SOUND 200

#define DURATION 200
#define PAUSE 50
#define VOL 100

#define count 5

int count100(int n)
{
	int i = 0;
	for(;;){
		n -= 100;
		if(n >= 0){
			i += 1;
		}else{
			break;
		}
	}
	return i;
}

int count10(int n)
{
	int i = 0;
	int j = n;
	for(;;){
		n -= 10;
		if(n >= 0){
			i += 1;
		}else{
			break;
		}
	}
	i -= count100(j)*10;
	return i;
}

int sum(int x[], int a, int b)
{
	int j = 0;
	int i;
	for(i = a; i < b; i++){
		j += x[i];
	}
	return j;
}

int average(void)
{
	int x[count], i;

	for(i = 0; i< count; i++){
		x[i]=ADRead(Read_left);
		Wait(WAIT);
	}
	return sum(x, 0, count)/count;

}

void play(int pitch, int w)
{
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(w);
	BuzzerStop();
	Wait(PAUSE);
}


void color_reader(int n)
{
	int a,b;
	a = count100(n);
	b = count10(n);
	for(; a > 0; a--)
	{
		play(SOUND, WAIT_L);
	}
	for(; b > 0; b--)
	{
		play(SOUND, WAIT_S);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		Wait(WAIT_START);
		LED(3);
		color_reader(average());
		LED(0);
	}


	return 0;
}
/*赤　　40	40	50

水色  50	50	50

緑    60    60    60

灰    280	280     270

白　　　40　　　40　　40

黄色   40     50   40

黒      890    890   880*/
