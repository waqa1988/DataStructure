/*
 * InsertionSort.h
 *
 * 优点：只在有需要时才会对数组进行排序，如果数组已经排好序了，就不会再对数据进行移动
 * 缺点：
 * （1）可能会忽视元素可能已在合适位置【5,2,3,8,1】中的数字2和数字3
 * （2）如果插入数据项，所有比插入元素大的元素必须移动
 *
 * 算法复杂度 ：O（n2）
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
