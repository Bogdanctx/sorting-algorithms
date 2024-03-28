//
// Created by Owner on 3/28/2024.
//

#include "HeapSort.h"


bool HeapSort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}
void HeapSort::heapify_down(int i, int n) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    // Compare with left child
    if (left_child < n && m_numsToSort[left_child] > m_numsToSort[largest])
        largest = left_child;

    // Compare with right child
    if (right_child < n && m_numsToSort[right_child] > m_numsToSort[largest])
        largest = right_child;

    // Swap if necessary and continue heapifying down
    if (largest != i) {
        std::swap(m_numsToSort[i], m_numsToSort[largest]);
        heapify_down(largest, n);
    }
}

void HeapSort::build_max_heap() {
    int n = m_numsToSort.size();
    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_down(i, n);
}

void HeapSort::sort(){
    build_max_heap();

    int n = m_numsToSort.size();
    // Extract elements from the heap in sorted order
    for (int i = n - 1; i > 0; i--) {
        std::swap(m_numsToSort[0], m_numsToSort[i]); // Move current root to end
        heapify_down(0, i); // Max heapify the reduced heap
    }
}

void HeapSort::begin_benchmark() {
    bool wasSorted;
    std::cout<<"\n";
    startTime = std::chrono::system_clock::now();
    std::cout<<"HeapSort: Begin benchmark\n";
    sort();
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"HeapSort: Could not sort.";
    }
    else {

        std::cout<<"HeapSort: Sorting finished in " << elapsedTime << " seconds.";
    }
    std::cout<<"\n";
}

