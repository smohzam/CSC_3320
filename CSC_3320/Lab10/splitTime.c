#include <stdio.h>
#include <stdlib.h>

/*

Lab #: 10
Name: Sriram Mohan

*/

void split_time(long total_sec, int *hr, int *min, int *sec);

int main() {
	long n=0;
	int *hr=0, *min=0, *sec=0;
	printf("Enter seconds: ");
	scanf("%d", &n);

	split_time(n, &hr, &min, &sec);
	printf("Converted format: %d hours %d mins %d secs", hr,min,sec);
	return 0;

}

void split_time(long total_sec, int *p, int *q, int *r) {
	*p = (int) total_sec / 3600;
	*q = (int) total_sec / 60;
	*r = (int) total_sec;
}