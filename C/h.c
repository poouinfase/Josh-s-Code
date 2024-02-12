#include <stdio.h>
int main(int argc, char **argv) {

  if (argc == 1)
    puts("ECHO is on");

  for (int i = 1; i < argc; i++)
    puts(*(argv + i));
}
