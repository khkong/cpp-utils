/*
 * PriorityQueue.h
 *
 *  Created on: 2017. 11. 30.
 *      Author: khkong
 */

#ifndef TEMPLATE_LIB_PRIORITY_QUEUE_H_
#define TEMPLATE_LIB_PRIORITY_QUEUE_H_
#include "heap.h"

template<typename _Tp>
class PriorityQueue: public khkong::Heap<_Tp> {
public/*method func*/:
    PriorityQueue() {
        this->__arr = new _Tp[DEF_SIZE];
        this->__arr_size = DEF_SIZE;
        this->__arr_rear = -1;
    }

    PriorityQueue(int size) {
        this->__arr = new _Tp[size];
        this->__arr_size = size;
        this->__arr_rear = -1;
    }

    virtual ~PriorityQueue() {
        delete[] this->__arr;
    }

    template<typename _Compare> _Tp pop(_Compare &__cmp) {
        if (this->__arr_rear <= -1)
            return (_Tp) NULL;
        _Tp item = this->__arr[0];
        remove(__cmp);
        return item;
    }

    _Tp peek() {
        if (this->__arr_rear <= -1)
            return (_Tp) NULL;
        return this->__arr[0];
    }

};

#endif /* TEMPLATE_LIB_PRIORITY_QUEUE_H_ */
