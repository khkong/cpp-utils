/*
 * TestUtils.h
 *
 *  Created on: 2017. 11. 30.
 *      Author: khkong
 */

#ifndef TEMPLATE_LIB_DEFINE_H_
#define TEMPLATE_LIB_DEFINE_H_
#include <string>

static const int EMPTY = -1;
static const int DEF_SIZE = 10;

struct IntegerMax {
    bool operator()(int a, int b) const {
        return a > b;
    }
} integer_max;

struct IntegerMin {
    bool operator()(int a, int b) const {
        return a < b;
    }
} integer_min;

struct StringMax {
    bool operator()(std::string a, std::string b) const {
        return a.compare(b);
    }
} string_max;

struct StringMin {
    bool operator()(std::string a, std::string b) const {
        return a.compare(b);
    }
} string_min;

#endif /* TEMPLATE_LIB_DEFINE_H_ */
