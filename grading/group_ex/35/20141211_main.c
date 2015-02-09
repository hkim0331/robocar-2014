#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO              120
#define VOL             100
#define Read_count      100
#define Read_interval   50
#define Buzzer_interval 100




int sum(int x[], int to) {
	int i;
	int total = 0;

	for(i=0; i<to; i++) {
		total += x[i];
	}
	return total;
}

int average(void) {
	int i;
	int x[Read_count];

	for(i=0; i<Read_count; i++) {
		x[i] = ADRead(0);
		Wait(Read_interval);
	}
	return sum(x,Read_count)/Read_count;
}

int count100(int n) {
	return n/100;
}

int count10(int n) {
	return (n-count100(n)*100)/10;
}

void buzzer(int n, int time) {
	int i;

	for(i=0; i<n; i++) {
		BuzzerSet(SO, VOL);
		BuzzerStart();
		LED(3);
		Wait(time);
		BuzzerStop();
		LED(0);
		Wait(time);
	}
}

void color(void) {
	buzzer(count100(average()),Buzzer_interval*2);
	buzzer(count10(average()), Buzzer_interval);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	color();


	return 0;
}

/*
 * 黒　     840
 * 白        40
 * グレー   160
 * 赤        40
 * 黄色      40
 * 緑        50
 * 青        40
 */

