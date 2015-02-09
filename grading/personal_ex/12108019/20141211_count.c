/*
 ============================================================================
 Name        : count.c
 Author      : Eto Ayaka
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int count100(int n)
{
	int i;
	for(i=0;i<10;i++){
		if(n<100){   //ここを0にするとエラー
			break;
		}else{
			n -= 100;
		}
	}
	return i;
}   //   return n/100;のみでも同じ動作

int count10(int n)
{
	int i;
	for(i=0;i<10;i++){
		if(n<10){
			break;
		}else{
			n -= 10;
		}
	}
	return i;
}

int main(void) {

	int x=987;
	int h;
	int d;

	h = count100(x);
	d = count10(x-100*h);

	printf("100*%d,10*%d\n", h,d);

	return EXIT_SUCCESS;
}
