/*
 * heapsort.c
 *
 *  Created on: Feb 6, 2022
 *      Author: Seung Park
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 128

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	// BuildHeap on the list
		buildHeap(A, n);
	// sort
	for(int i=n-1;i>=0;i--){
		swap(&A[n-1], &A[0]);
		heapify(A, 0, n-1);
	}
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	//heapify() every element from A[n/2] to A[0]
	int node = floor(n-1/2);
		for(int i=node;i>=0;i--){
			heapify(A, i, node);
		}
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	int left_index = 2*(i+1)-1; // get index of left child of element i
	int right_index = 2*(i+1); // get index of right child of element i
	int left_child = A[left_index].salary;
	int right_child = A[right_index].salary;
	int smaller = i;

	if(left_child<A[smaller].salary && left_child<right_child){ // determine which child has a smaller salary
		smaller = left_index;
	}
	if(right_child<A[smaller].salary && right_child<left_child){
		smaller = right_index;
	}

	// recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	// Then recursively heapify A[smaller].
	// Continue recursion as long as i is within range AND either right_child and left_child are still within range.
	if(smaller != i){
		swap(&A[i], &A[smaller]);
		heapify(A, smaller, n);
	}
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{	
	printf("[ ID = %s SALARY = %d ] \n", A[n-1].name, A[n-1].salary);
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	struct Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	for(int i=0; i<n;i++){
		if(i==(n-1)){
			printf("[ ID = %s SALARY = %d ] \n", A[i].name, A[i].salary);
		}else{
			printf("[ ID = %s SALARY = %d ], ", A[i].name, A[i].salary);
		}
	}
}
