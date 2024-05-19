base: base.o
	gcc -g -m32 -Wall  -o base base.o 
base.o: base.c 	
	gcc -m32 -g -Wall -c -o base.o base.c 
.PHONY: clean 
clean: 
	rm -f *.o base