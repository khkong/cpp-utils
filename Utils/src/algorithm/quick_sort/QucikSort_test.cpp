/*
 * QucikSort_test.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#include "QucikSort.h"

void QucikSort::TEST() {
    int arr[] = { 4, 2, 5, 3, 1 };
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    QucikSort* sort = new QucikSort();
    sort->sort(vec, 0, vec.size());

    int size = vec.size();
    for (int i = 0; i < size; i++) {
        cout << vec[i] << endl;
    }
    delete sort;
}
