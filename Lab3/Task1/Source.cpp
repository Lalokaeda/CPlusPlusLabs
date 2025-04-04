#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;


// 1. Метод "мини-макс"
void minMaxSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 2.1. Метод пузырька
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2.2. Быстрая сортировка
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quickSort(arr, left, j);
        quickSort(arr, i, right);
    }
}

// 3. Сортировка четных по возрастанию, нечетных по убыванию
void customSort(int arr[], int size) {
    // Разделяем четные и нечетные
    vector<int> even, odd;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even.push_back(arr[i]);
        }
        else {
            odd.push_back(arr[i]);
        }
    }

    // четные по возрастанию
    sort(even.begin(), even.end());

    // нечетные по убыванию
    sort(odd.begin(), odd.end(), greater<int>());

    // Сбор обратно в массив
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = even[evenIndex++];
        }
        else {
            arr[i] = odd[oddIndex++];
        }
    }
}

// 4. Сортировка по возрастанию на интервале [N1, N2]
void sortAscendingInRange(int arr[], int size, int N1, int N2) {
    if (N1 < 0 || N2 >= size || N1 > N2) {
        cout << "Некорректный интервал!" << endl;
        return;
    }
    sort(arr + N1, arr + N2 + 1);
}

// 5. Сортировка по убыванию на интервале [N1, N2]
void sortDescendingInRange(int arr[], int size, int N1, int N2) {
    if (N1 < 0 || N2 >= size || N1 > N2) {
        cout << "Некорректный интервал!" << endl;
        return;
    }
    sort(arr + N1, arr + N2 + 1, greater<int>());
}

// Функция для вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    // Исходный массив
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    const int n = sizeof(mas) / sizeof(mas[0]);

    cout << "Исходный массив: ";
    printArray(mas, n);

    // 1. Сортировка методом "мини-макс"
    {
        int arr[n];
        copy(mas, mas + n, arr);
        minMaxSort(arr, n);
        cout << "\n1. Сортировка методом \"мини-макс\": ";
        printArray(arr, n);
    }

    // 2.1. Сортировка пузырьком
    {
        int arr[n];
        copy(mas, mas + n, arr);
        bubbleSort(arr, n);
        cout << "2.1. Сортировка пузырьком: ";
        printArray(arr, n);
    }

    // 2.2. Быстрая сортировка
    {
        int arr[n];
        copy(mas, mas + n, arr);
        quickSort(arr, 0, n - 1);
        cout << "2.2. Быстрая сортировка: ";
        printArray(arr, n);
    }

    // 3. Сортировка четных по возрастанию, нечетных по убыванию
    {
        int arr[n];
        copy(mas, mas + n, arr);
        customSort(arr, n);
        cout << "3. Четные по возрастанию, нечетные по убыванию: ";
        printArray(arr, n);
    }

    // 4. Сортировка по возрастанию на интервале [3, 8]
    {
        int arr[n];
        copy(mas, mas + n, arr);
        sortAscendingInRange(arr, n, 3, 8);
        cout << "4. Сортировка по возрастанию на интервале [3,8]: ";
        printArray(arr, n);
    }

    // 5. Сортировка по убыванию на интервале [2, 7]
    {
        int arr[n];
        copy(mas, mas + n, arr);
        sortDescendingInRange(arr, n, 2, 7);
        cout << "5. Сортировка по убыванию на интервале [2,7]: ";
        printArray(arr, n);
    }

    // Ответ на вопрос
    cout << "\nМожно ли использовать такие функции для многомерных массивов?" << endl;
    cout << "Да, но для этого нужно либо преобразовать многомерный массив в одномерный," << endl;
    cout << "либо модифицировать функции сортировки для работы с многомерными массивами." << endl;

    return 0;
}