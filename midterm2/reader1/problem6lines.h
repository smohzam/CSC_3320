# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void problem6lines(FILE* fp, char* buff, int* n);

// counts no.of lines in fp using buff, and stores in n
void problem6lines(FILE* fp, char* buff, int* n) {

    int i = 0, j = 0;

    char c = buff[i];
    while ((c = fgetc(fp)) != EOF) {   // reads all characters until the end of the file

            fgets(buff, 1000, (FILE*)fp);
        while (c != '\0') {            // reads all characters until the end of the line
                c = buff[i];

            i++;

        }
        j++;                          // every newline characters signifies a new line
            i++;
        c = buff[i];
    }

    j++;                              // end of file signifies the last line
    *n = j;                           // j is passed on to n

}


