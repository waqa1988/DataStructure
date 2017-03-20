//============================================================================
// Name        : Sort.cpp
// Author      : Davi
// Version     :
// Copyright   : no copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "InsertionSort.h"
#include "SelectionSort.h"

using namespace std;

int main() {
	int array[] = {5, 2, 3, 8, 1};

	// Insertion sort
	// InsertionSort<int>::sort(array, 5);

	// Selection Sort
	SelectionSort<int>::sort(array, 5);

	for (int i = 0; i < 5; i++) {
		cout << array[i] << " ,";
	}
	return 0;
}
