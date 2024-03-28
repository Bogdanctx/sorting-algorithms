//
// Created by Radu on 3/24/2024.
//

#ifndef SORTING_ALGORITHMS_RADIXSORT_H
#define SORTING_ALGORITHMS_RADIXSORT_H


#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

class Radix_Sort {
public:
    explicit Radix_Sort(const std::vector<long long int> &nums) : m_Nums(nums), m_numsToSort(nums) {};

    long long int getMax();
    void countingSort(std::vector<long long int> &nums, int base, long long int exp);

    void begin_benchmark();

private:

    bool verifySort();
    void sort(int base);
    const std::vector<long long int> m_Nums;
    std::vector<long long int> m_numsToSort;
    std::chrono::system_clock::time_point startTime, endTime;
    int elapsedTime;
};


#endif //SORTING_ALGORITHMS_RADIXSORT_H
