#include <stdio.h>
#define i 5
int main(){
#if !defined(i)
#define i 8
#endif
#if i<8
printf("<8");
#else
Fun Fact: This line is a syntax error but the code will compile thanks to the preprocessor macro
#endif
}
