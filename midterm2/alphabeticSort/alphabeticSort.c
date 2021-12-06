# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// C has no definition for size, so we define our own
# define SIZE(a) ( sizeof(a) / sizeof(a[0]))

_Bool sort_Alphabetic(char** a[], char** in, int n);

void aBubbleSort(char*** a[], int n);

void dBubbleSort(char*** a[], int n);

void aPrint(char** a[], int n);

void swap(const char** str1, const char** str2);

int main() {

	// The array, Q2 has provided for us
	char* a[] = { "System", "Programming", "Deep", "Learning", "Internet", "Things", "Robotics", "Course" };

	// The length of the array
	int n = SIZE(a);

	// The variable that stores the input
	char* in = malloc(sizeof(char));

	// The boolean that will terminate the program, when the user inputs a valid character
	_Bool v = 1;

	while (v)
	{

		// Prompts the user to enter a valid character
		printf("\nAscending(A) or descending(D)?: ");

		// Stores value in the in variable
		scanf("\n %s", in);

		v = sort_Alphabetic(a, &in, n);                       // the array is passed with its length and is evaluated based on in
	}
	
	free(in);
	return 0;
}
    // evaluates the array based on in
	_Bool sort_Alphabetic(char** a[], char** in, int n) {

		char buff[255] = "";

		strcpy(buff, *in);

		// Initializing the first character to a char variable
		char e = buff[0];

		_Bool v = 1;

		if (e == 'A' || e == 'a')                              // 'A' and 'a' are for ascending, so we must sort in ascending order
		{
			aBubbleSort(a, n);                                 // sorts a in ascending, with the Bubble Swap Algorithm
			v = 0;                                             // terminates
			aPrint(a, n);                                      // prints a upto n characters
		}

		else if (e == 'D' || e == 'd')                         // 'D' and 'd' are for descending, so we must sort in descending order
		{
			dBubbleSort(a, n);                                 // sorts a in descending, with the Bubble Swap Algorithm
			v = 0;                                             // terminates
			aPrint(a, n);                                      // prints a upto n characters
		}

		else
		{
			printf("Invalid character.\n");                   // Only 'A' and 'D' are accepted and nothing else
		}

		return v;
	}

	// Sort a in in ascending , with the Bubble Swap Algorithm
	void aBubbleSort(char*** a[], int n)
	{

		for (int i = 0; i < n; i++)                             // repeat inner loop 'n' times
		{
			for (int j = 0; j < n-i-1; j++)                     // traverse the array
			{

				if (strcmp(a[j], a[j+1]) > 0)                   // we don't want greater values beforehand 
				{
					swap(&a[j], &a[j + 1]);                     // swap the 2 values
				}
			}
		}
	}

	// Sort a in in descending , with the Bubble Swap Algorithm
	void dBubbleSort(char*** a[], int n)                        // repeat inner loop 'n' times
	{

		for (int i = 0; i < n; i++)                             // traverse the array
		{
			for(int j = n-1-i; j > 0; j--)
			{

				if (strcmp(a[j], a[j - 1]) > 0)                 // we don't want greater values ahead
				{
					swap(&a[j], &a[j - 1]);                     // swap the 2 values
				}
			}
		}
	}

	// prints a upto n elements
	void aPrint(char** a[], int n)
	{
		printf("[");
		int i = 0;

		for (i = 0; i < n - 1; i++)                           // traverse the array
		{
			printf("%s, ", a[i]);                             // print corresponding elements

		}

		printf("%s]", a[i]);                                  // print last element
	}

	// Swap 2 variables with one another
	void swap(const char** str1, const char** str2)
	{
		*str1 = *str1 + (*str1 - *str2);              // adding the difference of the integer values of these two strings gives 2str1 - str2
		*str2 = *str1 - (*str1 - *str2) / 2;          // substracting half of that difference from the first value gives str1 to str2
		*str1 = *str1 - (*str1 - *str2) * 2;          // substracting twice that difference from the first value gives str2 to str1
	}