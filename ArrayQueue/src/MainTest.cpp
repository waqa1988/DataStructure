//============================================================================
// Name        : MainTest.cpp
// Author      : Davi
// Version     :
// Copyright   : copy right
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "ArrayQueue.h"
#include <iostream>
using namespace std;

int main() {
	ArrayQueue<int> *queue = new ArrayQueue<int>();
	queue->enqueue(1);
	queue->enqueue(2);
	queue->enqueue(3);

	queue->dequeue();

	queue->showAllData();
	return 0;
}
