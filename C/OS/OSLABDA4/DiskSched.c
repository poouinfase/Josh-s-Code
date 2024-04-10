#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *list;
  size_t len;
} ReqQue;

typedef struct {
  int curr;
  int max;
  int targ;
} rwHead;

int isEmpty(ReqQue *req);

ReqQue *ReqInit() {
  ReqQue *Out = (ReqQue *)malloc(sizeof(ReqQue));

  Out->len = 0;
  printf("Number of Requests: ");
  scanf("%llu", &Out->len);

  Out->list = (int *)malloc(Out->len * sizeof(int));

  for (int i = (int)Out->len - 1; i >= 0; i--) {
    Out->list[i] = 0;
    printf("Request %llu : ", Out->len - i);
    scanf("%d", &Out->list[i]);
  }

  return Out;
}

void printReq(ReqQue *req) {
  for (int i = 0; i < req->len; i++) {
    if (req->list[i] == -1)
      continue;
    printf("%d ", req->list[i]);
  }
  printf("\n");
  return;
}

void ReqFree(ReqQue *in) {
  free(in->list);
  in->list = NULL;
  in->len = 0;
  free(in);
}

int FIFOInit(ReqQue *req, rwHead *head) {
  int index = -1;
  for (int i = 0; i < req->len; i++) {
    if (req->list[i] == -1)
      continue;
    head->targ = req->list[i];
    index = i;
  }
  return index;
}

int FIFO(ReqQue *req, rwHead *head) {
  int ind = FIFOInit(req, head);
  if (ind != -1)
    req->list[ind] = -1;
  printReq(req);
  return ind;
}

int SSTF(ReqQue *req, rwHead *head) {
  int min = FIFOInit(req, head);

  for (int i = 0; i < req->len; i++) {
    if (req->list[i] == -1)
      continue;
    if (abs(head->curr - req->list[i]) < abs(head->curr - head->targ)) {
      head->targ = req->list[i];
      min = i;
    }
  }
  req->list[min] = -1;
  return head->targ == -1;
}

int CSCAN(ReqQue *req, rwHead *head) {
  static int dir = 1;

  head->targ = head->max * dir;

  for (int i = 0; i < req->len; i++) {
    if (dir != (req->list[i] > head->curr))
      continue;

    int delet = req->list[i];
    req->list[i] = -1;
    if (isEmpty(req)) {
      head->targ = delet;
      return i;
    }
  }
  dir = !dir;

  return head->targ;
}

int SCAN(ReqQue *req, rwHead *head) {

  head->targ = head->max;

  if (head->curr == head->max) {
    head->targ = 0;
    return 0;
  }

  for (int i = 0; i < req->len; i++) {
    if ((req->list[i] < head->curr))
      continue;
    int delet = req->list[i];
    req->list[i] = -1;
    if (isEmpty(req)) {
      head->targ = delet;
      return 0;
    }
  }

  return 0;
}

int max(ReqQue *req, rwHead *head) {
  int max = req->list[FIFOInit(req, head)];
  for (int i = 0; i < req->len; i++) {
    if (req->list[i] == -1)
      continue;
    if (req->list[i] > max)
      max = req->list[i];
  }
  return max;
}

int min(ReqQue *req, rwHead *head) {
  int min = req->list[FIFOInit(req, head)];
  for (int i = 0; i < req->len; i++) {
    if (req->list[i] == -1)
      continue;
    if (req->list[i] < min)
      min = req->list[i];
  }
  return min;
}

int CLOOK(ReqQue *req, rwHead *head) {
  head->targ = max(req, head);
  if (head->targ < head->curr) {
    head->targ = min(req, head);
    return 0;
  }

  for (int i = 0; i < req->len; i++) {
    if (req->list[i] >= head->curr)
      req->list[i] = -1;
  }
  return 0;
}

int isEmpty(ReqQue *req) {
  int cou = 0;
  for (int i = 0; i < req->len; i++)
    cou += req->list[i] == -1;
  return cou == req->len;
}

int EvalAlgo(int (*Alg)(ReqQue *, rwHead *), ReqQue *req, rwHead *head) {
  int seek = 0;
  for (int i = 0; !isEmpty(req) && i < req->len; i++) {
    Alg(req, head);
    seek += abs(head->targ - head->curr);
    printf("%d->%d SEEK TIME: %d\n", head->curr, head->targ, seek);
    head->curr = head->targ;
  }
  printf("Total Seek Time: %d\n", seek);
  return seek;
}

int main(int argc, char *argv[]) {
  ReqQue *Req = ReqInit();
  // printReq(Req);
  // putchar('\n');
  rwHead temp = {50, 199}; // curr max
  EvalAlgo(&CLOOK, Req, &temp);
  ReqFree(Req);

  return EXIT_SUCCESS;
}
