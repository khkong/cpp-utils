/*
 * utf8string.h
 *
 *  Created on: 2017. 12. 1.
 *      Author: khkong
 */

#ifndef LIB_SMART_STRING_H_
#define LIB_SMART_STRING_H_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
class smart_string: public string {
private:
    char* mBuffer;

public:
    smart_string();
    smart_string(const char* str);
    smart_string(const string& str);
    ~smart_string();

    smart_string& operator =(const char* str);
    smart_string& operator =(const string& str);
    smart_string operator*(const char* str) const;
    smart_string operator*(const string& str) const;
    smart_string& operator +=(const char* str);
    smart_string& operator +=(const string& str);

    int length() const;
    char* at(const int index) const;
    void append(const char* str);
    void append(const string& str);
    smart_string& substr(int start, int end);
    int compareTo(smart_string& s1, smart_string& s2);

    inline const char* c_str() {
        return mBuffer;
    }
};

#endif /* LIB_SMART_STRING_H_ */
