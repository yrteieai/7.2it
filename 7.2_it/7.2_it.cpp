#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для створення матриці з випадкових елементів
void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення матриці у вигляді таблиці
void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для обміну мінімального і максимального елементів кожного рядка
void SwapMinMaxInRow(int** a, const int k, const int n) {
    for (int i = 0; i < k; i++) {
        int minIndex = 0, maxIndex = 0;
        // Знаходимо індекси мінімального та максимального елементів у рядку
        for (int j = 1; j < n; j++) {
            if (a[i][j] < a[i][minIndex])
                minIndex = j;
            if (a[i][j] > a[i][maxIndex])
                maxIndex = j;
        }
        // Обмінюємо мінімальний і максимальний елементи
        int temp = a[i][minIndex];
        a[i][minIndex] = a[i][maxIndex];
        a[i][maxIndex] = temp;
    }
}

int main() {
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    int Low = -90;  // Нижня межа діапазону значень
    int High = 90;  // Верхня межа діапазону значень
    int k, n;       // Розміри матриці

    cout << "k: "; cin >> k;
    cout << "n: "; cin >> n;

    // Створюємо динамічну матрицю розміром k * n
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Створюємо матрицю з випадковими значеннями та виводимо її
    Create(a, k, n, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, k, n);

    // Обмінюємо мінімальні та максимальні елементи кожного рядка
    SwapMinMaxInRow(a, k, n);

    // Виводимо матрицю після модифікації
    cout << "Modified matrix:" << endl;
    Print(a, k, n);

    // Очищуємо пам'ять
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
