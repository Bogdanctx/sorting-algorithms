//
// Created by Bogdan on 3/24/2024.
//

#include "ShellSort.h"
#include "utilities.h"

void ShellSort::sort() {
    int n = m_numsToSort.size();
    for(int gap = n / 2; gap > 0; gap = gap / 2) {
        if(Utilities::isTle(startTime)) {
            return;
        }

        for(int i = gap; i < n; i++) {
            long long int temp = m_numsToSort[i];
            int j;

            for(j = i; j >= gap && m_numsToSort[j-gap] > temp; j -= gap) {
                m_numsToSort[j] = m_numsToSort[j - gap];
            }

            m_numsToSort[j] = temp;
        }
    }
}

void ShellSort::begin_benchmark() {
    std::cout<<'\n';

    startTime = std::chrono::system_clock::now();

    std::cout<<"Shellsort: Begin benchmark\n";

    sort();

    elapsedTime = Utilities::getElapsedSeconds(startTime);

    bool wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Shellsort: Could not sort.";
    }
    else {
        std::cout<<"Shellsort: Sorting finished in " << elapsedTime << " seconds.";
    }

    std::cout<<'\n';
}

bool ShellSort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}