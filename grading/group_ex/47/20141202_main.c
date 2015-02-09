#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(150);
  BuzzerStop();
  Wait(150);
}

int average(void) {
  int x0,x1, x2, x3, x4;

  x0 = ADRead(0);
  Wait(100);
  x1 = ADRead(0);
  Wait(100);
  x2 = ADRead(0);
  Wait(100);
  x3 = ADRead(0);
  Wait(100);
  x4 = ADRead(0);

  return (x0+x1+x2+x3+x4)/5;
}

void color(void) {
  int i;
  int n=average();

  for (i=0; i<n; i+=1) {
    beep();
  }
}

int main(void)

{
	const unsigned short MainCycle = 60;
		Init(MainCycle);

			Wait(500);

	color();

return 0;

}
//
//赤44
//白46
//黄49
//青50
//緑56
//黒80
