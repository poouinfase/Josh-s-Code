#include <conio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUFFER 1000

#define CSI(A)                                                                 \
  do {                                                                         \
    printf("\e[" A);                                                           \
  } while (0)

#define COMMAND 0
#define NORM 1
#define SELECT 2

struct state {
  int poinAtEnd;
  char buff[MAX_BUFFER];
  unsigned char currChar;
  uint8_t Mode;
  int Quit_Flag;
};
void normKeymove(struct state *opBuff);

void commMode(struct state *opBuff) {
  switch (opBuff->currChar) {

  case ':':
    CSI("s");
    CSI("42;1H");
    char s[51];
    int n = read(0, s, 50);
    s[n] = 0;
    if (*s == 'q')
      opBuff->Quit_Flag = 0;
    CSI("u");
    break;

  case 'i':
    opBuff->Mode = NORM;
    break;

  case 224:
    normKeymove(opBuff);
  default:
    break;
  }
}

void normKeymove(struct state *opBuff) {
  char i = _getch();
  switch (i) {
  case 'H':
    i = 'A';
    break;
  case 'K':
    i = 'D';
    opBuff->poinAtEnd--;
    break;
  case 'P':
    i = 'B';
    break;
  case 'M':
    i = 'C';
    opBuff->poinAtEnd++;
    break;
  }
#define TMP "%c", i
  CSI(TMP);
}

void normBackspace(struct state *opBuff) {
  if (opBuff->poinAtEnd == 0)
    return;
  opBuff->poinAtEnd = opBuff->poinAtEnd - 1;
  opBuff->buff[opBuff->poinAtEnd] = (unsigned char)' ';
  putc(8, stdout);
  putc(' ', stdout);
  putc(8, stdout);
}

void normalKey(struct state *opBuff) {
  if (opBuff->currChar == 13)
    opBuff->currChar = '\n';
  opBuff->buff[opBuff->poinAtEnd] = opBuff->currChar;
  opBuff->poinAtEnd += 1;
  putc(opBuff->currChar, stdout);
}

void normMode(struct state *opBuff) {
  switch (opBuff->currChar) {
  case 3:
    opBuff->Mode = COMMAND;
    break;
  case 8:
    normBackspace(opBuff);
    break;
  case 224:
    normKeymove(opBuff);
    break;
  default:
    normalKey(opBuff);
  }
}
int main(int argc, char *argv[]) {
  system("cls");
  struct state opbuff = {0};
  opbuff.Quit_Flag = 1;
  opbuff.Mode = NORM;

  while (opbuff.Quit_Flag && (opbuff.currChar = _getch())) {
    switch (opbuff.Mode) {
    case NORM:
      normMode(&opbuff);
      break;
    case COMMAND:
      commMode(&opbuff);
      break;
    case SELECT:
      break;
    }
  }
  system("cls");
  printf("\n%d\n%s\n", opbuff.poinAtEnd, opbuff.buff);
  return EXIT_SUCCESS;
}
