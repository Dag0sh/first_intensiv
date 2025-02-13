#include <stdio.h>

int sum(int a, int b);
int raz(int a, int b);
int prz(int a, int b);
int del(int a, int b);

int main() {
  int a, b;
  if (scanf("%d %d", &a, &b) != 2) {
    printf("n/a");
    return (0);
  }
  printf("%d %d %d ", sum(a, b), raz(a, b), prz(a, b));
  if (b == 0) {
    printf("n/a");
  } else
    printf("%d", del(a, b));
}

int sum(int a, int b) { return (a + b); }

int raz(int a, int b) { return (a - b); }

int prz(int a, int b) { return (a * b); }

int del(int a, int b) { return (a / b); }
