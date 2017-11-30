/*
 * HeapTmp.h
 *
 *  Created on: 2017. 11. 30.
 *      Author: khkong
 */

#ifndef TEMPLATE_LIB_HEAP_HEAP_H_
#define TEMPLATE_LIB_HEAP_HEAP_H_

#include <iostream>
#include <cstring>
#include "Define.h"

using namespace std;

template<typename _Tp>
class Heap {
private/*data member*/:
    _Tp *__arr;
    int __arr_size;
    int __arr_rear;

public/*method func*/:
    Heap() {
        this->__arr = new _Tp[DEF_SIZE];
        this->__arr_size = DEF_SIZE;
        this->__arr_rear = -1;
    }
    Heap(int size) {
        this->__arr = new _Tp[size];
        this->__arr_size = size;
        this->__arr_rear = -1;
    }

    ~Heap() {
        delete[] __arr;
    }

    template<typename _Compare>
    void add(_Tp __t, _Compare &__cmp) {
        if (__arr_rear + 1 >= __arr_size)
            resize();
        __arr[++__arr_rear] = __t;
        addReconstruction(__arr_rear, __cmp);
    }

    template<typename _Compare>
    bool remove(_Compare &__cmp) {
        if (__arr_rear <= EMPTY)
            return false;
        __arr[0] = __arr[__arr_rear--];
        removeReconstruction(0, __arr_rear, __cmp);
        return true;
    }

    template<typename _Compare>
    _Tp pop(_Compare &__cmp) {
        if (__arr_rear <= EMPTY)
            return (_Tp) NULL;
        _Tp item = __arr[0];
        remove(__cmp);
        return item;
    }

    _Tp peek() {
        if (__arr_rear <= EMPTY)
            return (_Tp) NULL;
        return __arr[0];
    }

    void clear() {
        __arr_rear = -1;
        resize(DEF_SIZE);
    }

    void resize(int newSize) {
        _Tp* __newArr = new _Tp[newSize];
        memcpy(__newArr, __arr, size * sizeof(int));
        size = newSize;
        delete[] __arr;
        __arr = __newArr;
    }

    template<typename _Compare>
    void sort(_Compare &__cmp) {
        for (int i = __arr_rear; i > EMPTY; i--) {
            _Tp tmp = __arr[0];
            __arr[0] = __arr[i - 1];
            __arr[i - 1] = tmp;
            removeReconstruction(0, i - 1, __cmp);
        }
    }

    int size() {
        return __arr_rear + 1;
    }

    void print() {
        cout << "__arr : ";
        for (int i = 0; i <= __arr_rear; i++) {
            cout << __arr[i];
            cout << " ";
        }
        cout << endl;
    }

private/*method func*/:
    void resize() {
        size_t newSize = __arr_size << 1;
        _Tp* __newArr = new _Tp[newSize];
        memcpy(__newArr, __arr, __arr_size * sizeof(int));
        __arr_size = newSize;
        delete[] __arr;
        __arr = __newArr;
    }

    template<typename _Compare>
    void addReconstruction(int idx, _Compare &__cmp) {
        if (idx == 0)
            return;
        int parentsNode = (idx - 1) >> 1;
        _Tp t = __arr[idx];

        if (__cmp(t, __arr[parentsNode])) {
            int tmp = __arr[parentsNode];
            __arr[parentsNode] = t;
            __arr[idx] = tmp;
            addReconstruction(parentsNode, __cmp);
        }
    }

    template<typename _Compare>
    void removeReconstruction(int idx, int limit, _Compare &__cmp) {
        int childNode_l = (idx << 1) + 1;
        int childNode_r = childNode_l + 1;
        int bestChild;

        if (limit <= childNode_l)
            return;
        else if (limit <= childNode_r)
            bestChild = childNode_l;
        else if (__cmp(__arr[childNode_l], __arr[childNode_r]))
            bestChild = childNode_l;
        else
            bestChild = childNode_r;

        if (__cmp(__arr[bestChild], __arr[idx])) {
            int tmp = __arr[bestChild];
            __arr[bestChild] = __arr[idx];
            __arr[idx] = tmp;
            removeReconstruction(bestChild, __cmp);
        }
    }

};

#endif /* TEMPLATE_LIB_HEAP_HEAP_H_ */
