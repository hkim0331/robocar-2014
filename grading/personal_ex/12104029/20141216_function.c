/*
 ============================================================================
 Name        : function.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int smaller(int x, int y)
{
	if(x<y){
		return x;
	} else{
		return y;
	}
}

int main(void) {
	int a = 10;
	int b = 20;

	printf("smaller is %d\n",smaller(a,b));
	return 0;
}
