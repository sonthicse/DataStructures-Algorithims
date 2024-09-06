#include "list.h"
#include <cassert>

template<class item>
list<item>::list() : element(nullptr), size(0), last(-1) {}

template<class item>
list<item>::list(const int& size) {
    this->element = new item[size];
    assert(this->element != nullptr);
    this->size = size;
    this->last = -1;
}

template<class item>
list<item>::list(const list& list) {
    delete[] this->element;
    this->element = new item[list.size];
    assert(this->element != nullptr);
    this->size = list.size;
    this->last = list.last;
    for (int i = 0; i < list.Length(); i++) {
        this->element[i] = list.element[i];
    }
}

template<class item>
list<item>& list<item>::operator=(const list& list) {
    delete[] this->element;
    this->element = new item[list.size];
    assert(this->element != nullptr);
    this->size = list.size;
    this->last = list.last;
    for (int i = 0; i < list.Length(); i++) {
        this->element[i] = list.element[i];
    }
    return *this;
}

template<class item>
inline bool list<item>::Empty() const { return last < 0; }

template<class item>
inline int list<item>::Length() const { return last + 1; }

template<class item>
void list<item>::Insert(const item& element, const int& index) {
    assert(index >= 0 && index <= last + 1);
    if (this->Length() < this->size) {
        for (int i = this->last; i >= index; i--) {
            this->element[i + 1] = this->element[i];
        }
        this->element[index] = element;
    }
    else {
        item* new_element;
        new_element = new item[2*this->size + 1];
        assert(new_element != nullptr);
        for (int i = 0; i < index; i++) {
            new_element[i] = this->element[i];
        }
        new_element[index] = element;
        for (int i = this->last; i >= index; i--) {
            new_element[i + 1] = this->element[i];
        }
        delete[] this->element;
        this->element = new_element;
        this->size = 2*this->size + 1;
    }
    this->last++;
}

template<class item>
void list<item>::Append(const item& element) {
    this->Insert(element, this->last + 1);
}

template<class item>
void list<item>::Delete(const int& index) {
    assert(index >= 0 && index <= last);
    for (int i = index; i < last; i++) {
        this->element[i] = this->element[i + 1];
    }
    last--;
}

template<class item>
inline item& list<item>::Element(const int& index) const {
    assert(index >= 0 && index <= last);
    return this->element[index];
}