#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define length 500
#define shortlength 200

int L ;

void beep(L) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(L);
  BuzzerStop();
  Wait(100);
}


int average(int n) {
  int x[n];
  int i;
 int Ret = 0;

  for (i=0;i<n;i++) {
    x[i] = ADRead(0);
    Wait(100);
    Ret += x[i];
  }
  return Ret/n;
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);

	for ( ; ; ){
		int A;
		A = average;

		beep(500);
		Wait(A/100);

		beep(100);
		Wait(A%100);

		Wait(2000);
	}

	return 0;
}

