#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch)
{
	 BuzzerSet(pitch, 100);
		    BuzzerStart();
		    Wait(400);
		    BuzzerStop();
		    Wait(100);

}
void Do(void){
	play(179);
}
void Re(void){
	play(160);
}
void Mi(void){
	play(142);
}
void Fa(void){
	play(134);

}
void So(void){
	play(120);

}
void Ra(void){
	  play(107);

}
void Si(void){
	play(95);
}
int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

   Do();
   Do();
   So();
   So();
   Ra();
   Ra();
   So();
   Fa();
   Fa();
   Mi();
   Mi();
   Re();
   Re();
   Do();
   Ra();
   Ra();
   So();
   So();
   Mi();
   Mi();
   Re();
   Ra();
   Ra();
   So();
   So();
   Mi();
   Mi();
   Re();



    return 0;
}


