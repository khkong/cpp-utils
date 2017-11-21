/*
 * QucikSort.h
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */

#ifndef ALGORITHM_QUICK_SORT_QUCIKSORT_H_
#define ALGORITHM_QUICK_SORT_QUCIKSORT_H_
#include <iostream>
#include <vector>

using namespace std;

class QucikSort {
public:
    QucikSort();
    virtual ~QucikSort();
    void sort(vector<int>& vec, int left, int right);
    void TEST();
};

#endif /* ALGORITHM_QUICK_SORT_QUCIKSORT_H_ */
