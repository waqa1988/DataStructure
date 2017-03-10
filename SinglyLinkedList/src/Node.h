/*
 * Node.h
 *
 *  Created on: 2017-03-10
 *      Author: Administrator
 */

#ifndef NODE_H_
#define NODE_H_

#include <stddef.h>

class Node {
public:
	int data;
	Node * next;

	Node() : data(0), next(NULL) {

	}

	Node(int d) : data(d), next(NULL) {

	}

	~Node() {

	}
};

#endif /* NODE_H_ */
