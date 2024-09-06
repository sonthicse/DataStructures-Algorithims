#include "list.h"

template <class item>
list<item>::list() : last(-1), current(-1) {}

template <class item>
bool list<item>::empty() const { return last < 0; }

template <class item>
int list<item>::length() const {
    if (last < 0) return 0;
    return last + 1;
}

template <class item>
void list<item>::insert(const item& element, const int& index) {
    assert(length() < MAX_SIZE && 0 <= index && index <= length());
    for (int i = last; i >= index; i--) {
        this->element[i + 1] = this->element[i];
    }
    this->element[index] = element;
    last++;
}

template <class item>
void list<item>::append(const item& element) {
    assert(length() < MAX_SIZE);
    this->element[++last] = element;
}

template <class item>
void list<item>::erase(const int& index) {
    assert(0 <= index && index <= length());
    for (int i = index; i < last; i++) {
        this->element[i] = this->element[i + 1];
    }
    last--;
}

template <class item>
item list<item>::get(const int& index) const {
    assert(index <= last);
    return this->element[index];
}

template <class item>
void list<item>::start() { 
    current = (last >= 0) ? 0 : -1;
}

template <class item>
bool list<item>::valid() const { return current >= 0 && current <= last; }

template <class item>
void list<item>::advanced() { 
    if (current <= last) current++;
}

template <class item>
item list<item>::getCurrent() const { return this->element[current]; }

template <class item>
void list<item>::add(const item& element) {
    assert(length() < MAX_SIZE && valid());
    last++;
    for (int i = last; i > current; i--) {
        this->element[i] = this->element[i - 1];
    }
    this->element[current++] = element;
}

template <class item>
void list<item>::remove() {
    for (int i = current; i < last; i++) {
        this->element[i] = this->element[i + 1];
    }
    last--;
}