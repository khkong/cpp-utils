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
    smart_string(char* str);
    smart_string(const char* str);
    smart_string(string& str);
    smart_string(const string& str);
    ~smart_string();

    smart_string& operator =(char* str);
    smart_string& operator =(const char* str);
    smart_string& operator =(string& str);
    smart_string& operator =(const string& str);
    smart_string operator*(char* str) const;
    smart_string operator*(const char* str) const;
    smart_string operator*(string& str) const;
    smart_string operator*(const string& str) const;

    /**
     * complexity : O(N)
     */
    int length() const;

    /**
     * complexity : O(N)
     */
    char* charAt(int index) const;
    void append(char* str);
    void append(const char* str);
    void append(string& str);
    void append(const string& str);

    inline const char* c_str() {
        return mBuffer;
    }
};

#endif /* LIB_SMART_STRING_H_ */
