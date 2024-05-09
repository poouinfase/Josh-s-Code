#include "stdio.h"
#include <float.h>  /* floating-point specifications */
#include <limits.h> /* integer specifications */

extern int printf(const char *format, ...);

/* Look at range limits of certain types */
int main(void) {
  long double a;
  double b;
  float c;
  // printf("%llu %llu %llu", sizeof(a), sizeof(b), sizeof(c));
  printf("Integer range:\t%d\t%d\n", INT_MIN, INT_MAX);
  printf("Long range:\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
  printf("Float range:\t%e\t%e\n", FLT_MIN, FLT_MAX);
  printf("Double range:\t%e\t%e\n", DBL_MIN, DBL_MAX);
  printf("Long double range:\t%e\t%e\n", LDBL_MIN, LDBL_MAX);
  printf("Float-Double epsilon:\t%e\t%e\n", FLT_EPSILON, DBL_EPSILON);
}
