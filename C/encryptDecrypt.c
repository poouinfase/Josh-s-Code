#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// #include <stdlib.h>

#define KEY 1
#define swap(a, b)                                                             \
  do {                                                                         \
    (a) ^= (b);                                                                \
    (b) ^= (a);                                                                \
    (a) ^= (b);                                                                \
  } while (0)

// void revthisstring(char *strIn, int len) {
//   for (int i = 0; i < len / 2; i++)
//     swap(strIn[i], strIn[len - i - 1]);
// }
//
// char *numToBin(int s) {
//   char *out = (char *)calloc(32, sizeof(char));
//   int poin = 0;
//   while (s) {
//     out[poin] = ((s) & 1) ? '1' : '0';
//     s >>= 1;
//     poin++;
//   }
//   for (; poin % 8 != 0; poin++) {
//     out[poin] = '0';
//   }
//   revthisstring(out, poin);
//   out = (char *)realloc(out, poin * sizeof(char) + 1);
//   out[poin] = '\0';
//   return out;
// }
// long long int charToNum(char *s) {
//   long long int out = 0;
//   for (int i = 3; i >= 0; i--) {
//     out += s[i];
//     out <<= 16;
//   }
//   return out;
// }
double nthRoot(long long int A, int N) {
  // initially guessing a random number between
  // 0 and 9
  double xPre = rand() % 10;

  //  smaller eps, denotes more accuracy
  double eps = 1e-3;

  // initializing difference between two
  // roots by INT_MAX
  double delX = INT_MAX;

  //  xK denotes current value of x
  double xK;

  //  loop until we reach desired accuracy
  while (delX > eps) {
    //  calculating current value from previous
    // value by newton's method
    xK = ((N - 1.0) * xPre + (double)A / pow(xPre, N - 1)) / (double)N;
    delX = fabs(xK - xPre);
    xPre = xK;
  }

  return xK;
}
unsigned long long int encrypt(long int base, int exp) {
  if (base == 0)
    return 0;
  long long int t = 1;
  while (exp > 0) { // Simplifying multiplication by squaring itself
    if ((exp & 1) == 1)
      t = t * base;
    base = base * base;
    exp >>= 1;
  }
  return t;
}
long long int decrypt(long long int base, int exp) {
  int ex = exp;
  long double bs = base;
  int chk = 0;
  while (ex > 0) {
    if ((ex & 1) == 1) {
      chk++;
    }
    bs = sqrtl(bs);
    ex >>= 1;
  }
  printf("%Lf\n", bs);
  return bs;
}
union Strintonum {
  char s[4];
  long int num;
};
int charToNum(char *restrict s) {
  union Strintonum Bing;
  for (int i = 0; i < 4; i++)
    Bing.s[i] = s[i];
  return Bing.num;
}
void numToChar(int num, char *s) {
  union Strintonum Bing;
  Bing.num = num;
  for (int i = 0; i < 4; i++)
    s[i] = Bing.s[i];
}
#define siz 84
int main() {
  char iss[] = {'B', '\0', '\0', '\0'};
  char buff[4];
  printf("%.4s\n", iss);
  int n = charToNum(iss);
  printf("%d\n", n);
  numToChar(n, buff);
  printf("%.4s\n", buff);
  long long int temp_encr = encrypt(n, KEY);
  printf("%llu\n", temp_encr);
  long bingus = decrypt(temp_encr, KEY);
  printf("Hell %ld\n", bingus);
  return 0;
  char *s = (char *)malloc(siz * sizeof(char));
  for (int i = 0; i < siz; i++) {
    *(s + i) = '\0';
  }
  scanf_s("%s", s);
  // char buff[4];
  unsigned long long int encr[siz / 4];
  for (int i = 0; i < siz; i++) {
    if (i != 0 && i % 4 == 0) {
      encr[i / 4] = encrypt(charToNum(buff), KEY);
      if (encr[i / 4])
        printf("%llu\n", encr[i / 4]);
    }
    buff[i % 4] = *(s + i);
  }
  for (int i = 0; i < siz / 4; i += 4) {
    numToChar(decrypt(encr[i / 4], KEY), buff);
    printf("%.4s", buff);
  }
  free(s);
  return 0;
}
