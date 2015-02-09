/*
 ============================================================================
 Name        : io.c
 Author      : isikawa hiroki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
printf("学園祭の開催日時はいつ");
printf("\nmaiad\n");
printf("3435+324543+34523/4363\n");}

void ex2(void){
	int x=18;
	int y=0;
	printf("i am %d years oided  i have %d years kids \n",x,y);
}

void ex3(void)
{int z=-1;
int y=15;
printf ("z=%d,%u,%o,%x\n",z,z,z,z);
printf ("z=%dは十進数%u,は符号なし%o,八進数%x１６進数\n",y,y,y,y);
}

void ex4(void)
{char *name="isikawa hiroki";
printf("my neme is %s\n",name);


}

void ex5(void)
{int a;
char name[256];
printf("整数を入力したください");
scanf("%d",&a);
printf("名前を入力したください");
scanf("%s",name);
printf("入力した数は %dです",a);
printf("入力した名前は %sです",name);}

void ex5(void){
	printf("生まれた年を西暦で入れてください");
	scanf("%d",&a);
	printf("貴方は%d歳ですね",2014-a);
}


int main(void){
ex5();
return 0;}
