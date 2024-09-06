#ifndef BAG_H
#define BAG_H

class Bag
{
public:
    static const int MAX_SIZE = 100;
    typedef int Item;
    Bag();
    int sum() const;
    int occurr(const Item&) const;
    void insert(const Item&);
    void remove(const Item&);
    void operator+=(const Bag&);
    friend Bag operator+(const Bag&, const Bag&);
private:
    Item data[MAX_SIZE];
    int size;
};

#endif