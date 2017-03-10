/*
 * SinglyLinkedList.h
 *
 *  Created on: 2017-03-10
 *      Author: Administrator
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include "Node.h"

class SinglyLinkedList {
public:
	SinglyLinkedList();
	virtual ~SinglyLinkedList();

	void addToHead(int data);
	void addToTail(int data);

	int deleteFromHead();
	int deleteFromTail();

	void deleteNode(int data);

	bool isInList(int data);

	bool isEmpty();

	void showAllNode();

private:
	Node * head;
	Node * tail;
};


#endif /* SINGLYLINKEDLIST_H_ */
