#include <stdio.h>

/*

Lab #: 7
Name: Sriram Mohan

*/

int main(void)
{
	float up=0,total=0;
	int n, q;
	char pd[]="";
	printf("Enter item number:  ");
	scanf("%d", &n);
	printf("Enter unit price: ");
	scanf("%f", &up);
	printf("Enter quantity: ");
	scanf("%d", &q);
	printf("Enter purchase date (MM/DD/YYYY): ");
	scanf("%s", &pd);
	total = q*up;
	printf("Item	Unit	Price	QTY	Purchase Date	Total	Amount");
	printf("\n%-d	$	%.2f	%-d	%-s	$	%.2f", n, up, q, pd, total);
	return 0;

}