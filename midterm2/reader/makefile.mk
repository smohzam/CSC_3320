# writing all the object files out to the file known as reader
reader:   reader.o problem5char.o problem5lines.o problem5words.o
          gcc -o reader reader.o problem5char.o problem5lines.o problem5words.o -I.
 
# compiling the main program
reader.o: reader.c
          gcc -c reader.c
 
#compiling the problem5char C-program
problem5char.o : problem5char.c
                 gcc -c problem5char.c
 
#compiling the problem5words C-program
problem5words.o : problem5words.c
                  gcc -c problem5words.c
 
#compiling the problem5lines C-program
problem5lines.o : problem5lines.c
                  gcc -c  problem5lines.c
 