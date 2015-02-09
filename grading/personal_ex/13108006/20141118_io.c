/*
 ============================================================================
 Name        : io.c
 Author      : Takakki Arimoto
 Version     :1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat\n12:00\nwith love\n");
	printf("Jane\tFeb\tMar\tApl\tMay\n");
	printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x = 20;
	int y = 0;
	printf("I am %d years old, have %d kids.\n",x,y);
}

void ex3(void){
	int z = -1, y = 15;

	z = z+1;

	printf("z = %d, %u, %o, %x\n",z,z,z,z);
	printf("y = %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name = "Takaaki Arimoto";
	printf("My name is %s.\n",name);
}

void ex5(void){
	int x;
	char name[256];

	printf("Please input integer:");
	scanf("%d",&x);
	printf("Please input your name:");
	scanf("%s",name);
	printf("Your name is %s.\tInput is %d.\n",name,x);
}

void ex6(void){
	int x;

	printf("Please input your birth year:");
	scanf("%d",&x);
	printf("You are %d years old.")
}

int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
	return 0;
}
