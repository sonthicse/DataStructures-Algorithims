#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

template<class item>
class dynamic_list;

template<class item>
class dynamic_list_iterator {
public:
    dynamic_list_iterator(dynamic_list<item>&);
    void start();
    bool valid() const;
    void advance();
    item& get_current() const;
    void add(const item&);
    void remove();
private:
    dynamic_list<item>* list_ptr;
    int current;
};

template<class item>
class dynamic_list {
public:
    friend class dynamic_list_iterator<item>;
    dynamic_list();
    dynamic_list(const int&);
    dynamic_list(const dynamic_list&);
    ~dynamic_list();
    dynamic_list& operator=(const dynamic_list&);
    bool empty() const;
    int length() const;
    void insert(const item&, const int&);
    void append(const item&);
    void erase(const int&);
    item& getElement(const int&) const;
private:
    item* element;
    int size;
    int last;
};

#endif