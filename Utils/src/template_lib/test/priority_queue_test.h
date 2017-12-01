/*
 * HeapTmp_test.cpp
 *
 *  Created on: 2017. 11. 30.
 *      Author: khkong
 */
#include "../priority_queue.h"

#include <iostream>
#include <string>
#include <stdlib.h>

#include "../compare.h"

using namespace std;
class PriorityQueue_test {
public:
    void TEST() {
        PriorityQueue<int> integer_max_heap;
        for (int i = 0; i < 50; i++) {
            integer_max_heap.add(i, integer_max);
            int check = integer_max_heap.peek();
            if (check != i) {
                cout << "integer_max_heap, addReconstruction fail." << endl;
                cout << i << endl;
                cout << check << endl;
                exit(EXIT_FAILURE);
            }
            if (i + 1 != integer_max_heap.size()) {
                cout << "integer_max_heap, size fail." << endl;
                cout << integer_max_heap.size() << endl;
                exit(EXIT_FAILURE);
            }
        }

        PriorityQueue<int> integer_min_heap;
        for (int i = 0; i < 50; i++) {
            int tmp = 50 - i;
            integer_min_heap.add(tmp, integer_min);
            int check = integer_min_heap.peek();
            if (check != tmp) {
                cout << "integer_min_heap, addReconstruction fail." << endl;
                cout << check << endl;
                exit(EXIT_FAILURE);
            }

            if (i + 1 != integer_min_heap.size()) {
                cout << "integer_min_heap, size fail." << endl;
                cout << integer_min_heap.size() << endl;
                exit(EXIT_FAILURE);
            }
        }
    }
};

