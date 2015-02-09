/*
 ============================================================================
 Name        : io.c
 Author      : Aratani Yoshiya
 Version     :1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("学園祭はいつ？");
	printf("11/22\nsat\n12:00\nwith love\n");
	printf("1\t23\tr\tie\t543\n");
}
void ex2(void)
{
	int x=21;
	printf("I am %d years old,having %d kids.\n",x,0);
}
void ex3(void)
{
	short z=-1;
	int y=15;

	printf("z = %d, %u, %o, %x\n",z,z+1,z,z);//%d int %u unsigned %o 8 %x 16
	printf("y = %d, %u, %o, %x\n",y,y,y,y);
}
void ex4(void)
{
	char *name="aratani yoshiya";
	printf("my name is %s.\n",name);
}
void ex5(void)
{
	int x;
	char name[256];
	printf("please input integer:");
	scanf("%d",&x);
	printf("名前はなーに？");
	scanf("%s",name);
	printf("%sさん、%dね",name,x);
}
void ex6(void);
{
	int x;
	printf("生まれた年の西暦は？:");
	scanf("%d",&x);
	printf("あなたの生まれた年は%d");

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
