#include <stdio.h>
#include <stdlib.h>

int count100(int x){
	return x/100;
}
int count10(int x){
	return (x-100*(x/100))/10;
}

int main(void) {
	int x=689;
	int h;
	int d;

	h = count100(x);
	d = count10(x);

	printf("100 * %d, 10 * %d\n",h,d);

	return 0;
}
