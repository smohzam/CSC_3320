#include <stdio.h>
#include <stdlib.h>
 
// including the header files to get their respective functions
# include "problem6char.h"
# include "problem6words.h"
# include "problem6lines.h"
 
// demanding the user to enter arguments from command line
int main(int argc, char* argv[]) {
 
    // counters for characters, words, and lines respectively 
    int i = 0,j = 0,k = 0;
 
    // these are the pointers to input and output respectively
    FILE* fp, *fo;
 
    // reading from the source file (argument 1)
    fp = fopen(argv[argc - 2], "r");
 
    // writing to the destination file (argument 2)
    fo = fopen(argv[argc - 1], "a");
 
    char buff[1000] = "";
 
    fgets(buff, 1000, (FILE*)fp);
 
    problem6char((FILE*)fp, buff, &i);                    // count no.of characters in fp and rewinds
    rewind(fp);
 
    problem6lines((FILE*)fp, buff, &j);                   // count no.of lines in fp and rewinds
    rewind(fp);
 
    problem6words((FILE*)fp, buff, &k);                   // count no.of words in fp and rewinds
    rewind(fp);
 
    // making sure file exists and then appending to it the no.of words, characters, and lines.
    if(fo != NULL)
     fprintf(fo,"C:%d\t W:%d\t L:%d\n", i,k,j);
 
    // close both the file pointers
    fclose(fp);
    fclose(fo);
    return 0;
}
 


