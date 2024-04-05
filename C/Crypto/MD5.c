// MD5

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *buff;
  int len;
} data;

int paddingStep1(int len);
void clear();
data Data(int len, data *cpy);
void Dat(data *cpy);
data input();

void clear() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

data Data(int len, data *cpy) {
  data encr = {.len = paddingStep1(len)};
  encr.buff = (char *)malloc(encr.len);

  for (int i = 0; i < encr.len; i++) {
    encr.buff[i] = 0;
  }
  encr.buff[len] = 1;

  return encr;
}
void Dat(data *cpy) { free(cpy->buff); }

int paddingStep1(int len) {
  if ((len % 128) == 112)
    return len + 16;
  if ((len % 128) < 112) {
    len += 112 - (len % 128);
    return len + 16;
  }
  if ((len % 128) > 112) {
    len += 128 - (len % 128) + 112;
    return len + 16;
  }
  return -1;
}

data input() {
  data encr;
  int len;
  scanf("%d", &len);
  clear();
  encr = Data(len, NULL);
  fread(encr.buff, 1, len, stdin);
  printf("\n%d\n", encr.len * 8);
  return encr;
}

void printData(data encr) {
  // fprintf(stderr, "%.*s\n", encr.len, encr.buff);
  for (int i = 0; i < encr.len; i++)
    putchar(encr.buff[i]);
}

int main() {
  data Encr = input();
  printData(Encr);
}
