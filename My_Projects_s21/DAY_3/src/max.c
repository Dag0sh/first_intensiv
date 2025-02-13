#include <stdio.h>

int max(int a, int b);

int main() {
  int a, b;
  if (scanf("%d %d", &a, &b) != 2) {
    printf("n/a");
    return (0);
  }
  if (a == b) {
    printf("числа равны");
    return (0);
  }
  printf("%d", max(a, b));
}

int max(int a, int b) {
  int m = a;
  if (b > a) {
    m = b;
  }
  return m;
}
