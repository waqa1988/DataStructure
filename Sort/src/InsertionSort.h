/*
 * InsertionSort.h
 *
 * 插入排序首先考虑数组data的前两个元素，即data[0]和data[1]。如果他们次序颠倒了，就交互他们。
 * 然后考虑第三个元素data[2], 将其插入到合适的位置上。如果data[2]同时小于data[0]和data[1],
 * 那么data[0]和data[1]都要移动一个位置，data[0]放在位置1上，data[1]放置在位置2上，而data[2]放在位置0上。
 * 如果data[2]小于data[1]而不小于data[0]，那么只需要把data[1]移动到位置2上，由data[2]占据它的位置。最后，
 * 如果data[2]不小于前两个元素，它将保留在当前位置上。
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
