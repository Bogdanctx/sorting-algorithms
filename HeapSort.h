//
// Created by Owner on 3/28/2024.
//

#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H

#include <vector>
#include <chrono>
#include <iostream>

class HeapSort{
public:
    explicit HeapSort(const std::vector<long long int> nums) : m_numsToSort(nums) {};
    void heapify_down(int i, int n);
    void build_max_heap();
    void begin_benchmark();

private:

    bool verifySort();
    void sort();
    std::vector<long long int> m_numsToSort;
    std::chrono::system_clock::time_point startTime, endTime;
    int elapsedTime;

};


#endif //SORTING_ALGORITHMS_HEAPSORT_H