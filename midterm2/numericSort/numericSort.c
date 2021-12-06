# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// C has no definition for size, so we define our own
# define SIZE(a) (sizeof(a) / sizeof(a[0]))

_Bool sort_Numeric(float a[], char** in, int n);

void aBubbleSort(float a[], int n);

void dBubbleSort(float a[], int n);

void aPrint(float a[], int n);

void swap(int* a, int* b);

int main() {

	// The array, Q1 has provided for us
	float a[] = { 10, 0.25, -2342, 12123, 3.145435, 6, 6, 5.999, -2, -5, -109.56 };

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

		v = sort_Numeric(a, &in, n);                    // the array is passed with its length and is evaluated based on in
	}

	free(in);
	return 0;
}
// evaluates the array based on in
_Bool sort_Numeric(float a[], char** in, int n) {

	char buff[255] = "";

	strcpy(buff, *in);

	// Initializing the first character to a char variable
	char e = buff[0];

	_Bool v = 1;                                           // We assume the program has not terminated yet.

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
		printf("Invalid character.\n");                    // Only 'A' and 'D' are accepted and nothing else
	}

	return v;                                              // returns this boolean for termination
}

// Sort a in ascending , with the Bubble Swap Algorithm
void aBubbleSort(float a[], int n)
{

	float temp = 0;

	for (int i = 0; i < n; i++)                           // repeat inner loop 'n' times
	{
		for (int j = 0; j < n-i-1; j++)                   // traverse the array
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);                   // swaps the 2 values
			}
		}
	}
}

// Sort a in descending , with the Bubble Swap Algorithm
void dBubbleSort(float a[], int n)
{

	float temp = 0;

	for (int i = 0; i < n; i++)                               // repeat inner loop 'n' times
	{
		for (int j = n-1; j > i; j--)                         // traverse the array
		{

			if (a[j] > a[j - 1])                              // we don't want greater values ahead
			{
				swap(&a[j], &a[j - 1]);                       // swap the 2 values
			}
		}
	}
}

// prints a upto n elements
void aPrint(float a[], int n)
{
	printf("[");
	int i = 0;

	for (i = 0; i < n-1; i++)                             // traverse the array
	{
		printf("%f, ", a[i]);                             // print corresponding elements

	}

	printf("%f]", a[i]);                                  // print last element
}

// swaps a with b
void swap(int *a, int* b)
{
	int temp = 0;                                         // temporary storage for a
	temp = *a;                                            // store a in temp         
	*a = *b;                                              // store b in a         
	*b = temp;                                            // store temp in b         
}
