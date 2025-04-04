#include <iostream>
#include <cstring> 
#include <windows.h>

using namespace std;

int main() {

    // Инициализация строк
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[40];

    // 1. Определение длины строки - strlen()
    cout << "1. Длина str1: " << strlen(str1) << endl;
    cout << "   Длина str2: " << strlen(str2) << endl;

    // 2. Конкатенация строк - strcat()
    strcpy_s(str3, str1); // Копируем str1 в str3
    strcat_s(str3, " ");  // Добавляем пробел
    strcat_s(str3, str2); // Добавляем str2
    cout << "2. Результат конкатенации: " << str3 << endl;

    // 3. Копирование строк - strcpy()
    char str4[20];
    strcpy_s(str4, str1);
    cout << "3. Результат копирования: " << str4 << endl;

    // 4. Сравнение строк - strcmp()
    int result = strcmp(str1, str2);
    cout << "4. Результат сравнения: ";
    if (result < 0) {
        cout << "str1 меньше str2" << endl;
    }
    else if (result > 0) {
        cout << "str1 больше str2" << endl;
    }
    else {
        cout << "str1 равно str2" << endl;
    }

    return 0;
}