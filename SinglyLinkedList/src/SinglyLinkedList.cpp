//============================================================================
// Name        : SinglyLinkedList.cpp
// Author      : Davi
// Version     :
// Copyright   : copy right
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;


SinglyLinkedList::SinglyLinkedList() : head(NULL), tail(NULL){
	head = new Node(-1);
	head->next = NULL;
	tail = head;
}

SinglyLinkedList::~SinglyLinkedList() {

}

void SinglyLinkedList::addToHead(int data) {
	Node *newNode = new Node(data);

	if (isEmpty()) {
		head->next = newNode;
		tail = head->next;
		tail->next = NULL;
	} else {
		newNode->next = head->next;
		head->next = newNode;
	}
}

void SinglyLinkedList::addToTail(int data) {
	Node *newNode = new Node(data);
	tail->next = newNode;
	tail = tail->next;
	tail->next = NULL;
}

int SinglyLinkedList::deleteFromHead() {
	int rslt = -1;
	if (!isEmpty()) {
		Node * node = head->next;
		head->next = head->next->next;
		rslt = node->data;
		delete node;
		node = NULL;
	}
	return rslt;
}

int SinglyLinkedList::deleteFromTail() {
	int rslt = -1;
	if (!isEmpty()) {
		Node *p = head->next;
		if (p == tail) {
			rslt = tail->data;
			delete p;
			p = NULL;
			tail = head;
			tail->next = NULL;
		} else {
			while (p->next != tail) {
				p = p->next;
			}
			rslt = tail->data;
			delete tail;
			tail = NULL;
			tail = p;
			tail->next = NULL;
		}
	}
	return rslt;
}

void SinglyLinkedList::deleteNode(int data) {
	if (!isEmpty()) {
		Node *p = head->next;

		if (p == tail) {
			deleteFromTail();
		} else {
			while (p->next != NULL) {
				if (p->next->data == data) {
					Node *delNode = p->next;
					p->next = p->next->next;

					delete delNode;
					delNode = NULL;

					break;
				}

				p = p->next;
			}
		}
	}
}

bool SinglyLinkedList::isInList(int data) {
	bool isIn = false;
	Node *p = head->next;
	while (p != NULL) {
		if (p->data == data) {
			isIn = true;
			break;
		}
		p = p->next;
	}
	return isIn;
}

bool SinglyLinkedList::isEmpty() {
	if (head->next == NULL)
		return true;
	else
		return false;
}

void SinglyLinkedList::showAllNode() {
	Node * node = head;
	while (node->next != NULL) {
		cout << node->next->data << ", ";
		node = node->next;
	}
	cout << endl;
}
