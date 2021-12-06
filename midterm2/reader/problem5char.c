# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
void problem5char(FILE* fp, char* buff, int* );
 
// counts no.of characters in fp using buff, and stores in n
void problem5char(FILE* fp, char* buff, int* n) {
 
    int i = 0, j=0;
 
    char c = buff[i];
    while ((c = fgetc(fp)) != EOF) {   // reads all characters until the end of the file
 
        fgets(buff, 1000, (FILE*)fp);
        while (c != '\0') {            // reads all characters until the end of the line
            c = buff[i];
 
            i++;
            j++;                       // all characters are actual characters except '\n' and '\0' 
        }
        i++;
        c = buff[i];
    }
 
    *n = j;                             // j is passed on to n
 
}