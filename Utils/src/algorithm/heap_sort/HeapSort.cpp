/*
 * HeapSort.cpp
 *
 *  Created on: 2017. 11. 21.
 *      Author: khkong
 */

#include "HeapSort.h"

HeapSort::HeapSort() {
}

HeapSort::~HeapSort() {
}

void HeapSort::sort(vector<int>& sorted) {
    int size = mData.size();
    for (int i = size; i > 0; i--) {
        int tmp = mData[0];
        mData[0] = mData[i - 1];
        mData[i - 1] = tmp;
        deleteReconstruction(0, i - 1);
    }
    sorted = mData;
}
