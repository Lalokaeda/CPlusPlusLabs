#include <iostream>
#include <cstdio>
#include "Stroka.h"  // Подключение заголовочного файла с классом Stroka

using namespace std;

int main(void) {

    // Создание объектов класса Stroka
    Stroka s1((char*)"qwert"), s3, s4(s1), s5;

    // Ввод строки с клавиатуры и присваивание строки объекту s3
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();

    // Конкатенация строк s1, s3 и s4 с сохранением результата в s5
    s5 = s1 + s3 + s4;

    // Вывод длины строки s5 и её содержимого
    cout << "Длина s5 = " << s5.dlina() << endl;
    s5.vyvod();

    // Сравнение строк s1 и s5, а также s1 и s4
    if (s1 == s5)
        cout << "Строки s1 и s5 равны" << endl;
    else if (s1 == s4)
        cout << "Строки s1 и s4 равны" << endl;

    return 0;
}