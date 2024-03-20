#include <stdio.h>
#include <stdlib.h>

#define SIZEOFCHAR 50

int coun(char, char *);

int main() {
  int n = 0;
  scanf("%d", &n);
  char **Arr = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    Arr[i] = (char *)malloc(SIZEOFCHAR * sizeof(char));
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", Arr[i]);
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
  char Look;
  scanf("%c", &Look);
  int Coun = 0;
  for (int i = 0; i < n; i++) {
    int temp = coun(Look, Arr[i]);
    printf("%d ", temp);
    Coun += temp;
  }
  putchar('\n');
  printf("%d\n", Coun);
}

int coun(char Look, char *Lookup) {
  Look = Look | 32;
  int sum = 0;
  for (char *i = Lookup; *i; i++) {
    sum += (((*i) | 32) == Look);
  }
  return sum;
}
