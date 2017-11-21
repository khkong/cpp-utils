/*
 * MinHeap.h
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#ifndef MinHeap_H_
#define MinHeap_H_
#include <iostream>
#include <vector>
#include "Heap.h"

using namespace std;

class MinHeap: public Heap {
public:
    MinHeap();
    virtual ~MinHeap();

    void addReconstruction(int idx);
    void deleteReconstruction(int idx, int limit);
    void TEST();
};

#endif /* MinHeap_H_ */
