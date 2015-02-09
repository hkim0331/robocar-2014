/*
 ============================================================================
 Name        : io.c
 Author      : Yuma Omori
 Version     :1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void ex1(void){
	printf("11/22\nSat.\n12:00\n");
printf("jan\tfeb\n");
printf("111111111111111111111111111111111111111111111111111111\t2\t\n");
}

void ex2(void){

int x=20;
int y=0;
printf("I am %d years old,have %d kids\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z=%d,%u,%o,%x\n",z,z,z,z);
printf("y=%d,%u,%o,%x\n",y,y,y,y);
}

void ex4(void){
	char *name="yuma omori";
	printf("my name is %s\n",name);
}


void ex5(){
	int x;
	char name[256];
	printf("整数を入力してください:");
	scanf("%d",&x);
	printf("名前を入力してください:");
	scanf("%s",name);
	printf("%sさん、%dですね\n",name,x);
printf("input is %d\n",x);
}
void ex6(void){
	int x;
	printf("何年生まれですか？:");
	scanf("%d",&x);
	printf("%d才ですね\n",2014-x);
}

int main(void) {
ex6();

return 0;
}
