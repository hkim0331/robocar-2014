/* ファイル名は sample.c */
#include <stdio.h>
int add1(int n) {
	return n+1;
	printf("楽天優勝おめでとう\n");
}

int main(void) {
	int x;
	int y;

	x = 1;
	y = add1(x);
	printf("x=%i, y=%i\n", x, y);
	return 0;
}

