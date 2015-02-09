/*
 ============================================================================
 Name        : io.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
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
    int y=3;
	printf("i am %d years old\n, have %d kids\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;

	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="hiroki goto";
	printf("my name is %s.\n",name);
}

void ex5(void){
	int x;
char name[256];

	printf("整数を入力:");
	scanf("%d",&x);
	printf("名前は何？:");
	scanf("%s",name);
	printf("%sさんの入力は%dです。\n",name,x);
}

void ex6(void){
int x;
char name[256];

printf("名前は何？：");
scanf("%s",name);
printf("生まれた年は？:");
scanf("%d",&x);


}
int main() {
	ex6();
	return 0;
}
