#ifndef SET_H
#define SET_H

#include "list.h"
#include <stdexcept>

template<class item>
class set : public list<item> {
public:
    typedef item KeyType;
    set() : list<item>() {}
    set(const int& size) : list<item>(size) {}
    void setInsert(const item&);
    void setDelete(const KeyType&);
    bool Search(const KeyType&) const;
    const item& max() const;
    const item& min() const;
};

#include "set.cpp"

#endif