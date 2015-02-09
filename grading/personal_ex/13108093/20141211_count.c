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

int count100(int n)

{
	int i;
	for(i = 0;i<10;i++){
		if(n>=100){
			n -= 100;
		}
		else {
			break;
		}
	}
	return i;

}

int count10(int n)
{
	int i;
	for(i = 0;i<10;i++){
		if(n>=10){
			n -= 10;
		}
		else {
			break;
		}
	}
	return i;
	return 0;
}
int main(void) {
	int x=630;
	int h;
	int d;

	h = count100(x);
	d = count10(x-100*h);          //fix//

	printf("100 * %d, 10 * %d\n",h,d);

	return EXIT_SUCCESS;
}
