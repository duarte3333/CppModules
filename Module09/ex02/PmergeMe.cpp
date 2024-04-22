#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

void PmergeMe::sort(std::vector<int>& array) {
    if (!array.empty()) {
        mergeInsertionSort(array, 0, array.size() - 1);
    }
}

int partition(std::vector<int>& array, int left, int right, int pivot) {
    int i = left, j = right;
    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    return i; // Return the partition index
}


void PmergeMe::mergeInsertionSort(std::vector<int>& array, int left, int right) {
    if (left >= right) {
        return;
    }
    if (right - left + 1 <= 5) {
        insertionSort(array, left, right);
        return;
    }

    std::vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        int subRight = std::min(i + 4, right);
        insertionSort(array, i, subRight);
        medians.push_back(array[i + (subRight - i) / 2]);
    }

    int medianValue = findMedian(medians, 0, medians.size() - 1);
    int partitionIndex = partition(array, left, right, medianValue);
    mergeInsertionSort(array, left, partitionIndex - 1);
    mergeInsertionSort(array, partitionIndex, right);

}

int PmergeMe::findMedian(std::vector<int>& array, int left, int right) {
    insertionSort(array, left, right);
    return array[left + (right - left) / 2];
}

void PmergeMe::insertionSort(std::vector<int>& array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= left && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
