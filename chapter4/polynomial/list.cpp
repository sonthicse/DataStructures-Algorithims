#include "list.h"
#include <cassert>

using namespace std;

template<class item>
list<item>::list() : element(nullptr), size(0), last(-1) {}

template<class item>
list<item>::list(const int& size) : element(new item[size]), size(size), last(-1) {}

template<class item>
list<item>::list(const list& other) : element(nullptr), size(0), last(-1) {
    if (other.size > 0) {
        this->element = new item[other.size];
        this->size = other.size;
        this->last = other.last;
        for (int i = 0; i <= this->last; i++) {
            this->element[i] = other.element[i];
        }
    }
}

template<class item>
list<item>::~list() {
    delete[] this->element;
    this->element = nullptr;  // Đặt con trỏ về nullptr sau khi giải phóng
    this->size = 0;
    this->last = -1;
}

template<class item>
list<item>& list<item>::operator=(const list& other) {
    if (this != &other) {  // Kiểm tra self-assignment
        item* new_element = nullptr;
        if (other.size > 0) {
            new_element = new item[other.size];
            for (int i = 0; i <= other.last; i++) {
                new_element[i] = other.element[i];
            }
        }
        
        delete[] this->element;  // Giải phóng bộ nhớ cũ
        
        this->element = new_element;
        this->size = other.size;
        this->last = other.last;
    }
    return *this;
}

template<class item>
bool list<item>::Empty() const { return this->last < 0; }

template<class item>
int list<item>::Length() const { return this->last + 1; }

template<class item>
void list<item>::Insert(const item& element, const int& index) {
    assert(index >= 0 && index <= this->last + 1);
    if (this->Length() < this->size) {
        for (int i = this->last; i >= index; i--) {
            this->element[i + 1] = this->element[i];
        }
        this->element[index] = element;
    }
    else {
        int new_size = this->size == 0 ? 1 : 2*this->size;
        item* new_element = new item[new_size];
        for (int i = 0; i < index; i++) {
            new_element[i] = this->element[i];
        }
        new_element[index] = element;
        for (int i = this->last; i >= index; i--) {
            new_element[i + 1] = this->element[i];
        }
        delete[] this->element;
        this->element = new_element;
        this->size = new_size;
    }
    this->last++;
}

template<class item>
void list<item>::Append(const item& element) {
    this->Insert(element, this->last + 1);
}

template<class item>
void list<item>::Delete(const int& index) {
    assert(index >= 0 && index <= this->last);
    for (int i  = index; i < this->last; i++) {
        this->element[i] = this->element[i + 1];
    }
    this->last--;
}

template<class item>
item& list<item>::Element(const int& index) const {
    assert(index >= 0 && index <= this->last);
    return this->element[index];
}

template<class item>
list_iterator<item>::list_iterator(const list<item>& ls) : list_ptr(&ls), current(0) {}

template<class item>
void list_iterator<item>::Start() { this->current = 0; }

template<class item>
bool list_iterator<item>::Valid() const { return this->current >= 0 && this->current <= this->list_ptr->last; }

template<class item>
void list_iterator<item>::Advance() { this->current++; }

template<class item>
item& list_iterator<item>::Current() const { 
    assert(this->Valid());
    return this->list_ptr->Element(this->current);
}

template<class item>
void list_iterator<item>::Add(const item& element) {
    const_cast<list<item>*>(this->list_ptr)->Append(element);
    this->current++;
}

template<class item>
void list_iterator<item>::Remove() {
    const_cast<list<item>*>(this->list_ptr)->Delete(this->current);
}