#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define BL 700
#define GR 300


int i;
int s=0;


void GO(int x , int y){
	Mtr_Run_lv(x, -y, 0, 0, 0, 0);
}
void STOP(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void migi(void){
	Mtr_Run_lv(-5000, -5000, 0, 0, 0, 0);
}

void hidari(void){
	Mtr_Run_lv(5000, 5000, 0, 0, 0, 0);
}

void slalom(void){

	Wait(100);

		unsigned short left;
		unsigned short right;

		   for( ; ; ) {
		       left = ADRead(0);
		       right = ADRead(1);
		       if (right>BL && left>BL){
		    	   for(i=s;i<10;i++){
		    		   if(i<4){
		    			   GO(7000,8500);
		    			   s=i+1;
		    			   break;
		    		   }else if(i>3 && i<5){
		    			   migi();
		    			   s=i+1;
		    			   break;
		    		   }else if(i>4 && i<8){
		    			   GO(7000,8500);
		    			   s=i+1;
		    			   break;
		    		   }else{
		    			   STOP();
		    			   break;
		    		   }
		    	   }
		   } else if (right > BL) {
			   migi();
			   Wait(50);
		   } else if (left > BL){
			   hidari();
			   Wait(50);
		   }else {
			   GO(7000,8500);
		   }

		}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	slalom();

	return 0;
}

