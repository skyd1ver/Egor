#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    const int N = 10000;
    int arr1[N], arr2[N];

    // Заполнение массивов случайными числами
    for (int i = 0; i < N; i++) {
        arr1[i] = rand();
        arr2[i] = arr1[i];
    }

    // Измерение времени работы сортировки вставками
    auto start1 = chrono::high_resolution_clock::now();
    insertionSort(arr1, N);
    auto end1 = chrono::high_resolution_clock::now();

    // Измерение времени работы сортировки выбором
    auto start2 = chrono::high_resolution_clock::now();
    selectionSort(arr2, N);
    auto end2 = chrono::high_resolution_clock::now();

    // Вывод результатов
    cout << "Insertion Sort: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << " microseconds" << endl;
    cout << "Selection Sort: " << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << " microseconds" << endl;

    // Вывод отсортированных массивов
    cout << "Sorted Array 1: ";
    for (int i = 0; i < N; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Sorted Array 2: ";
    for (int i = 0; i < N; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}