/*
 ============================================================================
 Name        : io.c
 Author      : sakaguchidaiki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love\n");
	printf("jan\tfeb\tmar\tape\tmay\n");
	printf("1\t23\t456\t7890\n");
}
void ex2(void){
	int x=20;
	int y=3;
	printf("i am %d years old,have %d kids.\n",x,y);
}
void ex3(void){
	int z=-1;
	int y=15;

	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}
void ex4(void){
	char *name="sakaguchi daiki.";
	printf("my name is %s\n",name);
}
void ex5(void){
	int x;
	char name[256];

	printf("整数を入力してください。");
	scanf("%d",&x);
	printf("名前はなに?");
	scanf("%s",name);
	printf("%sさん、入力は%dです。\n",name,x);
}
int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
	return 0;
}
