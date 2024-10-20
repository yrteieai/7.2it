#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// ������� ��� ��������� ������� � ���������� ��������
void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// ������� ��� ��������� ������� � ������ �������
void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// ������� ��� ����� ���������� � ������������� �������� ������� �����
void SwapMinMaxInRow(int** a, const int k, const int n) {
    for (int i = 0; i < k; i++) {
        int minIndex = 0, maxIndex = 0;
        // ��������� ������� ���������� �� ������������� �������� � �����
        for (int j = 1; j < n; j++) {
            if (a[i][j] < a[i][minIndex])
                minIndex = j;
            if (a[i][j] > a[i][maxIndex])
                maxIndex = j;
        }
        // �������� ��������� � ������������ ��������
        int temp = a[i][minIndex];
        a[i][minIndex] = a[i][maxIndex];
        a[i][maxIndex] = temp;
    }
}

int main() {
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����

    int Low = -90;  // ����� ���� �������� �������
    int High = 90;  // ������ ���� �������� �������
    int k, n;       // ������ �������

    cout << "k: "; cin >> k;
    cout << "n: "; cin >> n;

    // ��������� �������� ������� ������� k * n
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // ��������� ������� � ����������� ���������� �� �������� ��
    Create(a, k, n, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, k, n);

    // �������� ������� �� ���������� �������� ������� �����
    SwapMinMaxInRow(a, k, n);

    // �������� ������� ���� �����������
    cout << "Modified matrix:" << endl;
    Print(a, k, n);

    // ������� ���'���
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
