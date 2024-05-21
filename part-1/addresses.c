#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int addr5;
int addr6;

int foo()
{
    return -1;
}
void point_at(void *p);
void foo1();
char g = 'g';
void foo2();

int secondary(int x)
{
    int addr2;
    int addr3;
    char *yos = "ree";
    int *addr4 = (int *)(malloc(50));
	int iarray[3];
    float farray[3];
    double darray[3];
    char carray[3]; 
	int iarray2[] = {1,2,3};
    char carray2[] = {'a','b','c'};
    int* iarray2Ptr;
    char* carray2Ptr; 
    
	printf("- &addr2: %p\n", &addr2);
    printf("- &addr3: %p\n", &addr3);
    printf("- foo: %p\n", &foo);
    printf("- &addr5: %p\n", &addr5);
	printf("Print distances:\n");
    point_at(&addr5);

    printf("Print more addresses:\n");
    printf("- &addr6: %p\n", &addr6);
    printf("- yos: %p\n", yos);
    printf("- gg: %p\n", &g);
    printf("- addr4: %p\n", addr4);
    printf("- &addr4: %p\n", &addr4);

    printf("- &foo1: %p\n", &foo1);
    printf("- &foo1: %p\n", &foo2);
    
    printf("Print another distance:\n");
    printf("- &foo2 - &foo1: %ld\n", (long) (&foo2 - &foo1));

   
    printf("Arrays Mem Layout (T1b):\n");

    /* task 1 b here */
    
    printf("Pointers and arrays (T1d): ");

    /* task 1 d here */
    

}

int main(int argc, char **argv)
{ 
    int iarray[3];
    for(int i=0; i<3; i++)
        printf("iarray each cell: %p\n", &iarray[i]);
    printf("iarray: %p\n", iarray);
    printf("iarray + 1: %p\n", iarray+1);

    float farray[3];
    for(int i=0;i<3 ;i++)
        printf("farray each cell: %p\n", &farray[i]);
    printf("farray: %p\n", farray);
    printf("farray + 1: %p\n", farray+1);

    double darray[3];
    for (int i=0; i < 3; i++)
        printf("darray each cell: %p\n", &darray[i]);
    printf("darray: %p\n", darray);
    printf("darray + 1: %p\n", darray+1);

    char carray[3];
    for (int i=0; i < 3; i++)
        printf("carray each cell: %p\n", &carray[i]);
    printf("carray: %p\n", carray);
    printf("carray + 1: %p\n", carray+1);

    int iarray2[] = {1,2,3};
    char carray2[] = {'a','b','c'};
    int* iarray2Ptr;
    char* carray2Ptr;
    int *iarrayPtr = iarray2;
    char *carrayPtr = carray2;
    int i=0;
    while(iarrayPtr[i]!=(char)0){
        printf("iarray: %d\n", iarrayPtr[i]);
        i++;
    }
    i=0;
    while(carrayPtr[i]!=(char)0){
        printf("iarray: %c\n", carrayPtr[i]);
        i++;
    }
    int *p;
    printf("local variable p: %p\n", p);

    for (int i=0; i< argc; i++){
        printf("command line arguments addresses: %p\n", argv[i]);
    }

    printf("Print function argument addresses:\n");

    printf("- &argc %p\n", &argc);
    printf("- argv %p\n", argv);
    printf("- &argv %p\n", &argv);
	
	secondary(0);
    long l = sizeof(carray);
    
    printf("Command line arg addresses (T1e):\n");
    /* task 1 e here */
    
    return 0;
}

void point_at(void *p)
{
    int local;
    static int addr0 = 2;
    static int addr1;
    // test(code)->data segment(global/static)->heap-> stack(local variables)
    //p is a global int pointer (but send as an argument)
    long dist1 = (size_t)&addr6 - (size_t)p;//global int - global int  
    long dist2 = (size_t)&local - (size_t)p; // local int - global int   (the local is higher)
    long dist3 = (size_t)&foo - (size_t)p;// function(lower)- global int
    long sizeoflong = sizeof(long);


    printf("- dist1: (size_t)&addr6 - (size_t)p: %ld\n", dist1);
    printf("- dist2: (size_t)&local - (size_t)p: %ld\n", dist2);
    printf("- dist3: (size_t)&foo - (size_t)p:  %ld\n", dist3);
    printf("size of long:  %ld\n", sizeoflong);

    
    printf("Check long type mem size (T1a):\n");
    /* part of task 1 a here */

    printf("- addr0: %p\n", &addr0);
    printf("- addr1: %p\n", &addr1);
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}


