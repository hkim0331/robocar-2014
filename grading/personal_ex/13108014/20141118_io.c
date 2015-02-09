/*
 ============================================================================
 Name        : io.c
 Author      : Akihiro Ito
 Version     : 1.0
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
	int x=20;
	int y=3;
	printf("I am %d years old, have %d kids.\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u %o, %x\n",z,z,z,z);//%d:10進数,%u:unsigned,%o:8進数,%x:16進数
	printf("y= %d, %u %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="Akihiro Ito";
	printf("My name is %s.\n",name);
}

void ex5(void){
	int x;
	char name[256];

	printf("Please input integer:");
	scanf("%d",&x);
	printf("What is your name?:");
	scanf("%s",name);
	printf("input is %d.\tYour name is %s.\n",x,name);
}

void ex6(void){
	int x;
	char name[256];

	printf("お名前は?:");
	scanf("%s",&name);
	printf("年齢は?::");
	scanf("%d",x);
	printf("",x,name);
}

int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
	return 0;
}
