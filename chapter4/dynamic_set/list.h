#ifndef LIST_H
#define LIST_H

template<class item>
class list {
public:
    list();
    list(const int&);
    list(const list&);
    list& operator=(const list&);
    inline bool Empty() const;
    inline int Length() const;
    void Insert(const item&, const int&);
    void Append(const item&);
    void Delete(const int&);
    inline item& Element(const int&) const;
private:
    item* element;
    int size;
    int last;
};

#include "list.cpp"

#endif