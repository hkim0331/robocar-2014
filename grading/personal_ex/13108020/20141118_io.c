/*
 ============================================================================
 Name        : io.c
 Author      : Uchida Hironori
 Version     :1.0
 Copyright   : All Right Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void ex1(void){
	printf("11月22日\nSat.\n12:00\nwith love.\n");
	printf("jun\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t789\n");
}

void ex2(void){
	int x=20;
	int y=3;
	printf("i am %dyears old, have %d kidds.\n",x,y);

}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z=%d,%u,%o,%x\n",z,z,z,z);
	printf("y=%d,%u,%o,%x\n",y,y,y,y);

}

void ex4(void){
	char *name="Ucida Hironori";
	printf("My name is %s.\n",name);
}

void ex5(void){
	int x;
char name[256];

	printf("整数を入力してください:");
	scanf("%d",&x);
	printf("名前はなあに？");
	scanf("%s",name);
	printf("入力は %d\nですね。",x);
	printf("%sさん、%dね。",name,x);
}

void ex6(void){
int x;
char name;
scanf("%d",x);
scanf("%s",name);
printf("%sさん、%d生まれですね。,")

}
int main(void) {
ex1();
ex2();
ex3();
ex4();
ex5();
return 0;

}
