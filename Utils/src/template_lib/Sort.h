/*
 * HeapSort.h
 *
 *  Created on: 2017. 11. 30.
 *      Author: khkong
 */

#ifndef TEMPLATE_LIB_TEST_HEAPSORT_H_
#define TEMPLATE_LIB_TEST_HEAPSORT_H_
#include <vector>
#include "../template_lib/Heap.h"

template<typename _AccessIterator, typename _Compare> //
void heap_sort(_AccessIterator& __first, _AccessIterator& __last, _Compare &__cmp) {
    if (&__first == &__last)
        return;

    khkong::Heap<_AccessIterator> heap;
    for (_AccessIterator* __i = &__first; __i <= &__last + 1; __i++)
        heap.add((*__i), __cmp);

    int __arr_size = heap.size();
    _AccessIterator* __new_arr = heap.sortHeap(__cmp);
    memcpy(&__first, __new_arr, __arr_size * sizeof(_AccessIterator));
}

#endif /* TEMPLATE_LIB_TEST_HEAPSORT_H_ */
