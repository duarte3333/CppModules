#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for std::min

void PmergeMe::sort_with_vector(std::vector<int>& array) {
    if (!array.empty()) {
        vector_mergeInsertionSort(array, 0, array.size() - 1);
    }
}

int PmergeMe::vector_partition(std::vector<int>& array, int left, int right, int pivot) {
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

void PmergeMe::vector_mergeInsertionSort(std::vector<int>& array, int left, int right) {
    if (left >= right) {
        return;
    }
    if (right - left + 1 <= 5) {
        vector_insertionSort(array, left, right);
        return;
    }

    std::vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        int subRight = std::min(i + 4, right);
        vector_insertionSort(array, i, subRight);
        medians.push_back(array[i + (subRight - i) / 2]);
    }

    int medianValue = vector_findMedian(medians, 0, medians.size() - 1);
    int partitionIndex = vector_partition(array, left, right, medianValue);
    vector_mergeInsertionSort(array, left, partitionIndex - 1);
    vector_mergeInsertionSort(array, partitionIndex, right);
}

int PmergeMe::vector_findMedian(std::vector<int>& array, int left, int right) {
    vector_insertionSort(array, left, right);
    return array[left + (right - left) / 2];
}

void PmergeMe::vector_insertionSort(std::vector<int>& array, int left, int right) {
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

void PmergeMe::sort_with_list(std::list<int>& array) {
    if (!array.empty()) {
        list_mergeInsertionSort(array, 0, array.size() - 1);
    }
}

void PmergeMe::list_partition(std::list<int>& array, int pivot, std::list<int>& left, std::list<int>& right) {
    std::list<int>::iterator it = array.begin();
    while (it != array.end()) {
        if (*it < pivot) {
            left.push_back(*it);
        } else if (*it > pivot) {
            right.push_back(*it);
        }
        ++it;
    }
}

void PmergeMe::list_mergeInsertionSort(std::list<int>& array, int /*left*/, int /*right*/) {
    if (array.size() <= 5) {
        array.sort();
        return;
    }

    std::list<int> medians;
    std::list<int>::iterator it = array.begin();

    while (it != array.end()) {
        std::list<int> sublist;
        for (int i = 0; i < 5 && it != array.end(); i++, ++it) {
            sublist.push_back(*it);
        }
        sublist.sort();
        std::list<int>::iterator mid = sublist.begin();
        std::advance(mid, sublist.size() / 2);
        medians.push_back(*mid);
    }

    int medianValue = list_findMedian(medians);
    std::list<int> left, right;
    list_partition(array, medianValue, left, right);

    sort_with_list(left);
    sort_with_list(right);

    array.clear();
    array.splice(array.end(), left);
    array.splice(array.end(), right);
}

int PmergeMe::list_findMedian(std::list<int>& array) {
    array.sort();
    std::list<int>::iterator it = array.begin();
    std::advance(it, array.size() / 2);
    return *it;
}