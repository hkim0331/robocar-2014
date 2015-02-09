/*
 ============================================================================
 Name        : io.c
 Author      : yuya ishida
 Version     :1.0
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("学園祭はいつ？");
	printf("11/22\nSat\n12:00\nwith love\n");
	printf("Jan\nFeb\nMar\nApl\nMay\n");
	printf("123\n456\n789\n");
}
void ex2(void){
	int x=20;
	int kids=3;
	printf("I am %d years old,have %d kids.\n",x,kids);
}
void ex3(void){
	int z=-1;
	int y=15;
	printf("z =   %d   %u   %o   %x\n",z,z,z,z);
	printf("y =   %d   %u   %o   %x\n",y,y,y,y);
}
void ex4(void){
	char *name="yuya ishida";
	printf("my name is %s\n",name);
}
void ex5(void){
	int x;
	char name[256];
	printf("please input integer:");
	scanf("%d",&x);
	printf("please input your name:");
scanf("%s",name);
	printf("%s's input integer is %d\n",name,x);

}
void ex6(void){
	int x;
printf("あなたが生まれた年を西暦で入力してください。");
scanf("%d",&x);
printf("あなたの年齢は%d歳です。\n",x);
}
int main(void) {
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	return EXIT_SUCCESS;
}
