/*
 ============================================================================
 Name        : io.c
 Author      : Hiroki Kishida
 Version     :1.0
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
	printf("I am %d years old,have %d kids. \n",x,y);


}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z,z,z); //10進数　符号なし　8進数　16進数
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="hiroki kishida";
	printf("my name is %s.\n", name);
}

void ex5(void){
	int x;
	char name[256];

	printf("please input integer:"); //整数を入力してね
	scanf("%d", &x);
	printf("名前はなに？");
	scanf("%s",name);
	printf("input is %d\n" ,x);//あなたの入力は%dね
}



void ex6(void)
    int x;

    printf("何年生まれ？");
    scanf


int main(void) {
	//ex1();
    //ex2();
    //ex3();
   // ex4();
    //ex5();
	ex6();











	return 0;
}
