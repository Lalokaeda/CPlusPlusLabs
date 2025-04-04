#include <iostream>
#include <conio.h>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;

// Объявления функций
int diina1(char*);
int diina2(char*);
int diina3(char*);
void kopir(char*, char*);
int srawn(char*, char*);
void konkat(char*, char*);

void main(void)
{

    // Объявление строк
    char* str1 = (char*)calloc(50, sizeof(char));
    char* str2 = (char*)calloc(50, sizeof(char));

    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    // 1. Вызов функций длины строки
    cout << "Длина str1=" << diina1(str1) << ", str2=" << diina1(str2) << endl;
    cout << "Длина str1=" << diina2(str1) << ", str2=" << diina2(str2) << endl;
    cout << "Длина str1=" << diina3(str1) << ", str2=" << diina3(str2) << endl;

    // 2. Обмен значений
    char temp[100];
    kopir(temp, str1);
    kopir(str1, str2);
    kopir(str2, temp);
    cout << "после обмена 1: a=" << str1 << " b=" << str2 << endl;

    // 3. Копирование строк
    kopir(str1, str2);
    cout << "результат копирования: str1=" << str1 << ", str2=" << str2 << endl;

    // 4. Сравнение строк
    int cmpResult = srawn(str1, str2);
    cout << "результат сравнения: str1=" << str1 << ", str2=" << str2 << endl;
    cout << "код сравнения: " << cmpResult << endl;

    // 5. Конкатенация строк
    konkat(str1, str2);
    cout << "результат сцепления: str1=" << str1 << ", str2=" << str2 << endl;

    // malloc - выделяет неинициализированную память
    // calloc - выделяет и обнуляет память

}

// Реализации функций:

// 1. Три функции определения длины строки
int diina1(char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int diina2(char* str) {
    char* p = str;
    while (*p) p++;
    return p - str;
}

int diina3(char* str) {
    if (*str == '\0') return 0;
    return 1 + diina3(str + 1);
}

// 2. Функция копирования строк
void kopir(char* dest, char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

// 3. Функция сравнения строк
int srawn(char* s1, char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// 4. Функция конкатенации строк
void konkat(char* dest, char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}