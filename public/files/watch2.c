#include <stdio.h>

int main(void) 
{
	int c;
	char fname[100];
	FILE *inf;

	printf("file name? ");
	scanf("%s",fname);
	inf = fopen(fname,"r");
	while (1) {
		c=fgetc(inf);
		if (c==(-1)) {
			break;
		}
	fputc(c,stdout);
	}
	fclose(inf);
	return 0;
}
