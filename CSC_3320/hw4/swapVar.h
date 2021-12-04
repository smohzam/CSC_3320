# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void swap(const char** str1, const char** str2);

// Swap 2 variables with one another
void swap(const char** str1, const char** str2)
{
    *str1 = *str1 + (*str1 - *str2);              // adding the difference of the integer values of these two strings gives 2str1 - str2
    *str2 = *str1 - (*str1 - *str2)/2;            // substracting half of that difference from the first value gives str1 to str2
    *str1 = *str1 - (*str1 - *str2) * 2;          // substracting twice that difference from the first value gives str2 to str1
}

