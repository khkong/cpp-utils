/*
 * QucikSort.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#include "QucikSort.h"

QucikSort::QucikSort() {
}

QucikSort::~QucikSort() {
}

void QucikSort::sort(vector<int>& vec, int left, int right) {
    int pivot = vec[(left + right) >> 1];
    int i = left;
    int j = right;
    do {
        while (vec[i] < pivot)
            i++;
        while (vec[j] > pivot)
            j--;
        if (i <= j) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        sort(vec, left, j);
    if (right > i)
        sort(vec, i, right);
}
