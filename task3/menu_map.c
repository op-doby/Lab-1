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
    return c+0x20;
  return c;
}

char decrypt(char c){
/* Gets a char c and returns its decrypted form subtractng 0x20 from its value. But if c was not between 0x40 and 0x7E it is returned unchanged */
  if(c <= 0x7E && c>=0x40)
    return c-0x20;
  return c;
}

char xoprt(char c){
/* xoprt prints the value of c in a hexadecimal representation, then in octal representation, followed by a new line, and returns c unchanged. */
  printf("%02X ", (unsigned char)c);
  printf("%03o", (unsigned char)c);
  printf("\n");
  return c;
}

struct fun_desc {
char *name;
char (*fun)(char);
};

struct fun_desc menu_items[] = {{"Get string",&my_get},{"Print string",&cprt},{"Encrypt",&encrypt},{"Decrypt",&decrypt},{"Print Hex and Octal",&xoprt},{NULL,NULL}};

void menu(){
  char* carray = (char*)(malloc(5*sizeof(char)));
  int bound = 0;
  char input[256];  
  while (!feof(stdin))
  { 
    printf("Select operation from the following menu: (ctrl^D for exit) \n");
    for (int i = 0; menu_items[i].name != NULL; i++) {
        printf("%d) %s\n", i , menu_items[i].name);
        bound++;
    }
    printf("Option: ");
    if(fgets(input,256,stdin)==NULL) // could be due to ctrl^d or not entering anything
      break;
    int choice = atoi(input); 
    if((choice < bound) && (choice>=0))
      printf("Within bounds\n");
    else
    {
      printf("Not within bounds\n");
      break;
    }
    char* temp = carray;
    carray = map(carray,5,menu_items[choice].fun);
    free(temp);
  }

  free(carray);

}

int main(int argc, char **argv){
  /* TODO: Test your code */
  menu();
  
}
  

