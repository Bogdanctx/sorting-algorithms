//
// Created by Bogdan on 3/24/2024.
//

#include "NativeSort.h"
#include "utilities.h"

bool NativeSort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}

void NativeSort::begin_benchmark() {
    std::cout<<'\n';

    startTime = std::chrono::system_clock::now();

    std::cout<<"Native sort: Begin benchmark\n";

    std::sort(m_numsToSort.begin(), m_numsToSort.end());

    elapsedTime = Utilities::getElapsedSeconds(startTime);
    bool wasSorted = verifySort();

    if(!wasSorted) {
        std::cout<<"Native sort: Could not sort.";
    }
    else {
        std::cout<<"Native sort: Sorting finished in " << elapsedTime << " seconds.";
    }

    std::cout<<'\n';
}