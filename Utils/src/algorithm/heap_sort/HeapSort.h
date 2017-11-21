/*
 * HeapSort.h
 *
 *  Created on: 2017. 11. 21.
 *      Author: khkong
 */

#ifndef ALGORITHM_HEAP_SORT_HEAPSORT_H_
#define ALGORITHM_HEAP_SORT_HEAPSORT_H_
#include "../../data_structure/heap/Heap.h"

class HeapSort: public Heap {
public:
    HeapSort();
    virtual ~HeapSort();
    void sort(vector<int>& sorted);
};

#endif /* ALGORITHM_HEAP_SORT_HEAPSORT_H_ */
