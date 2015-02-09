/*
 ============================================================================
 Name        : io.c
 Author      : Ryoya Sugawara
 Version     : 1.0
 Copyright   : All rights reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat\n12:00\n");
	printf("jan\tfeb\tmar\tmay\n");
	printf("1\t23\t456\t7890\n");
}
void ex2(void){
	int x=19;
	int y=0;
	printf("I am %d years old ,have %d kids \n",x,y);
}
void ex3(void){
	short z=-1;
	int y=15;

	printf("z=%d,%u,%o,%x\n",z,z,z,z);   //%u10進数、%o８進数、%x16進数
	printf("z=%d,%u,%o,%x\n",y,y,y,y);
}
void ex4(void){
	char *name="Ryoya Sugawara";
	printf("my name is %s\n",name);  //%s 文字列
}
void ex5(void){
	int x;
	char name[256];
	printf("整数を入力してください");
	scanf("%d",&x);
	printf("名前を入力してください");
	scanf("%s",name);
	printf("入力は %dです。\n",x);
	printf("名前は%sです",name);
}
void ex6(void){
	int x;
	printf("あなたの西暦は?");
	scanf("%d",&x);
	printf("あなたは%d歳ですね",2014-x);

}


int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	ex6();
	return 0;

}
