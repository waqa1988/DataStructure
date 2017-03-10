/*
 * ArrayQueue.h
 *
 *  Created on: 2017-03-10
 *      Author: Administrator
 */

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

const int LEN = 100;
#include <iostream>
using namespace std;


template<class T>
class ArrayQueue {
public:
	ArrayQueue();
	virtual ~ArrayQueue();

	bool isFull();

	void enqueue(T);

	T dequeue();

	void showAllData();

private:
	T array[LEN];
	int front, rear;
};

template<class T>
ArrayQueue<T>::ArrayQueue() : front(-1), rear(-1) {

}

template<class T>
ArrayQueue<T>::~ArrayQueue() {
}

template<class T>
bool ArrayQueue<T>::isFull() {
	if ((front == 0 && rear == LEN - 1) || rear == front - 1) {
		return true;
	}
	return false;
}

template<class T>
void ArrayQueue<T>::enqueue(T data) {
	if (!isFull()) {
		if (rear == -1 || rear == LEN - 1) {
			array[0] = data;
			rear = 0;
			if (front == -1) {
				front = 0;
			}
		} else {
			array[++rear] = data;
		}
	}
}

template<typename T>
T ArrayQueue<T>::dequeue() {
	T rslt = array[front];
	if (front == rear) {
		front = -1;
		rear = -1;
	} else if (front == LEN -1) {
		front = 0;
	} else {
		front++;
	}
	return rslt;
}

template<typename T>
void ArrayQueue<T>::showAllData() {
	int p = front;
	while (p != rear) {
		if (p == LEN - 1) {
			p = 0;
			cout << array[p] << ",";
			continue;
		}
		cout << array[p] << ",";
		p++;
	}
	cout << array[rear] << endl;
}

#endif /* ARRAYQUEUE_H_ */
