#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZEOFPAGEBUFF 5

typedef struct {
  int index;
} page;

struct PageList {
  page *list;
  int len;
};

struct RequestList {
  int *list;
  int len;
};

struct FrameList {
  page **list;
  int len;
};

void fifo(struct RequestList, struct PageList, struct FrameList);
void optimal(struct RequestList, struct PageList, struct FrameList);
void lru(struct RequestList, struct PageList, struct FrameList);

int coun(int, int, struct RequestList);
int srch(int, struct FrameList);
int max(struct RequestList);
int dist(int srch, int cur, struct RequestList Req);

void prinframs(struct FrameList);
void shifright(struct FrameList);
void shifrightatind(struct FrameList Frames, int ind);
void nullify(struct FrameList);

int main() {
  struct PageList Pages;
  struct RequestList Requests;
  struct FrameList Frames;

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

  Pages.len = max(Requests);
  printf("Number of Pages: %d\n", Pages.len);

  assert(Pages.len > 0);

  Pages.list = (page *)malloc(Pages.len * sizeof(page));

  for (int i = 0; i < Pages.len; i++) {
    Pages.list[i].index = i;
  }

  Frames.len = 0;
  puts("Number of Frames: ");
  scanf("%d", &Frames.len);

  Frames.list = (page **)malloc(sizeof(page *) * Frames.len);
  putchar('\n');

  nullify(Frames);
  fifo(Requests, Pages, Frames);

  nullify(Frames);
  lru(Requests, Pages, Frames);

  nullify(Frames);
  optimal(Requests, Pages, Frames);

  free(Requests.list);
  free(Pages.list);

  return 0;
}

void fifo(struct RequestList Req, struct PageList Pag,
          struct FrameList Frames) {
  int hit = 0, miss = 0;
  puts("\n\n\nFIRST IN FIRST OUT:");
  for (int i = 0; i < Req.len; i++) {
    int cur = Req.list[i];
    if (srch(cur, Frames) != -1) {
      hit++;
      prinframs(Frames);
      continue;
    }
    miss++;
    shifright(Frames);
    Frames.list[0] = &Pag.list[cur];
    prinframs(Frames);
  }
  printf("Hit: %d\nMiss: %d\n", hit, miss);
}
void lru(struct RequestList Req, struct PageList Pag, struct FrameList Frames) {
  puts("\n\n\nLEAST RECENTLY USED:");
  int hit = 0, miss = 0;
  for (int i = 0; i < Req.len; i++) {
    int cur = Req.list[i];
    if (srch(cur, Frames) != -1) {
      hit++;
      int ind = srch(cur, Frames);
      shifrightatind(Frames, ind);
      Frames.list[0] = &Pag.list[cur];
      prinframs(Frames);
      continue;
    }
    miss++;
    shifright(Frames);
    Frames.list[0] = &Pag.list[cur];
    prinframs(Frames);
  }
  printf("Hit: %d\nMiss: %d\n", hit, miss);
}

void optimal(struct RequestList Req, struct PageList Pag,
             struct FrameList Frames) {
  puts("\n\n\nOPTIMAL:");
  int hit = 0, miss = 0;
  for (int i = 0; i < Req.len; i++) {
    int cur = Req.list[i];
    if (srch(cur, Frames) != -1) {
      hit++;
      prinframs(Frames);
      continue;
    }
    miss++;

    int min = 0;
    for (int j = 0; j < Frames.len; j++) {
      if (Frames.list[j] == NULL) {
        min = j;
        break;
      }
      if (min == j)
        continue;
      int tmp_c = coun(Frames.list[j]->index, i, Req);
      int min_c = coun(Frames.list[min]->index, i, Req);
      if (tmp_c < min_c) {
        min = j;
      }
      if (tmp_c == min_c) {
        if (dist(Frames.list[j]->index, i, Req) >
            dist(Frames.list[min]->index, i, Req))
          min = j;
      }
    }
    Frames.list[min] = &Pag.list[cur];
    prinframs(Frames);
  }
  printf("Hit: %d\nMiss: %d\n", hit, miss);
}

void prinframs(struct FrameList Frames) {
  for (int i = 0; i < Frames.len; i++) {
    if (Frames.list[i] == NULL)
      continue;
    printf("%d ", Frames.list[i]->index);
  }
  putchar('\n');
}

int srch(int cur, struct FrameList Frames) {
  for (int i = 0; i < Frames.len; i++) {
    if (Frames.list[i] == NULL)
      continue;
    if (cur == Frames.list[i]->index)
      return i;
  }

  return -1;
}

int coun(int srch, int cur, struct RequestList Req) {
  int co = 0;

  for (int i = cur; i < Req.len; i++) {
    if (Req.list[i] == srch)
      co++;
  }
  return co;
}

void shifright(struct FrameList Frames) {
  for (int i = Frames.len - 1; i > 0; i--)
    Frames.list[i] = Frames.list[i - 1];
}
void shifrightatind(struct FrameList Frames, int ind) {
  for (int i = ind; i > 0; i--)
    Frames.list[i] = Frames.list[i - 1];
}

int dist(int srch, int cur, struct RequestList Req) {
  for (int i = cur; i < Req.len; i++)
    if (Req.list[i] == srch)
      return i;

  return INT_MAX;
}

void nullify(struct FrameList Frames) {
  for (int i = 0; i < Frames.len; i++) {
    Frames.list[i] = NULL;
  }
}

int max(struct RequestList Req) {
  int ma = Req.list[0];

  for (int i = 0; i < Req.len; i++)
    if (Req.list[i] > ma)
      ma = Req.list[i];

  return ma;
}
