//
// Created by Bogdan on 3/24/2024.
//

#ifndef SORTING_ALGORITHMS_NATIVESORT_H
#define SORTING_ALGORITHMS_NATIVESORT_H

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

class NativeSort {
public:
    explicit NativeSort(const std::vector<int> nums) : m_numsToSort(nums) {};

    void begin_benchmark();

private:
    bool verifySort();

    std::vector<int> m_numsToSort;
};


#endif //SORTING_ALGORITHMS_NATIVESORT_H
