/*
 ============================================================================
 Name        : io.c
 Author      : Oka Toshiomi
 Version     : 1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("jan\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x=19;
	int y=0;
	printf("I am %d yeas old, have %d kids\n",x,y);
}

void ex3(){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z+1,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(){
	char *name="Oka Toshiomi";
	printf("My name is %s.\n",name);
}

void ex5(){
	int x;
	char name[256];
	printf("整数を入力してね:");
	scanf("%d",&x);
	printf("名前はなーに?");
	scanf("%s",name);
	printf("%sさんの入力は %dね\n",name,x);
}

void ex6(void){
	int x;
	printf("あなたは西暦何年生まれですか?\n");
	scanf("%d",&x);
	printf("あなたの年は%d",2014-x);
}
int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	return 0;
}
