#include <stdio.h>
int main(void)
{
  char c;
  short s;
  int i;
  long l;

  printf("%lu,%lu,%lu,%lu\n",sizeof(c),sizeof(s),sizeof(i),sizeof(l));

  float f;
  double d;
  printf("%lu,%lu\n",sizeof(f),sizeof(d));

  return 0;
}
