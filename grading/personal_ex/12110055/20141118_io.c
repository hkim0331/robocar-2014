/*
 ============================================================================
 Name        : io.c
 Author      : shinya bekki
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void) {
	printf("11/22\nsat.\n12:00\n");
	printf("jan\tfab\t");
	printf("1\t23\t345\t");
}
void ex2(void) {
	int x=21;
	int y=3;
	printf("i am %d old, have %d kid\n",x,y);

}
void ex3(void){
	int z=1;
	int y=23;
	printf("z= %d, %u, %o, %x",z,z,z,z);
	printf("y= %d, %u, %o, %x",y,y,y,y);
}
void ex4(void){
	char *name="shinya bekki";
	printf("my name is %s.\n",name);
}
void ex5(void){
	int x;
	char name[256];
	printf("整数を入力して");
	scanf("%d,"&x);
	printf("名前はなーに");
	scanf("%s",name);
	printf("%sさん、%dね\n",name,x);
}









int main(void) {
















	return 0;
}
