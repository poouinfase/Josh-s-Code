#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define zero ((int)'0')
#define swap(a, b)                                                             \
  do {                                                                         \
    (a) ^= (b);                                                                \
    (b) ^= (a);                                                                \
    (a) ^= (b);                                                                \
  } while (0)

char *numToBin(int s);
void revthisstring(char *in, int len);
void printabl(char *bin, char *strin) {
  int len = strlen(bin);
  for (int i = 0; i < len; i++) {
    if (i % 8 == 0) {
      printf_s("\n%d %c = %s: ", i / 8 + 1, *(strin), numToBin((int)(*strin)));
      strin++;
    }
    putc(*bin++, stdout);
  }
  putc('\n', stdout);
}

int stringtoint(char *s) {
  int out = 0;
  int len = strlen(s);
  for (int i = 0; i < len; i++)
    out = out * 10 + (int)(*(s + i) - zero);
  return out;
};
char *numToBin(int s) {
  char *out = (char *)calloc(32, sizeof(char));
  int poin = 0;
  while (s) {
    out[poin] = ((s) & 1) ? '1' : '0';
    s >>= 1;
    poin++;
  }
  for (; poin % 8 != 0; poin++) {
    out[poin] = '0';
  }
  revthisstring(out, poin);
  out = (char *)realloc(out, poin * sizeof(char) + 1);
  out[poin] = '\0';
  return out;
}
void revthisstring(char *strIn, int len) {
  for (int i = 0; i < len / 2; i++)
    swap(strIn[i], strIn[len - i - 1]);
}
int main(int argc, char **argv) {
  if (argc != 4) {
    printf_s("%d\n", argc);
    for (int i = 0; i < argc; i++) {
      printf_s("\n%d: %s\n", i, *(argv + i));
    }
    return 0xE1212012;
  }
  char *bin = numToBin(stringtoint(*(argv + 2)));
  printf_s("%s\n", *(argv + 1)); // Progname
  printf_s("%s\n", *(argv + 2)); // StringInNum
  printf_s("%s\n", *(argv + 3)); // String
  printf("%s\n", bin);
  printabl(bin, *(argv + 3));
  revthisstring(*(argv + 3), strlen(*(argv + 3)));
  printabl(bin, *(argv + 3));
  free(bin);
  return 0;
}
