#include <iostream>
#include <cstring>
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

const int NUM_STRINGS = 2;     // Количество строк
const int MAX_LENGTH = 100;    // Максимальная длина строки

int main() {
    // Объявляем массив строк
    char strings[NUM_STRINGS][MAX_LENGTH] = {
        "qwerty",
        "1234567890"
    };

    // 1. Вызов функций длины строки
    for (int i = 0; i < NUM_STRINGS; ++i) {
        cout << "Строка[" << i << "] = " << strings[i] << endl;
        cout << "  diina1: " << diina1(strings[i]) << endl;
        cout << "  diina2: " << diina2(strings[i]) << endl;
        cout << "  diina3: " << diina3(strings[i]) << endl;
    }

    // 2. Обмен строк местами
    char temp[MAX_LENGTH];
    kopir(temp, strings[0]);
    kopir(strings[0], strings[1]);
    kopir(strings[1], temp);
    cout << "\nПосле обмена:\n";
    cout << "  strings[0]: " << strings[0] << endl;
    cout << "  strings[1]: " << strings[1] << endl;

    // 3. Копирование одной строки в другую
    kopir(strings[0], strings[1]);
    cout << "\nПосле копирования:\n";
    cout << "  strings[0]: " << strings[0] << endl;
    cout << "  strings[1]: " << strings[1] << endl;

    // 4. Сравнение строк
    int cmp = srawn(strings[0], strings[1]);
    cout << "\nРезультат сравнения:\n";
    cout << "  strings[0]: " << strings[0] << endl;
    cout << "  strings[1]: " << strings[1] << endl;
    cout << "  Код сравнения: " << cmp << endl;

    // 5. Конкатенация строк
    konkat(strings[0], strings[1]);
    cout << "\nПосле конкатенации:\n";
    cout << "  strings[0]: " << strings[0] << endl;
    cout << "  strings[1]: " << strings[1] << endl;

    return 0;
}

// Функции работы со строками
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
