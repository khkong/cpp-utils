/*
 * MaxHeap.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#include "MaxHeap.h"

MaxHeap::MaxHeap() {
}

MaxHeap::~MaxHeap() {
}

void MaxHeap::addReconstruction(int idx) {
    if (idx == 0)
        return;
    int parentsNode = (idx - 1) >> 1;
    int n = mData[idx];
    if (n > mData[parentsNode]) {
        int tmp = mData[parentsNode];
        mData[parentsNode] = n;
        mData[idx] = tmp;
        addReconstruction(parentsNode);
    }
}

void MaxHeap::deleteReconstruction(int idx, int limit) {
    int bestChild;
    int childNode_l = idx * 2 + 1;
    int childNode_r = idx * 2 + 2;
    if (limit <= childNode_l)
        return;

    if (limit <= childNode_r)
        bestChild = childNode_l;
    else
        bestChild = mData[childNode_r] > mData[childNode_l] ? childNode_r : childNode_l;

    if (mData[bestChild] > mData[idx]) {
        int tmp = mData[bestChild];
        mData[bestChild] = mData[idx];
        mData[idx] = tmp;
        deleteReconstruction(bestChild, limit);
    }
}
