# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

_Bool palValidate(const char* input);

char* strFilter(const char** input);

int main(void) {

	//Boolean used for checking the validity of the palindrome
	_Bool val = 0;

	// String used to store input
	char *input = malloc(sizeof(char));

	while (!val)
	{
		// Demanding the user to enter a message
		printf("Enter message: ");
		fgets(input, 255, stdin);

		// Check for a palindrome
		val = palValidate(&input);

		// If yes
		if (val)
			printf("Yes, this is a palindrome.");

		// If no
		else
			printf("No, it's not a palindrome.\n\n");
	}

	free(input);
	return 0;
}

// Check whether the given input is a palindrome
_Bool palValidate(const char** input)
{
	_Bool pal = 1;                         // we want a palindrome, but we assume the input is a palindrome, until we check it
	char c = "", d = "";
	int i = 0;
	char buff[255] = "";
	strcpy(buff, strFilter(*input));       // we only want to evaluate with letters, so we filter out all other characters
	int j = strlen(strFilter(*input)) - 1;
	c = buff[i], d = buff[j];

	while (pal && i <= j)              
	{
		if (c != d)                        // c and d being different makes this not a palindrome, so pal is false
			pal = 0;
		i++;
		j--;
		c = buff[i], d = buff[j];
	}

	return pal;
}
// Filter out non-alphabetical characters
char* strFilter(const char* input) {

	char result[255] = "",c="";            // result is the value we are going to return 
	char buff[255] = "";
	int i = 0, j = 0;
	strcpy(buff, input);
	c = buff[i];
    
	while (c != '\0')
	{
		if (c >= 'a' && c <= 'z')          // Any character that is a letter is appended to result
		{
			result[j++] = c;
		}

		if (c >= 'A' && c <= 'Z')
		{
			result[j++] = tolower(c);      // Capitals are allowed, but they are converted to lowercase
		}
		i++;
		c = buff[i];
	}

	result[j] = '\0';

	return result;
}