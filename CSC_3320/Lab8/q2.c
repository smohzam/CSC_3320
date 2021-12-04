#include <stdio.h>

int main() {

    int letters = 0;
    int words = 0;
    char character = ' ';
    _Bool space = 1;
    printf("Enter a Sentence: ");

    while ((character = getchar()) != '\n') {
        if (character != ' ') {
            if (!space) {
                words++;
                space = 1;
            }
            letters++;
        }
        else
            space = 0;
    }
    words++;
    printf("Average word length : %.1f", (double) letters/words);

    return 0;
} 
