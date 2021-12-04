# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "swapVar.h"                                  // This is the file that contains the swap function, and needs to be included to implement it

int main() {

    // String used to store sentence 1
    char* str1 = malloc(sizeof(char));

    // String used to store sentence 2
    char* str2 = malloc(sizeof(char));

    // Demanding the user the user to enter sentence 1
    printf("Sentence 1:\n");
    fgets(str1, 255, stdin);

    // Demanding the user the user to enter sentence 2
    printf("\nSentence 2:\n");
    fgets(str2, 255, stdin);

    // loop initializers
    int i = 0;
    int j = 0;

    // Booleans used in the swap process
    _Bool b = 0;
    _Bool c = 0;

    // The swap function does not work on single characters, as the entire sentences are swapped instead, so we initialize these two buffers 
    char buff1[255] = "";
    char buff2[255] = "";

    while (i < strlen(str1))
    {
        // The first character of every new word and punctuation marks are the only characters to be swapped once 
        if (i == 0 || b)
        {
            swap(&str1[i], &str2[i]);
            j = 0;
        }

        // All the rest of the characters are swapped twice
        else
        {
            swap(&str1[i], &str2[i]);
            swap(&str1[i], &str2[i]);
        }
        buff1[i] = str1[i];
        buff2[i] = str2[i];
        i++;
        j++;

        // b checks this condition at the end of every word
        b = (str1[i - 1] == ' ' || ((i == strlen(str1) - 3) && j % 2 == 0));

    }

    printf("\nS1:%s\nS2:%s", buff1, buff2);
    free(str1);
    free(str2);
    return 0;
}