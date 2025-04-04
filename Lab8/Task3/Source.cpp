#include <iostream>
#include <fstream>
#include <string>

void EncryptFileWithStateDemo(const std::string& filename, int key) {
    std::ifstream in(filename, std::ios::in | std::ios::binary);

    if (!in) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;

        std::cout << "in.good(): " << in.good() << std::endl;
        std::cout << "in.fail(): " << in.fail() << std::endl;
        std::cout << "in.bad(): " << in.bad() << std::endl;
        std::cout << "in.eof(): " << in.eof() << std::endl;

        in.clear();
        std::cout << "Флаги сброшены с помощью clear().\n";
        return;
    }

    std::streampos start = in.tellg();
    in.seekg(0, std::ios::end);
    std::streampos end = in.tellg();
    std::cout << "Размер файла: " << (end - start) << " байт" << std::endl;
    in.seekg(0);

    std::string outFilename = "code_" + filename;
    std::ofstream out(outFilename, std::ios::out | std::ios::binary);

    char ch;
    while (in.get(ch)) {
        out.put(ch ^ key);
    }

    if (in.eof()) {
        std::cout << "Достигнут конец файла при шифровании.\n";
    }
    else if (in.fail()) {
        std::cout << "Произошла ошибка ввода при шифровании.\n";
    }

    in.close();
    out.close();
    std::cout << "Файл зашифрован: " << outFilename << std::endl;
}

void DecryptFile(const std::string& encryptedFilename, int key) {
    std::ifstream in(encryptedFilename, std::ios::in | std::ios::binary);
    if (!in) {
        std::cerr << "Ошибка открытия зашифрованного файла: " << encryptedFilename << std::endl;
        return;
    }

    std::string outFilename = "decoded_" + encryptedFilename.substr(5); // убрать "code_"
    std::ofstream out(outFilename, std::ios::out | std::ios::binary);

    char ch;
    while (in.get(ch)) {
        out.put(ch ^ key);
    }

    if (in.eof()) {
        std::cout << "Достигнут конец файла при дешифровке.\n";
    }
    else if (in.fail()) {
        std::cout << "Произошла ошибка ввода при дешифровке.\n";
    }

    in.close();
    out.close();
    std::cout << "Файл расшифрован: " << outFilename << std::endl;
}

int main() {
    std::string filename;
    int key;

    std::cout << "Введите имя файла для шифрования: ";
    std::cin >> filename;

    std::cout << "Введите числовой ключ (целое число): ";
    std::cin >> key;

    EncryptFileWithStateDemo(filename, key);

    std::string encrypted = "code_" + filename;
    DecryptFile(encrypted, key);

    return 0;
}
