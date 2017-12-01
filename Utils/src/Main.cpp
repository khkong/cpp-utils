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
    char* a = test.at(2);
    cout << a << endl;

    string app = "천재";
    const char* bbb = app.data();
    cout << bbb << endl;
    test.append(app);
    cout << test.c_str() << endl;
    test += "입니닷";
    cout << test.substr(2, 8).c_str() << endl;

    char *test_2 = new char[10];
    memset(test_2, -1, 10);
    test_2[0] = 'a';
    test_2[1] = 'b';
    test_2[2] = '\0';
    const char* test_3 = test_2;

    cout << test_3 << endl;
}
