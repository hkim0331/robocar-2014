/*
 ============================================================================
 Name        : io.c
 Author      : Oka Chiharu
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("jan\tfub\tmay\n");
	printf("1\t234\t5677\t");
}

void ex2(void){
	int x=20;
	int y=3;
	printf("i am %d years old, have %d kids.\n", x,y);

}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z=%d, %u, %o, %x\n",z,z,z,z); /*d=10進数 u=unsigned o=8進数 x=16進数*/
	printf("y=%d, %u ,%o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="chiharu oka";
	printf("my name is %s\n", name);

}

void ex5(void){
	int x;
	char name[256];
	printf("整数を入力してください\n");
	scanf("%d", &x);
	printf("名前を入力してください\n");
	scanf("%s",name);
	printf("整数は%d\n名前は%s\n", x,name);

}

int main(void) {
   ex1();
   ex2();
   ex3();
   ex4();
   ex5();

   return 0;

}
