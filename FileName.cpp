#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int Max(int** a, const int n);
int Min(int** a, const int n);
int SumMinMax(int** a, const int n);
void SwapMinMax(int** a, const int n);

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    cout << "n = "; cin >> n;
    int** a = new int* [n];

    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    int max = Max(a, n);
    int min = Min(a, n);
    int sum = SumMinMax(a, n);

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
    cout << "Sum = " << sum << endl;

    SwapMinMax(a, n);
    cout << "After swapping Min and Max:" << endl;
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n) {
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

int Max(int** a, const int n) {
    int max = a[0][1];  //Ініцілізація максимального значення значенням над діагоналлю

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }

    return max;
}

int Min(int** a, const int n) {
    int min = a[1][0];  // Ініцілізація мінімального значення значенням під діагоналлю

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }

    return min;
}
int SumMinMax(int** a, const int n) {
    int max = Max(a, n);
    int min = Min(a, n);

    return max + min;
}
void SwapMinMax(int** a, const int n) {
    int max = Max(a, n);
    int min = Min(a, n);

    int max_i, max_j, min_i, min_j;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == max) {
                max_i = i;
                max_j = j;
            }
            if (a[i][j] == min) {
                min_i = i;
                min_j = j;
            }
        }
    }
    int temp = a[max_i][max_j];
    a[max_i][max_j] = a[min_i][min_j];
    a[min_i][min_j] = temp;
}