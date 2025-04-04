#ifndef STROKA_H
#define STROKA_H

#include <iostream>

class Stroka {
    char* str;

public:
    Stroka(char* s);
    Stroka();
    Stroka(const Stroka& other);
    Stroka& operator=(const Stroka& other);
    Stroka& operator=(const char* s);
    Stroka operator+(const Stroka& other);
    int operator==(const Stroka& other);
    int dlina();
    void vvod();
    void vyvod();
    ~Stroka();

    // Новое:
    friend std::ostream& operator<<(std::ostream& out, const Stroka& s);
    friend std::istream& operator>>(std::istream& in, Stroka& s);
};

#endif
