#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  for(int i=0; i< array_length; i++){
    mapped_array[i]=(*f)(array[i]); // applying f on the array values 
  }
  return mapped_array;
}
char foo(char c){
  return c+1;
  }


char my_get(char c){
  /* Ignores c, reads and returns a character from stdin using fgetc. */
  return (char)fgetc(stdin);
}

char cprt(char c){
/* If c is a number between 0x20 and 0x7E, cprt prints the character
 of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character.
  After printing, cprt returns the value of c unchanged. */
  if(c <= 0x7E && c>=0x20)
    printf("%c\n", (char)c);
  else  
    printf(".\n");
  return c;
}

char encrypt(char c){
/* Gets a char c. If c is between 0x20 and 0x4E add 0x20 to its value and return it. Otherwise return c unchanged */
  if(c <= 0x4E && c>=0x20)
    c= c+0x20;
  return (char)c;
}

char decrypt(char c){
/* Gets a char c and returns its decrypted form subtractng 0x20 from its value. But if c was not between 0x40 and 0x7E it is returned unchanged */
  if(c <= 0x7E && c>=0x40)
    return (char)(c-0x20);
  return (char)c;
}

char xoprt(char c){
/* xoprt prints the value of c in a hexadecimal representation, then in octal representation, followed by a new line, and returns c unchanged. */
  printf("%02X ", (unsigned char)c);
  printf("%03o", (unsigned char)c);
  printf("\n");
  return c;
}
void menu(){
  printf("Select operation from the following menu: \n");

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
  free(array);
  free(mapped_array);

  int base_len = 5;
  char arr1[base_len];
  char* arr2 = map(arr1, base_len, my_get);
  char* arr3 = map(arr2, base_len, cprt);
  char* arr4 = map(arr3, base_len, xoprt);
  char* arr5 = map(arr4, base_len, encrypt);
  free(arr2);
  free(arr3);
  free(arr4);
  free(arr5);
}
  

