count-words: count-words.o
	gcc -g -m32 -Wall  -o count-words count-words.o 
count-words.o: count-words.c 
#if it doesn't work to add the -c	
	gcc -m32 -g -Wall -c -o count-words.o count-words.c 
.PHONY: clean 
clean: 
	rm -f *.o count-words

