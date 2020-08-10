// Developer: John Cody
// Date: 03/16/2020
// Class: CSE 310 @ ASU
// Taught by: Guoliang Xue
// Project Name: P01

#include <stdio.h>  // included to be used for output
#include <stdlib.h> // included for exit() function
#include "heap.h"
#include "util.h"

int main()
{
	// variables for the parser...
	char c;
	int i, v, f;
	Heap *myHeap; // the heap pointer that will be used throughout
	bool initialized = false; // simple check to see if the 
	// heap has been initialized, only the Command: C will change it 

	while (1) {
		c = nextCommand(&f, &i, &v); // waiting for the next piece of input
		switch (c) {
		case 'S': { // ending the program
			printf("COMMAND: %c\n", c);
			if (initialized == true) { // deleting dynamic memory if it was allocated
				delete[] myHeap->H;
				delete myHeap;
			}
			exit(0);
		}

		case 'C': { // initializing a heap
			printf("COMMAND: %c %d\n", c, f);
			if (initialized == true) { // checking to see if the heap has already been initialized
				delete[] myHeap->H; // if it has then we delete the old heap
				delete myHeap;
			}
			if (f < 0) { // checking to make sure the the capacity of the heap is 0 or more
				printf("Error: invalid heap capacity\n");
			}
			else {
				myHeap = Initialize(f); // initializing the heap
				initialized = true; //changing the initialization checker
			}

			break;
		}

		case 'R': { // reads an array from a file and then writes the values of the array into a heap
			printf("COMMAND: %c\n", c);
			if (initialized == false) { // checking to make sure that the heap has been initialized
				printf("Error: heap not initialized\n");
				break;
			}
			else {
				Element* A = NULL; 
				v = fileReader(A); // saving the capacity of the array in v and the elements in A
				myHeap->size = 0; // getting rid of everything that was previously in the heap

				if (v > myHeap->capacity) { // checking to make sure that the array will fit into the heap
					printf("Error: array size exceeds heap capacity\n");
				}
				else {
					BuildHeap(myHeap, A, v); // putting the values of A into myHeap
				}

				delete[] A; // deleting the allocated array A
				break;
			}
		}

		case 'W': { // printing the heap and some info about it
			printf("COMMAND: %c\n", c);
			if (initialized == false) { // checking to make sure that the heap has been initialized
				printf("Error: heap not initialized\n");
			}
			else {
				printHeap(myHeap); // printing the heap
			}
			break;
		}

		case 'I': { // inserting an element into the heap with the value i
			printf("COMMAND: %c %d %d\n", c, f, i);
			if (initialized == false) { // checking to make sure that the heap has been initialized
				printf("Error: heap not initialized\n");
			}
			else if (f != 1 && f != 2) { //checking to make sure that the flag value is valid
				printf("Error: invalid flag value\n");
			}
			else {
				Insert(myHeap, f, i); // inserting the element into the heap
			}
			break;
		}

		case 'D': { // deleting the max element in the heap
			printf("COMMAND: %c %d\n", c, f);
			if (initialized == false) { // checking to make sure that the heap is initialized
				printf("Error: heap not initialized\n");
			}
			else if (myHeap->size == 0) { // checking to make sure that the heap is not empty
				printf("Error: heap empty\n");
			}
			else if (f != 1 && f != 2) { // checking to make sure that the flag value is valid
				printf("Error: invalid flag value\n");
			}
			else {
				printf("Deleted max = %d\n", DeleteMax(myHeap, f).key); // deleting the max and outputting
			}
			break;
		}

		case 'K': { // increasing the key of element i to value v
			printf("COMMAND: %c %d %d %d\n", c, f, i, v);
			if (initialized == false) { // checking to make sure that the heap has been initialized
				printf("Error: heap not initialized\n");
			}
			else if (f != 1 && f != 2) { // checking to make sure that the flag value is valid
				printf("Error: invalid flag value\n");
			}
			else if ((i < 1) || (i > myHeap->size)) { // checking to make sure that the heap index is valid
				printf("Error: invalid index\n");
			}
			else if (v < myHeap->H[i].key) { // ensuring that the new key is larger than current key
				printf("Error: new key is smaller than current key\n");
			}
			else {
				IncreaseKey(myHeap, f, i, v); // increasing the key of index i to v
			}
			break;
		}

		default: break;
		}
	}
	exit(0);
}