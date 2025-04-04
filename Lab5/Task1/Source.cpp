#include <iostream>
#include <cstdio>
#pragma warning(disable : 4996)

using namespace std;

// Функция для выполнения задач 1, 2 и 3
void Task1_2_3() {
    char name[50];
    printf("Введите имя файла: ");
    scanf("%s", name);

    // Открываем файл для чтения
    FILE* in = fopen(name, "r");
    if (in == NULL) {
        printf("Файл %s не открыт", name);
        exit(1);
    }

    int count_all = 0;      // Счетчик всех символов
    int count_empty = 0;    // Счетчик пустых символов
    char* IN_Str = new char[128]; // Строка для поиска
    cout << "Введите строку для поиска:" << endl;
    cin >> IN_Str;

    char* buff = new char[128]; // Буфер для чтения строк
    cout << "***Начало содержимого файла***\n";

    // Чтение файла построчно
    while (!feof(in)) {
        if (fgets(buff, 128, in)) {
            // Подсчет символов
            for (int i = 0; i < strlen(buff); i++) {
                if (buff[i] <= 32) { count_empty++; }
                else { count_all++; }
            }

            // Поиск подстроки
            if (strstr(buff, IN_Str) != NULL) {
                cout << "Подстрока найдена: " << strstr(buff, IN_Str) << endl;
            }

            // Вывод содержимого файла
            printf("%s", buff);
        }
    }
    cout << "***Конец содержимого файла***\n";

    // Вывод результатов
    printf("Найдено пустых символов: %i\n", count_empty);
    printf("Найдено других символов: %i\n", count_all);

    fclose(in);
}

// Функция для выполнения задачи 4
void Task4() {
    char name[50];
    char fname[] = { "frmt_" };
    printf("Введите имя файла (для форматирования с нумерацией): ");
    scanf("%s", name);
    strcat(fname, name);

    int page_count = 1;

    FILE* in = fopen(name, "r");
    FILE* out = fopen(fname, "w");
    char* buff = new char[128];

    if (in == NULL) {
        printf("Файл %s не открыт", name);
        exit(1);
    }

    while (!feof(in)) {
        if (fgets(buff, 128, in) != NULL) {
            if (strstr(buff, "\f") != NULL) {
                fprintf(out, "\t\t\t\t\t\t %i\f", page_count);
                page_count++;
            }

            if (strstr(buff, "- ") != NULL && strstr(buff, " -") != NULL) {
                continue;
            }
            else {
                fputs(buff, out);
            }
        }
    }

    fprintf(out, "\t\t\t\t\t\t %i\f", page_count);

    fclose(in);
    fclose(out);
    exit(0);
}

// Функция для задач 5 и 6 (шифрование/дешифрование)
void Task5_6(char* name, int key) {
    char ch;
    char fname[] = { "code_" };

    FILE* in = fopen((char*)name, "r");
    if (in == NULL) {
        printf("Файл %s не открыт", name);
        return;
    }
    else {
        strcat(fname, (char*)name);
        FILE* out = fopen(fname, "w");

        while (!feof(in)) {
            ch = getc(in);
            ch = ch ^ key;
            fputc(ch, out);
        }

        fclose(in);
        fclose(out);
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    std::cout << __cplusplus << std::endl;
    Task1_2_3();
    Task4();

    char ch, name[50];
    int key;
    if (argc > 1) {
        if (argc == 3) {
            strcpy(name, argv[1]);
            key = atoi(argv[2]);
        }
        if (argc > 3) {
            printf("Слишком много аргументов");
            return 1;
        }
    }
    else {
        puts("Введите имя файла: ");
        scanf("%s", name);
        puts("Введите ключ: ");
        scanf("%i", &key);
    }

    Task5_6(name, key);

    return 0;
}