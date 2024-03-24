//
// Created by Bogdan on 3/24/2024.
//

#include "NativeSort.h"

bool NativeSort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}

void NativeSort::begin_benchmark() {
    std::chrono::system_clock::time_point startTime, endTime;
    int elapsedTime;

    startTime = std::chrono::system_clock::now();
    std::cout<<"Native sort: Begin benchmark\n";
    std::sort(m_numsToSort.begin(), m_numsToSort.end());
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    bool wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Native sort: Could not sort.";
    }
    else {
        std::cout<<"Native sort: Sorting finished in " << elapsedTime << " seconds.";
    }
}