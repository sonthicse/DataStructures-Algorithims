#ifndef LISH_H
#define LISH_H

#include <cassert>

template <class item>
class list {
public:
    static const int MAX_SIZE = 50;
    list();
    bool empty() const;
    int length() const;
    void insert(const item&, const int&);
    void append(const item&);
    void erase(const int&);
    item get(const int&) const;
    void start();
    bool valid() const;
    void advanced();
    item getCurrent() const;
    void add(const item&);
    void remove();
private:
    item element[MAX_SIZE];
    int last;
    int current;
};

#include "list.cpp"

#endif