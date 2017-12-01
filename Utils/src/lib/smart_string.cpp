/*
 * utf8string.cpp
 *
 *  Created on: 2017. 12. 1.
 *      Author: khkong
 */

#include "../lib/smart_string.h"
#include <iostream>

smart_string::smart_string() {
    mBuffer = new char[1];
    mBuffer[0] = '\0';
}

smart_string::smart_string(const char* str) {
    int len = strlen(str);
    mBuffer = new char[len + 1];
    memcpy(mBuffer, str, len * sizeof(char));
    mBuffer[len] = '\0';
}

smart_string::smart_string(const string &str) {
    const char* tmp = str.c_str();
    int len = strlen(tmp);
    mBuffer = new char[len + 1];
    memcpy(mBuffer, tmp, len * sizeof(char));
    mBuffer[len] = '\0';
}

smart_string::~smart_string() {
    delete[] mBuffer;
}

smart_string& smart_string::operator =(const char* str) {
    int len = strlen(str);
    char* newBuffer = new char[len + 1];
    memcpy(newBuffer, str, len * sizeof(char));
    newBuffer[len] = '\0';
    char* tmp = mBuffer;
    mBuffer = newBuffer;
    delete[] tmp;
    return *this;
}

smart_string& smart_string::operator =(const string& str) {
    const char* char_arr = str.c_str();
    return operator =(char_arr);
}

smart_string& smart_string::operator +=(const char* str) {
    append(str);
    return *this;
}

smart_string& smart_string::operator +=(const string& str) {
    append(str.c_str());
    return *this;
}

smart_string smart_string::operator*(const char* str) const {
    return smart_string(str);
}

smart_string smart_string::operator*(const string& str) const {
    return smart_string(str);
}

void smart_string::append(const char* str) {
    char* tmp = strcat(mBuffer, str);
    size_t addSize = strlen(str);
    size_t originSize = strlen(mBuffer);
    char* newArr = new char[addSize + originSize + 1];
    memcpy(newArr, tmp, strlen(tmp) * sizeof(char));
    delete[] mBuffer;
    mBuffer = newArr;
}

void smart_string::append(const string& str) {
    append(str.c_str());
}

int smart_string::length() const {
    unsigned int ret_len = 0;
    int str_len = strlen(mBuffer);
    int index = 0;
    while (index < str_len) {
        if ((mBuffer[index] & 0xF0) == 0xF0) {
            index += 4;
        } else if ((mBuffer[index] & 0xE0) == 0xE0) {
            index += 3;
        } else if ((mBuffer[index] & 0xC0) == 0xC0) {
            index += 2;
        } else {
            index += 1;
        }
        ret_len++;
    }
    return ret_len;
}

char* smart_string::at(int index) const {
    int i = 0, j = 0, k = 0;
    for (; i <= index; i++) {
        if ((mBuffer[j] & 0xF0) == 0xF0) {
            j += 4;
            k = 4;
        } else if ((mBuffer[j] & 0xE0) == 0xE0) {
            j += 3;
            k = 3;
        } else if ((mBuffer[j] & 0xC0) == 0xC0) {
            j += 2;
            k = 2;
        } else {
            j += 1;
            k = 1;
        }
    }
    char* ret_str = new char[k + 1];
    strncpy(ret_str, &mBuffer[j - k], k);
    ret_str[k] = '\0';
    return ret_str;
}

smart_string& smart_string::substr(int start, int end) {
    int i, j, k = 0, l = 0;
    for (i = 0; i < start; i++) {
        if ((mBuffer[k] & 0xF0) == 0xF0) {
            k += 4;
        } else if ((mBuffer[k] & 0xE0) == 0xE0) {
            k += 3;
        } else if ((mBuffer[k] & 0xC0) == 0xC0) {
            k += 2;
        } else {
            k += 1;
        }
    }
    l = k;
    for (j = i; j < end; j++) {
        if ((mBuffer[l] & 0xF0) == 0xF0) {
            l += 4;
        } else if ((mBuffer[l] & 0xE0) == 0xE0) {
            l += 3;
        } else if ((mBuffer[l] & 0xC0) == 0xC0) {
            l += 2;
        } else {
            l += 1;
        }
    }

    char *newArr = new char[l - k + 1];
//    memcpy(newArr, &mBuffer[k], (l - k + 1) * sizeof(char));
    strncpy(newArr, &mBuffer[k], (l - k + 1) * sizeof(char));
    newArr[l - k + 1] = '\0';
    char* tmp = mBuffer;
    mBuffer = newArr;
    delete[] tmp;
    return *this;
}

int smart_string::compareTo(smart_string& s1, smart_string& s2) {
    string a = s1.c_str();
    string b = s2.c_str();
    return a.compare(b);
}

