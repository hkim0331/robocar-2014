/*
 ============================================================================
 Name        : io.c+
 Author      : Kotaro Tokitsu
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1 (void){
	int age=20;
	int gf=3;
	printf("I am %d years old.\n I have %d  kids.\n ホークス優勝おめでとう！\n",age,gf);
}

void ex2 (void){
	printf("123\t 3456\t apple\t 1\t 2\n");
	printf("a\t b\t c\t d\t e\t\n");
	printf("spring\t summer\t autumn\t winter\t\n");
}

void ex3 (void){
	int z=-1;
	printf("z= %d, %u, %o, %x\n",z,z,z,z); //%dは整数//
}

void ex4 (void){
	char *name="kotaro tokitsu";
	printf("my name is %s.\n",name); //%sは文字列//
}

void ex5 (void){
    int x;

    printf("整数を入力してね");
    scanf("%d",&x);
    printf("your input is %d.\n",x);
}

void ex6 (void){
	char name[255];

	printf("あなたの名前は何ですか==>");
	scanf("%s",name);
	printf("%sさん、おはようございます。\n",name);

}

int main(void) {
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();
    ex6();
	return 0;
}
