#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <climits>
#include <vector>

#define N 5

using namespace std;

// Функция для нахождения минимума матрицы
float matrixMin(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для нахождения максимума матрицы
float matrixMax(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для нахождения максимума инженерно-политической части матрицы (предполагаем, что это нижнетреугольная часть)
float engineeringPoliticalMax(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для нахождения максимума верхнетреугольной части матрицы
float upperTriangleMax(float m[N][N]) {
    float maxVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для нахождения минимума инженерно-политической части матрицы
float engineeringPoliticalMin(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для нахождения минимума верхнетреугольной части матрицы
float upperTriangleMin(float m[N][N]) {
    float minVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для нахождения минимума главной диагонали
float mainDiagonalMin(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] < minVal) {
            minVal = m[i][i];
        }
    }
    return minVal;
}

// Функция для нахождения максимума главной диагонали
float mainDiagonalMax(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] > maxVal) {
            maxVal = m[i][i];
        }
    }
    return maxVal;
}

// Функция для нахождения минимума второстепенной диагонали
float secondaryDiagonalMin(float m[N][N]) {
    float minVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] < minVal) {
            minVal = m[i][N - 1 - i];
        }
    }
    return minVal;
}

// Функция для нахождения максимума второстепенной диагонали
float secondaryDiagonalMax(float m[N][N]) {
    float maxVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] > maxVal) {
            maxVal = m[i][N - 1 - i];
        }
    }
    return maxVal;
}

// Функция для нахождения среднеарифметического значения элементов матрицы
float matrixAverage(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// Функция для нахождения среднеарифметического инженерно-политической части
float engineeringPoliticalAverage(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для нахождения среднеарифметического верхнетреугольной части
float upperTriangleAverage(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для вычисления сумм строк
vector<float> rowSums(float m[N][N]) {
    vector<float> sums(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sums[i] += m[i][j];
        }
    }
    return sums;
}

// Функция для вычисления сумм столбцов
vector<float> columnSums(float m[N][N]) {
    vector<float> sums(N, 0);
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            sums[j] += m[i][j];
        }
    }
    return sums;
}

// Функция для нахождения минимальных значений строк
vector<float> rowMins(float m[N][N]) {
    vector<float> mins(N, 0);
    for (int i = 0; i < N; i++) {
        mins[i] = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] < mins[i]) {
                mins[i] = m[i][j];
            }
        }
    }
    return mins;
}

// Функция для нахождения минимальных значений столбцов
vector<float> columnMins(float m[N][N]) {
    vector<float> mins(N, 0);
    for (int j = 0; j < N; j++) {
        mins[j] = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] < mins[j]) {
                mins[j] = m[i][j];
            }
        }
    }
    return mins;
}

// Функция для нахождения максимальных значений строк
vector<float> rowMaxs(float m[N][N]) {
    vector<float> maxs(N, 0);
    for (int i = 0; i < N; i++) {
        maxs[i] = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] > maxs[i]) {
                maxs[i] = m[i][j];
            }
        }
    }
    return maxs;
}

// Функция для нахождения максимальных значений столбцов
vector<float> columnMaxs(float m[N][N]) {
    vector<float> maxs(N, 0);
    for (int j = 0; j < N; j++) {
        maxs[j] = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] > maxs[j]) {
                maxs[j] = m[i][j];
            }
        }
    }
    return maxs;
}

// Функция для нахождения среднеарифметических значений строк
vector<float> rowAverages(float m[N][N]) {
    vector<float> avgs(N, 0);
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        avgs[i] = sum / N;
    }
    return avgs;
}

// Функция для нахождения среднеарифметических значений столбцов
vector<float> columnAverages(float m[N][N]) {
    vector<float> avgs(N, 0);
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        avgs[j] = sum / N;
    }
    return avgs;
}

// Функция для нахождения сумм нижне- и верхнетреугольных частей матрицы
void triangleSums(float m[N][N], float& lowerSum, float& upperSum) {
    lowerSum = 0;
    upperSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            lowerSum += m[i][j];
        }
        for (int j = i; j < N; j++) {
            upperSum += m[i][j];
        }
    }
}

// Функция для нахождения элемента, наиболее близкого к среднеарифметическому
float closestToAverage(float m[N][N]) {
    float avg = matrixAverage(m);
    float closest = m[0][0];
    float minDiff = abs(m[0][0] - avg);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = abs(m[i][j] - avg);
            if (diff < minDiff) {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }
    return closest;
}

int main() {
    float m[N][N];
    int i, j;

    // Инициализация матрицы случайными значениями
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = rand() % 1000 / 10.0f; // Генерация чисел от 0 до 99.9
        }
    }

    // Вывод матрицы
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << setw(8) << setprecision(5) << m[i][j];
        }
        cout << endl;
    }

    // Вычисление и вывод всех требуемых значений
    cout << "\nМинимальное значение матрицы: " << matrixMin(m) << endl;
    cout << "Максимальное значение матрицы: " << matrixMax(m) << endl;
    cout << "Максимум нижнетреугольной части: " << engineeringPoliticalMax(m) << endl;
    cout << "Максимум верхнетреугольной части: " << upperTriangleMax(m) << endl;
    cout << "Минимум нижнетреугольной части: " << engineeringPoliticalMin(m) << endl;
    cout << "Минимум верхнетреугольной части: " << upperTriangleMin(m) << endl;
    cout << "Минимум главной диагонали: " << mainDiagonalMin(m) << endl;
    cout << "Максимум главной диагонали: " << mainDiagonalMax(m) << endl;
    cout << "Минимум побочной диагонали: " << secondaryDiagonalMin(m) << endl;
    cout << "Максимум побочной диагонали: " << secondaryDiagonalMax(m) << endl;
    cout << "Среднее арифметическое матрицы: " << matrixAverage(m) << endl;
    cout << "Среднее нижнетреугольной части: " << engineeringPoliticalAverage(m) << endl;
    cout << "Среднее верхнетреугольной части: " << upperTriangleAverage(m) << endl;

    vector<float> sums = rowSums(m);
    cout << "\nСуммы строк: ";
    for (float val : sums) cout << val << " ";

    sums = columnSums(m);
    cout << "\nСуммы столбцов: ";
    for (float val : sums) cout << val << " ";

    vector<float> mins = rowMins(m);
    cout << "\nМинимумы строк: ";
    for (float val : mins) cout << val << " ";

    mins = columnMins(m);
    cout << "\nМинимумы столбцов: ";
    for (float val : mins) cout << val << " ";

    vector<float> maxs = rowMaxs(m);
    cout << "\nМаксимумы строк: ";
    for (float val : maxs) cout << val << " ";

    maxs = columnMaxs(m);
    cout << "\nМаксимумы столбцов: ";
    for (float val : maxs) cout << val << " ";

    vector<float> avgs = rowAverages(m);
    cout << "\nСредние значения строк: ";
    for (float val : avgs) cout << val << " ";

    avgs = columnAverages(m);
    cout << "\nСредние значения столбцов: ";
    for (float val : avgs) cout << val << " ";

    float lowerSum, upperSum;
    triangleSums(m, lowerSum, upperSum);
    cout << "\nСумма нижнетреугольной части: " << lowerSum << endl;
    cout << "Сумма верхнетреугольной части: " << upperSum << endl;

    cout << "Элемент, ближайший к среднему: " << closestToAverage(m) << endl;


    return 0;
}