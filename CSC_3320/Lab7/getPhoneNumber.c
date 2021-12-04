#include <stdio.h>

/*

Lab #: 7
Name: Sriram Mohan

*/

int main(void)
{
	int i, j, k;
	printf("Enter phone number [(999)-999-9999]:  ");
	scanf("(%3d)-%3d-%4d", &i, &j, &k);
	printf("You entered (%3d)-%3d-%4d\n", i,j,k);
		return 0;
}