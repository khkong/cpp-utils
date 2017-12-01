/*
 * Sort.h
 *
 *  Created on: 2017. 11. 30.
 *      Author: khkong
 */

#ifndef TEMPLATE_LIB_TEST_HEAPSORT_H_
#define TEMPLATE_LIB_TEST_HEAPSORT_H_
#include <vector>

#include "heap.h"

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

void quick_sort(vector<int>& vec, int left, int right) {
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
        quick_sort(vec, left, j);
    if (right > i)
        quick_sort(vec, i, right);
}

template<typename _AccessIterator, typename _Compare> //
void quick_sort(_AccessIterator& __first, _AccessIterator& __last, _Compare &__cmp) {

}



#endif /* TEMPLATE_LIB_TEST_HEAPSORT_H_ */
