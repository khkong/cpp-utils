/*
 * Heap.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#include "Heap.h"

Heap::Heap() {
}

Heap::~Heap() {
}

void Heap::addItem(int n) {
    mData.push_back(n);
    addReconstruction(mData.size() - 1);
}

void Heap::deleteItem() {
    int size = mData.size();
    mData[0] = mData[size - 1];
    mData.pop_back();
    deleteReconstruction(0, size - 1);
}

int Heap::peek() {
    return mData[0];
}

int Heap::pop() {
    if (mData.size() == 0)
        return -1;
    int item = mData[0];
    deleteItem();
    return item;
}


void Heap::clear() {
    mData.clear();
}
