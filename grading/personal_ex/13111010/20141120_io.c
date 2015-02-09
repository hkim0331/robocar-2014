/*
 ============================================================================
 Name        : io.c
 Author      : Junji Oba
 Version     : 1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)
{
	int age=21;
	int gf=530000;
	printf("I am %d years old.\nI have %d girl friends.\n", age, gf);
}

void ex2(void)
{
	printf("123\t3456\tapple\t2\n");
	printf("a\tb\tc\td\te\t\n");
	printf("spring\tsummer\tautum\twinter\n");
}

void ex3(void)
{
	int z=-1;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
}

void ex4(void)
{
	char *name="Junji Oba";
	printf("I'm %s.\n",name);
}

void ex5(void){
	int x;

	printf("整数を入力してね");
	scanf("%d",&x);
	printf("your input is %d.\n",x);

}

void ex6(void){
	char name[255];

	printf("あなたの名前はなんですか==>");
	scanf("%s", name);
	printf("%sさん、おはようございます。\n");

}

int main(void) {

	ex1();
	ex2();
	ex3();
	ex4();

	ex6();
	return EXIT_SUCCESS;
}
