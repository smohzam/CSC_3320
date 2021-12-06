# writing all the object files out to the file known as reader
reader1:   reader1.o problem6char.h problem6lines.h problem6words.h
           gcc -o reader1 reader1.o problem6char.h problem6lines.h problem6words.h -I.
 
# compiling the main file
reader1.o: reader1.c
           gcc -c reader1.c
 