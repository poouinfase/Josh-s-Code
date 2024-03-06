#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZEOFPAGEBUFF 5

typedef struct {
  int index;
  int AcessTime;
} page;

struct PageList {
  page *list;
  int len;
};

struct RequestList {
  int *list;
  int len;
};

int main() {
  struct PageList Pages;
  struct RequestList Requests;
  page *PageBuff[SIZEOFPAGEBUFF];

  Requests.len = 0;
  printf("Number of Requests: ");

  if (0 == scanf("%d", &Requests.len))
    return -1;
  putchar('\n');

  assert(Requests.len > 0);

  Requests.list = (int *)malloc(Requests.len * sizeof(int));
  printf("Enter Requests:\n");
  for (int i = 0; i < Requests.len; i++) {
    if (0 == scanf("%d", Requests.list + i))
      return -1;
  }
  putchar('\n');

  Pages.len = 0;
  printf("Number of Pages: ");

  if (0 == scanf("%d", &Pages.len))
    return -1;
  putchar('\n');

  assert(Pages.len > 0);

  Pages.list = (page *)malloc(Pages.len * sizeof(page));

  for (int i = 0; i < Pages.len; i++) {
    Pages.list[i].index = i;
    Pages.list[i].AcessTime = -1;
  }

  free(Requests.list);
  free(Pages.list);
}
