/*
 * MainTest.cpp
 *
 *  Created on: 2017年3月10日
 *      Author: Administrator
 */
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
	SinglyLinkedList *list = new SinglyLinkedList();
	list->addToTail(1);
	list->addToTail(3);
	list->addToTail(5);

	//list->showAllNode();

	list->addToTail(9);

	//list->showAllNode();

	//cout << list->deleteFromHead();
	//cout << list->deleteFromTail()<<endl;
	//list->deleteNode(5);
	list->showAllNode();
	cout << list->isInList(5);
	return 0;
}


