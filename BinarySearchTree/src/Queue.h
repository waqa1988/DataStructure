/*
 * Queue.h
 *
 *  Created on: 2017-03-13
 *      Author: Davi
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <queue>

using namespace std;

template<typename T>
class Queue : public queue<T> {

	T dequeue() {
		T tmp = front();
		queue<T>::pop();
		return tmp;
	}

	void equeue(const T &el) {
		push(el);
	}

};


#endif /* QUEUE_H_ */
