/*
 * Main.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */
#include "data_structure/heap/MaxHeap.h"
#include "data_structure/heap/MinHeap.h"
#include "algorithm/quick_sort/QucikSort.h"

int main(int argc, char **argv) {
    cout << "최대 힙" << endl;
    Heap* maxHeap = new MaxHeap();
    maxHeap->TEST();
    cout << "최소 힙" << endl;
    Heap* minHeap = new MinHeap();
    minHeap->TEST();
    cout << "퀵 정렬" << endl;
    QucikSort* sort = new QucikSort();
    sort->TEST();

    delete maxHeap;
    delete minHeap;
    delete sort;
}
