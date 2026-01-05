#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "linear_search.h"
#include "binary_search.h"

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

    sort(a.begin(), a.end());

    int target;
    cout << "Enter value to search: ";
    cin >> target;

    auto start1 = high_resolution_clock::now();
    int idx1 = linearSearch(a, target);
    auto end1 = high_resolution_clock::now();
    auto t1 = duration_cast<microseconds>(end1 - start1);

    auto start2 = high_resolution_clock::now();
    int idx2 = binarySearch(a, target);
    auto end2 = high_resolution_clock::now();
    auto t2 = duration_cast<microseconds>(end2 - start2);

    cout << "\nResults:\n";

    cout << "Linear Search: ";
    if (idx1 != -1) cout << "Found at index " << idx1;
    else cout << "Not found";
    cout << " | Time: " << t1.count() << " microseconds\n";

    cout << "Binary Search: ";
    if (idx2 != -1) cout << "Found at index " << idx2;
    else cout << "Not found";
    cout << " | Time: " << t2.count() << " microseconds\n";

    return 0;
}
