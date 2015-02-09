#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10


void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average(int a[], int from, int to){
	int ret=0;
	int i;
	for (i=from; i<to; i++){
		ret +=a[i];
	}
	return ret/(to-from);
}


int color(int n){
    int i[n];
    int b;
for(b=0;b<100;b++){
    i[n]=ADRead(0);
    Wait(10);//10wait読み込む
}

}

int main(void)
{
const unsigned short MainCycle = 60;
	Init(MainCycle);
Wait(1000);
LED(3);

int x;
int y;
int z;

y=n/100;
z=n%10;



while(x>0){
	beep(500);
	x--;
}
while(y>0){
	beep(100);
		y--;

}

return 0;
}

