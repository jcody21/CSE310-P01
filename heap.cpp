// Developer: John Cody
// Date: 03/16/2020
// Class: CSE 310 @ ASU
// Taught by: Guoliang Xue
// Project Name: P01

#include "heap.h"

#include <stdio.h> 
// included for output in printHeap, Insert, DeleteMax, and IncreaseKey

#include <limits.h> 
// included to set the key of a new element to the lowest possible int value in the Insert function

#include <cmath> 
// included for use in the Insert function to calculate the 
// next largest power of 2 to use as the heap capacity



// takes in an index and returns the index of the parent - no checking
int Parent(int i) {
	return (i / 2);
}

// takes in an index and returns where the left child should be - no checking
int Left(int i) {
	return (2 * i);
}

// takes in an index and returns where the right child should be - no checking 
int Right(int i) {
	return (2 * i + 1);
}

// moves the value at index i down the tree until it is larger than both of it's children
void Heapify(Heap* A, int i) {
	int largest = i; // largest will be the compairison value
	int L = Left(i); 
	int R = Right(i); 
	if ((L <= A->size) && (A->H[L].key > A->H[largest].key)) { // finding out which value is the largest
		largest = L; 
	}
	if ((R <= A->size) && (A->H[R].key > A->H[largest].key)) {
		largest = R; 
	}
	if (largest != i) { // if i is still the largest, then we don't do anything, 
		// otherwise swap and call heapify again on the value that got lowered
		int key = A->H[largest].key; 
		A->H[largest].key = A->H[i].key; 
		A->H[i].key = key; 
		Heapify(A, largest); 
	}
}

// creates and returns an empty heap of capacity n
Heap* Initialize(int n) {
	Heap *x = new Heap; // allocating memory for a new heap
	x->capacity = n; // VvV storing data VvV
	x->size = 0;
	x->H = new Element[n + 1];
	return x;
}

// loops through Element array A and writes the values of the keys into the Heap heap. 
void BuildHeap(Heap* heap, Element* A, int n) {
	for (int i = 1; i <= n; i++) { 
		heap->H[i].key = A[i].key; // writing the values of the array into the heap
		heap->size++; // increasing the size as elements are added
	}
	for (int i = heap->size; i > 0; i--) {
		Heapify(heap, i); // calling heapify on the elements to ensure the heap is ordered properly
	}
}

// inserts a new element into the Heap heap, with a value of k
// the heap is not large enough to support another element, then
// the heap is grown to the next power of 2
void Insert(Heap* heap, int flag, int k) {
	if (flag == 2) { // showing what the heap looks like before the Insert
		printf("Before insert operation:\n");
		printHeap(heap);
	}
	
	if (heap->size == heap->capacity) { // checking to see if the heap needs to grow
		int capacity = (int) ((log(heap->size + 0.3) / log(2)) + 1); // this actually calculates the exponent
		capacity = (int) pow(2, capacity); //this calculates the new capacity
		Element* A = new Element[capacity+1]; // allocating a new array 
		for (int i = 1; i <= heap->size; i++) { 
			A[i] = heap->H[i]; // storing the values in the new element array
		}
		delete[] heap->H; // deleting the old element array
		heap->H = A; // having heap point to the new element array
		heap->capacity = capacity; // storing the new capacity into the heap
	}

	heap->size++; // increasing the size of the heap as we will be adding a new element
	heap->H[heap->size].key = INT_MIN; // setting the key to the smallest possible value an int can hold
	IncreaseKey(heap, 1, heap->size, k); // increasing the key to the value that it will actually hold

	if (flag == 2) { // showing what the heap looks like after the Insert
		printf("After insert operation:\n");
		printHeap(heap);
	}
} 

// deletes the max element of the heap, and then reorders the heap appropriately
Element DeleteMax(Heap* heap, int flag) {
	if (flag == 2) { // printing info about the heap before deleting the max element
		printf("Before delete max operation:\n");
		printHeap(heap);
	}

	Element max = heap->H[1]; // copying the max element into max
	heap->H[1] = heap->H[heap->size]; // writing over the max element with the last element in the heap
	heap->size--; // decreasing the size of the heap
	Heapify(heap, 1); // moving the "max" down into it's new position 
	//somewhere where it obeys the laws of heap

	if (flag == 2) { // printing info after the delete max operation
		printf("After delete max operation:\n");
		printHeap(heap);
	}

	return max; // returning the element that holds the previous max
}

// increases the key of the element at index to value and then reorders
// the heap appropriately
void IncreaseKey(Heap* heap, int flag, int index, int value) {
	if (flag == 2) { // printing info about the heap before any operations
		printf("Before increase key operation:\n");
		printHeap(heap);
	}

	heap->H[index].key = value; // changing the value of the key 
	while ((index > 1) && (heap->H[index].key > heap->H[Parent(index)].key)) { 
		// checking to make sure parent and child obey the heap property
		// if they don't, swap, if they do, we're done
		int key = heap->H[Parent(index)].key; 
		heap->H[Parent(index)].key = heap->H[index].key;
		heap->H[index].key = key;
		index = Parent(index);
	}

	if (flag == 2) { // printing info about the heap after completing the operations
		printf("After increase key operation:\n");
		printHeap(heap);
	}
}

// takes in a heap pointer and prints the size, the 
// capacity, and the key values of the elements
void printHeap(Heap* heap) {
	printf("Capacity = %d\n", heap->capacity); // printing the capacity
	printf("Size = %d\n", heap->size); // printing the size
	for (int i = 1; i <= heap->size; i++) { // printing all of the elements
		printf("%d\n", heap->H[i].key);
	}
}