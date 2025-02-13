#include <math.h>
#include <stdio.h>

float need(float x);

int main() {
  float x;
  if (scanf("%f", &x) != 1) {
    printf("n/a");
    return (0);
  }
  printf("%.1f", need(x));
}

float need(float x) {
  float m;
  m = (7e-3) * pow(x, 4) +
      ((22.8 * pow(x, 1.0 / 3.0) - 1e3) * x + 3) / (x * x / 2) -
      x * pow(10 + x, 2 / x) - 1.01;
  return m;
}
