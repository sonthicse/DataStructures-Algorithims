#include "String.h"

String::String() : size(0) {}

String::String(const String& str) {
    size = str.size;
    for (int i = 0; i < size; i++) {
        string[i] = str.string[i];
    }
}

int String::getSize() const { return size; }

char String::get(const int& index) { return string[index - 1]; }

void String::operator=(const String& str) {
    size = str.size;
    for (int i = 0; i < size; i++) {
        string[i] = str.string[i];
    }
}

void String::operator+=(const String& str) {
    for (int i = size; i < size + str.size; i++) {
        string[i] = str.string[i];
    }
    size += str.size;
}

String operator+(const String& str1, const String& str2) {
    String result;
    result += str1;
    result += str2;
    return result;
}

bool operator<(const String& str1, const String& str2) {
    int loop = str1.size < str2.size ? str1.size : str2.size;
    for (int i = 0; i < loop; i++) {
        if (str1.string[i] < str2.string[i])
            return true;
        if (str1.string[i] > str2.string[i])
            return false;
    }
    return str1.size < str2.size;
}

bool operator>(const String& str1, const String& str2) {
    int loop = str1.size < str2.size ? str1.size : str2.size;
    for (int i = 0; i < loop; i++) {
        if (str1.string[i] > str2.string[i])
            return true;
        if (str1.string[i] < str2.string[i])
            return false;
    }
    return str1.size > str2.size;
}

bool operator==(const String& str1, const String& str2) {
    if (str1.size != str2.size)
        return false;
    for (int i = 0; i < str1.size; i++) {
        if (str1.string[i] != str2.string[i])
            return false;
    }
    return true;
}