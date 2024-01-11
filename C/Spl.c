#include <stdio.h>
#include <stdlib.h>

char *stcp(char *strin, int strt, int end) {
  char *out = "\0";
  if (end < strt)
    return out;

  out = (char *)malloc(sizeof(char) * (end - strt + 1) + 1);
  char *poin = out;
  for (char *i = strin + strt; (strin + end) - i >= 0; i++) {
    *poin = *i;
    poin++;
  }
  *poin = '\0';
  return out;
}

char **split(char *strin, char sep) {
  char **out;
  int lef = 0;
  int rig = 0;
  for (char *i = strin; *i != '\0'; i++) {
    if (*(i) == sep || *(i + 1) == '\0') {
      int h = (*i == sep) ? 1 : 0;
      printf("%d %d\t%s\n", lef, rig - h, stcp(strin, lef, rig));
      lef = rig;
      lef++;
    }
    rig++;
  }
  return out;
}

int main() {
  char *strin = (char *)malloc(sizeof(char) * 50);
  scanf_s("%[^\n]*s", strin);
  // printf_s("%s\n", strin);
  split(strin, ' ');
}
