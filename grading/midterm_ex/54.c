#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*絶対　全角スペースに注意しような*/

int left;
int right;


int step(mstt,mwat){ //mstt;モータまわすじかん,mwat;モータとめたあとまつじかん

	const unsigned short MainCycle = 60;
	Init(MainCycle);
	  Mtr_Run_lv(32760, -32760, 0, 0, 0, 0);  //32767で最大パワー！！！　光の翼が見えます。嘘です。
	  Wait(mstt);
	  Mtr_Run_lv( 0, 0, 0, 0, 0, 0);
	  Wait(mwat);
	return 0;
}

int buzz(vol , bt ,bwat){  //bt;ブザーならすじかん,bwat;ブザーとめたあとまつじかん
      BuzzerSet( 90 , vol );   // 近年の流行りはピッチ９０だと聞いている
	  BuzzerStart();
	  Wait(bt);
	  BuzzerStop();
	  Wait(bwat);
}

int turn(RM,LM,per){    //左右のモータの回転早さ?と持続時間を指定してください
	                  Mtr_Run_lv(RM, LM, 0, 0, 0, 0);
			       	  Wait(per);
			       	  Mtr_Run_lv( 0, 0, 0, 0, 0, 0);
			       	  Wait(0);
}



int main(void){

	const unsigned short MainCycle = 60;
	Init(MainCycle);

		for( ; ; ) {

		       // step(,);
		        left = ADRead(0);
                right = ADRead(1);

                	if(left>600){
                		LED(2);
                		Wait(200);
                		turn(32760,32760,50);  //	軌道修正 ~ 右　10k,10k　,persist = 100ms
                	}


                	if(right>600){
                		LED(1);
                		Wait(200);
                		turn(-32760,-32760,50);   //軌道修正  ~ 左　-10k, -10k
                	}


                	if(right > 600 && left > 600){
                		break;
                	}


                	else{
                          step(30,0);
                          buzz(0,30,0);
			       	  }

    LED(0);
		     }



		return 0;
}

