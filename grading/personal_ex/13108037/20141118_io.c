/*
 ============================================================================
 Name        : io.c
 Author      : Shoichi Kamoda
 Version     : 1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("a\ti\tu\n");
	printf("1\t23\t456");
}
void ex2(void){
	int x=52;
	int y=3;
	printf("I am %d years old, have %d kids. \n",x,y);

}
void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}
void ex4(void){
	char *name="shoichi kamoda.";
	printf("My name is %s\n",name);
}
void ex5(void){
	int x;
	char name[256];
	printf("整数を入力してください。:");
	scanf("%d",&x);
	printf("名前はなに？");
	scanf("%s",name);
	printf("%s の入力は %d です。\n",name,x);
}
void ex6(void){
	int a,b;
	char name[256];

	printf("あなたの名前は？\n");
	scanf("%s",name);
	printf("あなたの生まれた西暦は？\n");
	scanf("%d",&a);


}






int main(void)
{
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
	return 0;
}
