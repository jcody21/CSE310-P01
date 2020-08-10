// Developer: John Cody
// Date: 03/16/2020
// Class: CSE 310 @ ASU
// Taught by: Guoliang Xue
// Project Name: P01

#pragma once // done so that this file is only ever included once in other files

struct Element { // the Element data structure the heap is based on
	int key;
};

struct Heap { // the data structure used throughout the project
	int capacity;
	int size;
	struct Element* H;
};

int Parent(int i);
// takes in an index and returns the index of the parent - no checking

int Left(int i);
// takes in an index and returns where the left child should be - no checking

int Right(int i);
// takes in an index and returns where the right child should be - no checking

void Heapify(Heap* A, int i);
// moves the value at index i down the tree until it is not larger than both of it's children

Heap* Initialize(int n);
// creates and returns an empty heap of capacity n

void BuildHeap(Heap* heap, Element* A, int n);
// loops through Element array A and writes the values of the keys into the Heap heap. 

void Insert(Heap* heap, int flag, int k); 
// inserts a new element into the Heap heap, with a value of k
// the heap is not large enough to support another element, then
// the heap is grown to the next power of 2

Element DeleteMax(Heap* heap, int flag); 
// deletes the max element of the heap, and then reorders the heap appropriately

void IncreaseKey(Heap* heap, int flag, int index, int value);
// increases the key of the element at index to value and then reorders
// the heap appropriately

void printHeap(Heap* heap);
// takes in a heap pointer and prints the size, the 
// capacity, and the key values of the elements