#include "dynamic_list.h"
#include <cassert>

template<class item>
dynamic_list_iterator<item>::dynamic_list_iterator(dynamic_list<item>& list) : list_ptr(&list), current(-1) {}

template<class item>
void dynamic_list_iterator<item>::start() { current = 0; }

template<class item>
bool dynamic_list_iterator<item>::valid() const { return 0 <= current && current < list_ptr->length(); }

template<class item>
void dynamic_list_iterator<item>::advance() { current++; }

template<class item>
item& dynamic_list_iterator<item>::get_current() const {
    assert(valid());    
    return list_ptr->element[current];
}

template<class item>
void dynamic_list_iterator<item>::add(const item& element) {
    list_ptr->insert(element, current);
    current++;
}

template<class item>
void dynamic_list_iterator<item>::remove() {
    assert(valid());
    list_ptr->erase(current);
}

template<class item>
dynamic_list<item>::dynamic_list() : element(nullptr), size(0), last(-1) {}

template<class item>
dynamic_list<item>::dynamic_list(const int& size) {
    this->element = new item[size];
    assert(element != nullptr);
    this->size = size;
    this->last = -1;
}

template<class item>
dynamic_list<item>::dynamic_list(const dynamic_list& list) {
    this->element = new item[list.size];
    assert(element != nullptr);
    this->size = list.size;
    this->last = list.last;
    for (int i = 0; i <= this->last; i++) {
        this->element[i] = list.element[i];
    }
}

template<class item>
dynamic_list<item>::~dynamic_list() { delete[] element; }

template<class item>
dynamic_list<item>& dynamic_list<item>::operator=(const dynamic_list& list) {
    if (this != &list) {
        if (this->size != list.size) {
            delete[] element;
            element = new item[list.size];
            this->size = list.size;
        }
        this->last = list.last;
        for (int i = 0; i <= this->last; i++) {
            this->element[i] = list.element[i];
        }
    }
    return *this;
}

template<class item>
bool dynamic_list<item>::empty() const { return last == -1; }

template<class item>
int dynamic_list<item>::length() const { return last + 1; }

template<class item>
void dynamic_list<item>::insert(const item& element, const int& index) {
    assert(index >= 0 && index <= last + 1);
    if (length() == size) {
        int new_size = size == 0 ? 1 : 2 * size;
        item* new_element = new item[new_size];
        assert(new_element != nullptr);
        for (int i = 0; i < index; i++) {
            new_element[i] = this->element[i];
        }
        new_element[index] = element;
        for (int i = index; i <= last; i++) {
            new_element[i + 1] = this->element[i];
        }
        delete[] this->element;
        this->element = new_element;
        size = new_size;
    } else {
        for (int i = last; i >= index; i--) {
            this->element[i + 1] = this->element[i];
        }
        this->element[index] = element;
    }
    last++;
}

template<class item>
void dynamic_list<item>::append(const item& element) {
    insert(element, last + 1);
}

template<class item>
void dynamic_list<item>::erase(const int& index) {
    assert(index >= 0 && index <= last);
    for (int i = index; i < last; i++) {
        element[i] = element[i + 1];
    }
    last--;
}

template<class item>
item& dynamic_list<item>::getElement(const int& index) const {
    assert(index >= 0 && index <= last);
    return element[index];
}