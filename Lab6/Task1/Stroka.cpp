#include "stroka.h"
#include <iostream>
using namespace std;

// Реализация функций
int diina1(char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void kopir(char* dest, char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

int srawn(char* s1, char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void konkat(char* dest, char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}

// Реализация методов Stroka
Stroka::Stroka(char* s) {
    int len = diina1(s);
    str = new char[len + 1];
    kopir(str, s);
}

Stroka::Stroka() {
    str = new char[1];
    str[0] = '\0';
}

Stroka::Stroka(const Stroka& other) {
    int len = diina1(other.str);
    str = new char[len + 1];
    kopir(str, other.str);
}

Stroka& Stroka::operator=(const Stroka& other) {
    if (this != &other) {
        delete[] str;
        int len = diina1(other.str);
        str = new char[len + 1];
        kopir(str, other.str);
    }
    return *this;
}

Stroka& Stroka::operator=(const char* s) {
    delete[] str;
    int len = diina1((char*)s);
    str = new char[len + 1];
    kopir(str, (char*)s);
    return *this;
}

Stroka Stroka::operator+(const Stroka& other) {
    int len1 = diina1(str);
    int len2 = diina1(other.str);
    char* newStr = new char[len1 + len2 + 1];
    kopir(newStr, str);
    konkat(newStr, other.str);
    Stroka result(newStr);
    delete[] newStr;
    return result;
}

int Stroka::operator==(const Stroka& other) {
    return srawn(str, other.str) == 0;
}

int Stroka::dlina() {
    return diina1(str);
}

void Stroka::vvod() {
    char buffer[1000];
    cin.getline(buffer, 1000);
    delete[] str;
    int len = diina1(buffer);
    str = new char[len + 1];
    kopir(str, buffer);
}

void Stroka::vyvod() {
    cout << str << endl;
}

Stroka::~Stroka() {
    delete[] str;
}
