/*
 * Main.cpp
 *
 *  Created on: 2017. 11. 20.
 *      Author: khkong
 */
#include <vector>

#include "lib/smart_string.h"
#include "template_lib/test/priority_queue_test.h"

int main(int argc, char **argv) {
    smart_string test = "test";
    cout << test.c_str() << endl;
    test = "공경환";
    cout << test.c_str() << endl;
    test = "공경환+!abs";
    cout << test.length() << endl;
    char* a = test.charAt(2);
    cout << a << endl;
}
