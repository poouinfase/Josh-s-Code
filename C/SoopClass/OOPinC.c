#include <stdio.h>
#include <stdlib.h>

#define Date(...) Date_handle((Date_args){__VA_ARGS__})

typedef struct {
  int dd;
  int mm;
  int yyyy;
} date;

typedef struct {
  date *Templ;
} Date_args;

date *Date_handle(Date_args);
date *Date_Construct(date *);
void printDate(date *);

date *Date_handle(Date_args in) {
  in.Templ = (in.Templ) ? in.Templ : NULL;
  return Date_Construct(in.Templ);
}

date *Date_Construct(date *Templ) {

  date *Construction = (date *)malloc(sizeof(date));

  if (Templ == NULL) {
    Construction->dd = 1;
    Construction->mm = 1;
    Construction->yyyy = 1970;
  } else {
    Construction->dd = Templ->dd;
    Construction->mm = Templ->mm;
    Construction->yyyy = Templ->yyyy;
  }

  return Construction;
}

void printDate(date *In) { printf("%d-%d-%d\n", In->dd, In->mm, In->yyyy); }

int main(int argc, char *argv[]) {
  date cpy = {69, 420, 96};
  date *Temp = Date(&cpy);
  printDate(Temp);
  return EXIT_SUCCESS;
}
