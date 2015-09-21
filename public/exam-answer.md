# 情報処理応用（ロボカー）期末試験　解答例

````c
#include <stdio.h>

// 1 --------------------
int rev2(int n)
{
  return (n % 10) * 10 + n/10;
}

// 2 --------------------
int a2i(void)
{
  int a[] = {1, 5, 4, 0, 3, 7, -1};
  int i;
  int ret = 0;

  for (i=0; a[i] != -1; i++) {
    ret = ret * 10 + a[i];
  }
  return ret;
}

// 3 --------------------
int dp(int n)
{
  int sum = 0;

  while (n>0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

// 4 --------------------
int max2(int x, int y)
{
  if (x>y) {
    return x;
  } else {
    return y;
  }
}

// 5 --------------------
int max4(int a, int b, int c, int d)
{
  return max2(max2(a, b), max2(c, d));
}

// 6 --------------------
int max(int a[], int n)
{
  int i;
  int m = -1;

  for(i=0; i<n; i++) {
    m = max2(m, a[i]);
  }
  return m;
}

// 7 --------------------
int D(int a, int b, int c)
{
  return b * b- 4 * a * c >= 0;
}

// 8 --------------------
int power2(int n)
{
  int i;
  int ret = 1;

  for (i=0; i<n; i++) {
    ret *= 2;
  }
  return ret;
}

// 9 --------------------
int factorial(int n)
{
  int i;
  int ret = 1;

  for (i = n; i > 0; i--) {
    ret *= i;
  }
  return ret;
}

// 10 --------------------
int count(void)
{
  int n;
  int ret = 0;

  for (n=1; n<= 12; n++) {
    if (power2(n) > factorial(n)) {
      ret++;
    }
  }
  return ret;
}

// 以下、火曜日追加分
// --------------------
int f_is_over(int m)
{
  int i;

  for (i=1; ;i++) {
    if (factorial(i) > m) {
      break;
    }
  }
  return i;
}

// --------------------
int dsum(int n)
{
  int i;
  int sum = 0;
  for (i=1;i<n;i++) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum;
}

// --------------------
void perfects(int n)
{
  int i;

  for(i=1; i<=n; i++) {
    if (dsum(i) == i) {
      printf("%d ",i);
    }
  }
  printf("\n");
}

// --------------------
int same_digits(int n)
{
  int digit;

  digit= n % 10;
  while (1) {
    if (n == 0) {
      return 1;
    } else if (n % 10 == digit) {
      n /=10 ;
    } else {
      return 0;
    }
  }
}
// --------------------

int main(void)
{
  int a[] = {73, 26, 38, 43, 67, 91, 14};

  printf(" 1, %d\n", rev2(48));
  printf(" 2, %d\n", a2i());
  printf(" 3, %d\n", dp(123456789));
  printf(" 4, %d\n", max2(45, 54));
  printf(" 5, %d\n", max4(1,2,4,5));
  printf(" 6, %d\n", max(a, 7));
  printf(" 7, %d\n", D(1,2,3));
  printf(" 8, %d\n", power2(10));
  printf(" 9, %d\n", factorial(6));
  printf("10, %d\n", count());

  printf("factorialof %d > 2000000\n", f_is_over(2000000));

  printf("dsum(28): %d\n", dsum(28));
  perfects(1000);

  printf("same digits? %d\n", same_digits(999999));
  printf("same digits? %d\n", same_digits(998999));

  return 0;
}
````

以上。
