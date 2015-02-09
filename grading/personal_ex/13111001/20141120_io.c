/*
 ============================================================================
 Name        : io.c
 Author      : Aoki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void) {

	int age=20;
	int gf=3;

	printf("I am %d years old,\n I have %d girl friend.", age, gf);


}

void ex2(void){

	printf("123\t3456\tapple\t1\t2\n");
	printf("a\tb\tc\t\n");

}

void ex3(void){

	int z=-1;
	printf("z=%d, %u, %o, %x\n",z,z,z,z);

}

void ex4(void){

	char *name="mirakurumaiku";
	printf("my name is %s\n", name);

}

void ex5(void){

	int n;
	scanf("%d", &n);
	printf("%d", n);

}

void ex6(void){

	char name[255];

	printf("あなたの名前は何ですか？");
	scanf("%s", name);
	printf("%sさんおはよう？！！", name);


}
int main(void){

	ex6();

while(1);
	return 0;

}
