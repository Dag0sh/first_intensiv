#include <math.h>
#include <stdio.h>

int main() {
  float a, b;
  if (scanf("%f %f", &a, &b) != 2) {
    printf("n/a");
    return (0);
  }
  if (pow(a, 2) + pow(b, 2) < 25) {
    printf("GOTCHA");
  } else
    printf("MISS");
  return (0);
}
