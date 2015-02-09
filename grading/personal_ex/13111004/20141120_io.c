/*
 ============================================================================
 Name        : io.c
 Author      : Shunpei Ariyoshi
 Version     :1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	int age=52;
	int gf=3;
	printf("I am %d years old.\nI have %d kids.\n ", age, gf);

}

void ex2(void){

	printf("123\t3456\tapple\t1\t2\n");
	printf("a\tb\tc\td\te\te\t\n");
	printf("spring\tsummer\tautum\twinter\n");

}

void ex3(void){

	int z=-1;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);

}

void ex4(void){

	char *name="shunpei ariyoshi";
	printf("my name is %s.\n",name);

}

void ex5(void){
	int x;

	printf("整数を入力してね:");
	scanf("%d",&x);
	printf("your input i s%d\n",x);

}
int main(void) {

	ex5();
	return 0;
}
