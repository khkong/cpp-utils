/*
 * Heap.h
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#ifndef HEAP_HEAP_H_
#define HEAP_HEAP_H_
#include <iostream>
#include <vector>

using namespace std;

class Heap {
protected:
    vector<int> mData;

public:
    Heap();
    virtual ~Heap();

    void addItem(int n);
    void deleteItem();
    int peek();
    int pop();
    void clear();

    virtual void addReconstruction(int idx)=0;
    virtual void deleteReconstruction(int idx, int limit) =0;
    virtual void TEST()=0;
};

#endif /* HEAP_HEAP_H_ */
