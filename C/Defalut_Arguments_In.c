#include <stdio.h>
#define Message(...) Message_handle((Message_args){__VA_ARGS__})

typedef struct{
  char *message;
}Message_args;

void Message_handle(Message_args);
void Message_worker(char*);

void Message_handle(Message_args Struct_name){
  if (Struct_name.message==0)
    Struct_name.message="This is the Default Argument";
  Message_worker(Struct_name.message);
}

void Message_worker(char* message){
  printf("%s\n",message);
}

int main(int argv, char** argc){
  Message(*++argc);
  return 0;
}
