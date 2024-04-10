#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *list;
  size_t len;
} ReqQue;

typedef struct {
  int curr;
  int targ;
} rwHead;

ReqQue *ReqInit() {
  ReqQue *Out = (ReqQue *)malloc(sizeof(ReqQue));

  Out->len = 0;
  puts("Number of Requests: ");
  scanf("%llu\n", &Out->len);

  Out->list = (int *)malloc(Out->len * sizeof(int));

  for (int i = 0; i < Out->len; i++) {
    Out->list[i] = 0;
    printf("Request %d: ", i + 1);
    scanf("%d", &Out->list[i]);
  }

  return Out;
}

void ReqFree(ReqQue *in) {
  free(in->list);
  in->list = NULL;
  in->len = 0;
  free(in);
}

int FIFO(ReqQue *req, rwHead *head) { return 1; }

int EvalAlgo(int (*Alg)(ReqQue *, rwHead *), ReqQue *req, rwHead *head) {
  int seek = 0;
  for (int i = 0; i < req->len; i++) {
    Alg(req, head);
    seek += abs(head->targ - head->curr);
  }
  printf("Seek Time: %d", seek);
  return seek;
}

int main(int argc, char *argv[]) {
  ReqQue *Req = ReqInit();
  ReqFree(Req);
  return EXIT_SUCCESS;
}
