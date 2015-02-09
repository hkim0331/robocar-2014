/*
 ============================================================================
 Name        : io.c
 Author      : ono kouta
 Version     :1.0.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\nwith love.\n");
	printf("jun\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t789t");

}
void ex2(void){
	int x=20;
	int y=0;
	printf("I am %d years old,have %d kids\n",x,y);
}
void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z+1,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}
void ex4(void){
char *name="kohta ono";
printf("My name is %s. \n",name);
}
void ex5(void){
int x;
char name[256];
printf("整数を入力してね:");
scanf("%d",&x);
printf("名前はなーに？\n");
scanf("%s",name);
printf("%sさん、%dね\n",name,x);
}
void ex6(){
int x,y;
char name[256];
printf("生まれた西暦は？:");
scanf("%d",&x);
printf("名前は？\n");
scanf("%s",name);
y=2014-x;
printf("%sさん、%d歳ね\n",name,y);
}
int main(void) {
//ex1();
//ex2();
//ex3();
//ex4();
//ex5();
ex6();
	return 0;
}

