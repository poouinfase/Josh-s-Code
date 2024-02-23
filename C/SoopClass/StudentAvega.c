#include <stdio.h>
#include <stdlib.h>

struct student {
  int marks[6];
  float avg;
};

struct student *calcavgusinPoin(struct student *s) {
  for (int i = 0; i < 6; i++)
    s->avg += s->marks[i];
  s->avg /= 6.0;
  return s;
}
struct student calcavgusinVal(struct student s) {
  for (int i = 0; i < 6; i++)
    s.avg += s.marks[i];
  s.avg /= 6.0;
  return s;
}
int main() {
  struct student s = {};
  for (int i = 0; i < 6; i++)
    s.marks[i] = i;
  printf("%.2f\n", calcavgusinVal(s).avg);
  calcavgusinPoin(&s);
  printf("%.2f\n", s.avg);
  return EXIT_SUCCESS;
}
