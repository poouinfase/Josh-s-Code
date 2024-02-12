#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define split(...) split_handle((split_args){__VA_ARGS__})

typedef struct {
  char *strin;
  char sep;
} split_args;

typedef struct {
  char **StrArray;
  int len;
} CstrView;

char *stcp(char *strin, int strt, int end) {
  if (end < strt) {
    return NULL;
  }
  char *out =
      (char *)malloc(sizeof(char) * (end - strt + 1) + 1 * (sizeof(char)));
  char *poin = out;
  for (char *i = strin + strt; (strin + end) - i >= 0; i++) {
    *poin = *i;
    poin++;
  }
  *poin = '\0';
  return out;
}

CstrView split_worker(char *strin, char sep) {
  char **out = malloc(sizeof(char *) * strlen(strin));
  int wor = 0;
  int lef = 0;
  int rig = 0;
  for (char *i = strin; *i != '\0'; i++) {
    if (*(i) == sep || *(i + 1) == '\0') {
      int h = (*i == sep);
      char *s = stcp(strin, lef, rig - h);
      if (s != NULL) {
        // printf("%d %d\t%s\n", lef, rig - h, s);
        out[wor++] = s;
      }
      lef = rig;
      lef++;
    }
    rig++;
  }
  out = realloc(out, wor * sizeof(char *));
  return (CstrView){.StrArray = out, .len = wor};
}
CstrView split_handle(split_args In) {
  In.sep = (In.sep) ? In.sep : ' ';
  return split_worker(In.strin, In.sep);
}

int main() {
  char *strin = (char *)malloc(sizeof(char) * 50);
  if (scanf("%[^\n]*s", strin) == 0)
    return -1;
  const CstrView out = split(strin);
  free(strin);
  for (int i = 0; i < out.len; i++) {
    printf("%s\n", out.StrArray[i]);
    free(out.StrArray[i]);
  }
  free(out.StrArray);
}
