#ifndef LIST_H
#define LIST_H

template<class item>
class list_iterator;

template<class item>
class list {
public:
    friend class list_iterator<item>;
    list();
    list(const int&);
    list(const list&);
    ~list();
    list& operator=(const list&);
    bool Empty() const;
    int Length() const;
    void Insert(const item&, const int&);
    void Append(const item&);
    void Delete(const int&);
    item& Element(const int&) const;
private:
    item* element;
    int size;
    int last;
};

template<class item>
class list_iterator {
public:
    list_iterator(const list<item>&);
    void Start();
    bool Valid() const;
    void Advance();
    item& Current() const;
    void Add(const item&);
    void Remove();
private:
    const list<item>* list_ptr;
    int current;
};

#include "list.cpp"

#endif