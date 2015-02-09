/*
 ============================================================================
 Name        : io.c
 Author      :Hikaru Kaishakuji
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
    printf("1\t23\t456\t7890\t");
}

void ex2(void){
int x=300;
int y=3;
printf("I am %d years old, have %d kids.\n",x,y);

}

void ex3(void){
	int z=-1;
	int y=15;

	printf("z = %d,%u,%o,%x\n",z,z+1,z,z);
	printf("y = %d,%u,%o,%x\n",y,y,y,y);
}

void ex4(void){
	char *name="hikaru kaishakuji";
	printf("my name is %s\n",name);

}

void ex5(void){
	int x;
	char name[256];

	printf("input integer");/*integer=整数*/
	scanf("%d",&x);
	printf("What your name?");
    scanf("%s",name);
    printf("your name is %s,and %d",name,x);
}

void ex6(void){
	int x;
	printf("西暦何年生まれですか？\n");
	scanf("%d",&x);
	printf("あなたの年齢は%d歳ですね\n",2014-x);

}
int main(void) {
	ex6();
    return 0;
}
