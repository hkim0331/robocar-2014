#include <stdio.h>
#include <stdlib.h>

int mk_array(int n)
{
    int ary[n];
    printf("sizeof ary=%li, sizeof ary[0]=%li\n",sizeof(ary),sizeof(ary[0]));
    return 1;
}

int main(int argc, char *argv[])
{
    int i;
    for (i=1; i<argc; i++) {
        mk_array(atoi(argv[i]));
    }
    return 0;
}

