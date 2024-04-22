#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe {
public:
    void sort(std::vector<int>& array);
private:
    void mergeInsertionSort(std::vector<int>& array, int left, int right);
    int findMedian(std::vector<int>& array, int left, int right);
    void insertionSort(std::vector<int>& array, int left, int right);
};

#endif
