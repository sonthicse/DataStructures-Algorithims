#include "set.h"
#include <cassert>

using namespace std;

template<class item>
void set<item>::setInsert(const item& element) {
    if (!this->Search(element)) {
        this->Append(element);
    }
}

template<class item>
void set<item>::setDelete(const KeyType& key) {
    for (int i = 0; i < this->Length(); i++) {
        if (this->Element(i) == key) {
            this->Delete(i);
            return;
        }
    }
}

template<class item>
bool set<item>::Search(const KeyType& key) const {
    for (int i = 0; i < this->Length(); i++) {
        if (this->Element(i) == key) {
            return true;
        }
    }
    return false;
}

template<class item>
const item& set<item>::max() const {
    if (this->Empty()) {
        throw runtime_error("Set is empty");
    }
    int index = 0;
    for (int i = 1; i < this->Length(); i++) {
        if (this->Element(index) < this->Element(i)) {
            index = i;
        }
    }
    return this->Element(index);
}

template<class item>
const item& set<item>::min() const {
    if (this->Empty()) {
        throw runtime_error("Set is empty");
    }
    int index = 0;
    for (int i = 1; i < this->Length(); i++) {
        if (this->Element(index) > this->Element(i)) {
            index = i;
        }
    }
    return this->Element(index);
}