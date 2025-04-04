#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Пример 1: Запись в текстовый файл
    ofstream fout("textfile.txt");
    if (!fout) {
        cerr << "Не удалось открыть файл для записи\n";
        return 1;
    }
    fout << "Пример работы с текстовым файлом.\n";
    fout << "Запись строки номер 2.\n";
    fout.close();

    // Пример 2: Чтение из текстового файла
    ifstream fin("textfile.txt");
    if (!fin) {
        cerr << "Не удалось открыть файл для чтения\n";
        return 1;
    }
    cout << "\nСодержимое textfile.txt:\n";
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    // Пример 3: Запись в бинарный файл
    ofstream bout("binaryfile.bin", ios::binary);
    if (!bout) {
        cerr << "Не удалось открыть бинарный файл для записи\n";
        return 1;
    }
    int a = 42;
    double b = 3.14159;
    bout.write((char*)&a, sizeof(a));
    bout.write((char*)&b, sizeof(b));
    bout.close();

    // Пример 4: Чтение из бинарного файла
    ifstream bin("binaryfile.bin", ios::binary);
    if (!bin) {
        cerr << "Не удалось открыть бинарный файл для чтения\n";
        return 1;
    }
    int a_read;
    double b_read;
    bin.read((char*)&a_read, sizeof(a_read));
    bin.read((char*)&b_read, sizeof(b_read));
    bin.close();

    cout << "\nПрочитано из бинарного файла:\n";
    cout << "int: " << a_read << ", double: " << b_read << endl;

    return 0;
}
