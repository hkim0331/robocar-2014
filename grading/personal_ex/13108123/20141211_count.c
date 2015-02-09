/*
 ============================================================================
 Name        : count.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int count(int m,int n)
{
	int i;

		for(i=0;i<10;i++){
			if (n<m){
				break;
			} else {
				n-=m;

			}
		}
	return i;

}
/*int count100(int n)
{
	int i;

	for(i=0;i<10;i++){
		if (n<10){
			break;
		} else {
			n -=100;

		}
	}
return i;
}

int count10(int n)
{
	int i;

	for(i=0;i<10;i++){
		if (n<0){
			break;
		} else {
			n -=10;

		}
	}
return i;

}
*/
int main(void) {

	int x=987;
	int h;
	int d;

	h=count(100,x);
	d=count(10,x-100*h);

	printf("100*%d, 10*%d\n",h,d);



	return EXIT_SUCCESS;
}
