#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 7

int main()
{
	struct Employee A[MAX_EMPLOYEES];
	char reply = 'y';
	int inc = 0;
	//TODO
	while(reply != 'n'  && inc<MAX_EMPLOYEES){
		printf("This is the incrementor: %d\n", inc);
		printf("Name: ");
		scanf("%s", A[inc].name);
		printf("Salary: ");
		scanf("%d", &A[inc].salary);
		if(inc<MAX_EMPLOYEES-1){
			printf("Enter another user? (y/n) ");
			scanf(" %c", &reply);
		}
		inc++;
	}

	printf("Before heapsort: \n");
	printList(A, inc);
	printf("After heapsort: \n");
	heapSort(A, inc);
	printList(A, inc);
	return 0;
}
