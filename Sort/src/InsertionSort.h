/*
 * InsertionSort.h
 *
 *  Created on: 2017-3-20
 *      Author: Davi
 */

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

template<typename T>
class InsertionSort {
public:
	InsertionSort(){};
	virtual ~InsertionSort(){};

	static void sort(T data[], int n);
};

template<typename T>
void InsertionSort<T>::sort(T data[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		T temp = data[i];

		for ( ; j > 0 && temp < data[i - 1]; j--) {
			data[j] = data[j - 1];
		}

		data[j] = temp;
	}
}

#endif /* INSERTIONSORT_H_ */
