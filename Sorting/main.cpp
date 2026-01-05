#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "algorithms.h"

using namespace std;
using namespace chrono;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> a(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1e9);

    for (int i = 0; i < n; i++)
        a[i] = dist(gen);

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "6. Heap Sort\n";
    cout << "Choice: ";

    int choice;
    cin >> choice;

    vector<int> b = a;

    auto start = high_resolution_clock::now();

    switch (choice) {
        case 1: bubbleSort(b); break;
        case 2: selectionSort(b); break;
        case 3: insertionSort(b); break;
        case 4: mergeSort(b, 0, b.size() - 1); break;
        case 5: quickSort(b, 0, b.size() - 1); break;
        case 6: heapSort(b); break;
        default: cout << "Invalid choice\n"; return 0;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nTime taken: " << duration.count() << " ms\n";
    cout << "Sorted correctly? " << (isSorted(b) ? "YES" : "NO") << "\n";

    return 0;
}
