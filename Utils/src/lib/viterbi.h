/*
 * viterbi.h
 *
 *  Created on: 2017. 12. 1.
 *      Author: khkong
 */

#ifndef LIB_VITERBI_H_
#define LIB_VITERBI_H_
#include <iostream>
#include <vector>

using namespace std;

template<typename _Nodep>
class viterbi {
private:
    vector<_Nodep*> __vec_cache;

public:
    viterbi();
    virtual ~viterbi();

    void node_connection(int key, _Nodep& __node_first, _Nodep& __node_last) {
        _Nodep* __cache_data = __vec_cache[key];
        if (&__node_first == &__node_last)
            return;

        for (_Nodep* __i = &__node_first; __i <= &__node_last + 1; __i++) {

        }
    }

    void node_push(int key, _Nodep* __node) {

    }

private:
    template<typename _CostFunc>
    void best_node(_Nodep* __prevNode, _Nodep __node, _CostFunc __costFunc);
};

#endif /* LIB_VITERBI_H_ */
