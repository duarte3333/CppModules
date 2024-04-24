#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
public:
    void sort_with_vector(std::vector<int>& array);
    void sort_with_list(std::list<int>& array);

private:
    // Functions for vector sorting
    void vector_mergeInsertionSort(std::vector<int>& array, int left, int right);
    int vector_partition(std::vector<int>& array, int left, int right, int pivot);
    int vector_findMedian(std::vector<int>& array, int left, int right);
    void vector_insertionSort(std::vector<int>& array, int left, int right);
    
    // Functions for list sorting
    void list_mergeInsertionSort(std::list<int>& array, int left, int right);
    int list_findMedian(std::list<int>& array);
    void list_partition(std::list<int>& array, int pivot, std::list<int>& left, std::list<int>& right);
};

#endif
