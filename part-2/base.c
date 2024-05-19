#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  for(int i=0; i< array_length; i++){
    mapped_array[i]=(*f)(array[i]);
  }
  return mapped_array;
}
char foo(char c){
  return c+1;
}
int main(int argc, char **argv){
  /* TODO: Test your code */
  int array_length = 3;
  char* array = (char*)(malloc(array_length*sizeof(char)));
  array[0]='1'; array[1]='2'; array[2]='3';
  char (*foo1)(char) =foo;
  char* mapped_array = map(array,array_length,foo1);
  for(int i=0; i<array_length; i++){
    printf("%c \n",mapped_array[i]);
  }
}
  

