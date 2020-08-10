// Developer: John Cody
// Date: 03/16/2020
// Class: CSE 310 @ ASU
// Taught by: Guoliang Xue
// Project Name: P01

#pragma once // done so that this file is only ever included once in other files

#include "heap.h" // including heap.h so that Element is recognized as a data type

// function prototypes for util.cpp
int nextCommand(int* i, int* v, int* f); 
// reads from the input stream until it gathers a command

int fileReader(Element* (&A)); 
// reads from a file to connect the given pointer to an element array that it generates 
// and returns the size of the array as an int