#ifndef STRING_H
#define STRING_H

class String {
public:
    String();
    String(const String&);
    int getSize() const;
    char get(const int&);
    void operator=(const String&);
    void operator+=(const String&);
    friend String operator+(const String&, const String&);
    friend bool operator<(const String&, const String&);
    friend bool operator>(const String&, const String&);
    friend bool operator==(const String&, const String&);
private:
    static const int MAX_SIZE = 100;
    char string[MAX_SIZE];
    int size;
};

#endif