// ロボカーを 5 秒前進させる。
// プログラム的にはあまり良くない。
// 先週の授業を思い出して改良せよ。
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define stop1 1000  //一秒
#define round 1     //何周まわるのか
#define rou (round*4)  //実際に使う数値
#define manmos 10000  //前進モータの回転数
#define minmanmos 1000  //右回りのモータ回転数

void mae(int x, int y){

    const unsigned short MainCycle = 60;
    Init(MainCycle);

    Mtr_Run_lv(x, -x, 0, 0, 0, 0);
    Wait(y);

    }


stop_motor(int x){

    const unsigned short MainCycle = 60;
     Init(MainCycle);


   Mtr_Run_lv(0, 0, 0, 0, 0, 0);
   Wait(x);
}


right_turn(int x, int y){

    const unsigned short MainCycle = 60;
         Init(MainCycle);

         Mtr_Run_lv(x, 0, 0, 0, 0, 0);
           Wait(y);

}


int main(void)
{
    int i;

const unsigned short MainCycle = 60;
  Init(MainCycle);


for(i=0;i<rou;i++){

 mae(manmos,stop1*2+500);     //10000,2500
stop_motor(stop1);            //1000
right_turn(minmanmos,stop1);  //1000,1000
stop_motor(stop1);            //1000
}





  return 0;
}
