// Developer: John Cody
// Date: 03/16/2020
// Class: CSE 310 @ ASU
// Taught by: Guoliang Xue
// Project Name: P01

#include "util.h" // "heap.h" is not included again as it is already within "util.h"
#include <stdio.h> // used to get input from the user
#include <fstream> // used to get input from a file
using namespace std;


// reads from the input stream until it gathers a command
int nextCommand(int* f, int* i, int* v) {

	char c; // declaring a variable to use for input

	while (1) {
		scanf("%c", &c); // taking in new input
		if (c == ' ' || c == '\t' || c == '\n') { // discarding whitespace
			continue; }

		if (c == 'S' || c == 's') { // Ends the program
			c = 'S'; // setting a definte value for output
			break; }
		
		if (c == 'C' || c == 'c') { // builds an empty heap the size of f
			c = 'C';
			scanf("%d", f); // getting the size
			break; }
		
		if (c == 'R' || c == 'r') { // reads in an array from a file and then puts it in a heap
			c = 'R';
			break; }
		
		if (c == 'W' || c == 'w') { // prints the current heap info to the screen
			c = 'W';
			break; }
		
		if (c == 'I' || c == 'i') { // inserts a new element with key i into the heap
			c = 'I';
			scanf("%d", f); // determines if we print info
			scanf("%d", i); // key value
			break; }
		
		if (c == 'D' || c == 'd') { // deletes the maximum element from the heap
			c = 'D';
			scanf("%d", f); // determines if we print info
			break; }
		
		if (c == 'K' || c == 'k') { // increases the key of element i to v, f determines if we print info
			c = 'K';
			scanf("%d", f); // determines if we print info
			scanf("%d", i); // index
			scanf("%d", v); // key
			break; }

		else {
			c = '\0'; // getting rid of old input
			continue;
		}
		
		//printf("Invalid Command\n"); 
		// "Invalid Command\n" never showed up in any of the tests, so I have omitted it as 
		// I was uncertain that it needed to be in the program. 
	}
	return c;
}


// reads from a file to connect the given pointer to an element array that it generates 
// and returns the size of the array as an int
int fileReader(Element *(&A)) { 
	
	ifstream myfile; // creating an ifstream file
	myfile.open("HEAPinput.txt"); // opening the file to be read

	if (!myfile.is_open()) { // checking to make sure the file opened
		printf("The file did not open properly.\n");
		printf("The program is now qutting.\n");
		exit(0);
	}

	int input; // declaring a variable to use for input
	myfile >> input; // the first input will tell us the size of the array

	// this input is not sanitized as we should be able to trust this file
	// if we cannot, then this code needs that then

	int capacity = input; // capacity will be returned, whereas input will change
	A = new Element[capacity+1]; // declared 1 larger so that the array can start at 1

	int i = 1; // increment variable
	while (myfile >> input) { // looping through the file until we reach the end of the file
		A[i].key = input; // saving the value of input into each key of the element array
		i++;
	}

	myfile.close(); // closing the file now that we are finished

	return capacity;
}