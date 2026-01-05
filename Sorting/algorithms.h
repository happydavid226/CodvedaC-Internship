#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

void bubbleSort(std::vector<int>& a);
void selectionSort(std::vector<int>& a);
void insertionSort(std::vector<int>& a);
void mergeSort(std::vector<int>& a, int l, int r);
void quickSort(std::vector<int>& a, int l, int r);
void heapSort(std::vector<int>& a);

bool isSorted(const std::vector<int>& a);

#endif
