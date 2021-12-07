# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*

Lab #: 10
Name: Sriram Mohan

*/

char* strcpy(char* strDest, const char* strSrc);

char* strcpy(char* strDest, const char* strSrc) {
    while (*strSrc != '\0')
    {
        *strDest = *strSrc;
        strDest++;
        strSrc++;
    }

    *strDest = '\0'; 
    return "";
}

int main(void) 
{
    char in[20] = "";
    char smallest[20] = "",largest[20]="";
    _Bool first = 1;

    while (strlen(in) != 4)
    {
        printf("Enter word: ");
        scanf("%s", &in);

        if (strlen(in) > 20)
        {
            printf("Invalid.\n");
        }
        
        else {

            if (strcmp(in, smallest) < 0 || first)
            {
                strcpy(&smallest, &in);
            }

            if (strcmp(in, largest) > 0 || first)
            {
                strcpy(&largest, &in);
            }
            first = 0;

        }
    }
    printf("\nSmallest word: %s", smallest);
    printf("\nLargest word: %s\n", largest);

    return 0;
}