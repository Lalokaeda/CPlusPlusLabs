#include <iostream>
#include <fstream>

void main() {
    std::ifstream in("nofile.txt");
    if (!in.good()) {
        std::cout << "Поток не в хорошем состоянии\n";
    }
    if (in.fail()) {
        std::cout << "Ошибка ввода/вывода\n";
    }
    in.clear(); // сброс флагов ошибок
    std::cout << "Ошибки сброшены\n";

    // Работа с seekg
    std::ofstream out("seekdemo.txt");
    out << "1234567890";
    out.close();

    std::ifstream seekIn("seekdemo.txt");
    seekIn.seekg(5);
    char c;
    seekIn.get(c);
    std::cout << "Символ на позиции 5: " << c << std::endl;
}
