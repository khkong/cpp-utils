/*
 * MinHeap_test.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#include "MinHeap.h"

void MinHeap::TEST() {
    Heap* heap = new MinHeap();
    int arr[] = { 4, 2, 5, 3, 1 };
    int size = sizeof(arr) / sizeof(int);

    cout << "input.." << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
        heap->addItem(arr[i]);
    }

    delete heap;
}
