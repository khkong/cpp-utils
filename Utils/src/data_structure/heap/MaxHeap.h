/*
 * MaxHeap.h
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#ifndef MAXMaxHeap_H_
#define MAXMaxHeap_H_
#include <iostream>
#include <vector>
#include "Heap.h"

using namespace std;

class MaxHeap: public Heap {
public:
    MaxHeap();
    virtual ~MaxHeap();

    void addReconstruction(int idx);
    void deleteReconstruction(int idx, int limit);
    void TEST();
};

#endif /* MAXMaxHeap_H_ */
