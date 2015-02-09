#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void ex1(){

	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(5000);
		Mtr_Run_lv(0,0,0,0,0,0);

}
void ex2(){

	Wait(2000);
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(5000);
		Mtr_Run_lv(0,0,0,0,0,0);
}
void ex3(){

	Wait(1000);
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(100);
		Mtr_Run_lv(0,0,0,0,0,0);


}
void ex4(){

	  Wait(1000);
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(420);
		Mtr_Run_lv(0,0,0,0,0,0);
}
void ex5(){

	Wait(1000);
		Mtr_Run_lv(-10000,10000,0,0,0,0);
		Wait(300);
		Mtr_Run_lv(0,0,0,0,0,0);

}
void ex6(){

	Wait(1000);
			Mtr_Run_lv(-10000,-10000,0,0,0,0);
			Wait(400);
			Mtr_Run_lv(0,0,0,0,0,0);
}
void ex7(){

	 Wait(1000);
			Mtr_Run_lv(10000,10000,0,0,0,0);
			Wait(1360);
			Mtr_Run_lv(0,0,0,0,0,0);
}
void ex8(){

	Wait(1000);
			Mtr_Run_lv(20000,-20000,0,0,0,0);
			Wait(240);
			Mtr_Run_lv(0,0,0,0,0,0);

}

void ex9(){

	Wait(1000);
Mtr_Run_lv(5000,-5000,0,0,0,0);
Wait(960);
Mtr_Run_lv(0,0,0,0,0,0);

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	 Wait(1000);
			Mtr_Run_lv(10000,-10000,0,0,0,0);
			Wait(1260);
			Mtr_Run_lv(0,0,0,0,0,0);

			Mtr_Run_lv(-10000,-10000,0,0,0,0);
						Wait(400);
						Mtr_Run_lv(0,0,0,0,0,0);


	 Wait(1000);
			Mtr_Run_lv(10000,-10000,0,0,0,0);
			Wait(1260);
			Mtr_Run_lv(0,0,0,0,0,0);

			Mtr_Run_lv(-10000,-10000,0,0,0,0);
						Wait(400);
						Mtr_Run_lv(0,0,0,0,0,0);



	 Wait(1000);
	        Mtr_Run_lv(10000,-10000,0,0,0,0);
			Wait(1260);
			Mtr_Run_lv(0,0,0,0,0,0);

			Mtr_Run_lv(-10000,-10000,0,0,0,0);
						Wait(400);
						Mtr_Run_lv(0,0,0,0,0,0);



     Wait(1000);
     		Mtr_Run_lv(10000,-10000,0,0,0,0);
			Wait(1260);
			Mtr_Run_lv(0,0,0,0,0,0);

			Mtr_Run_lv(-10000,-10000,0,0,0,0);
						Wait(400);
				     	Mtr_Run_lv(0,0,0,0,0,0);


			return 0;
}


