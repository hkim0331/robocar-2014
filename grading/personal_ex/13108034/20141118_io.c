/*
 ============================================================================
 Name        : io.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void ex1(void){
	printf("学園祭いつ？");
	printf("11/12\nsat.\n12:00\nwith love.\n");
	printf("jan\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x=21;
	int y=2;
	printf("I am %d years old\n",having %d kids\n,x,y);
}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z=%d,%u,%o,%x\n",z,z,z,z);//%uはunsighned,%oは8進数,%xは１６進数//
	printf("z=%d,%u,%o,%x\n",y,y,y,y);
}

void ex4(void){
	char *name="masaki kataoka";
	printf("My name is %s\n",name);//文字列のときは %s を使う//
}

void ex5(void){
	int x;
	char name[256];

	printf("please input integer:");
	scanf("%d",&x);
	printf("あなたの名前はなあに？");
	scanf("%s",&name);
	printf("%さん、%dね\n",name,x);
}

void ex6(void){
	int m;

	printf("あなたいくつ？");
	scanf("%d",&m);
	printf("あなたは今年で %d 歳")

}



int main(void) {
	ex1();
	ex2();
	ex3();
	ex4();
	return 0;
}
