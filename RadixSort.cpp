//
// Created by Radu on 3/24/2024.
//

#include "RadixSort.h"

bool Radix_Sort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}

int Radix_Sort::getMax(){
    int max = m_numsToSort[0];
    for (int i = 1; i < m_numsToSort.size(); i++) {
        if (m_numsToSort[i] > max) {
            max = m_numsToSort[i];
        }
    }
    return max;
}

void Radix_Sort::countingSort(std::vector<int>& arr, int base, int exp){
    std::vector<int> output(arr.size());
    std::vector<int> count(base, 0);
    for (size_t i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % base]++;
    }
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void Radix_Sort::sort(int base) {
    int max = getMax();
    for (long long int exp = 1; max / exp > 0; exp *= base) {
        countingSort(m_numsToSort, base, exp);
    }
}

void Radix_Sort::begin_benchmark() {
    bool wasSorted;


    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"\nRadix_Sort: Begin benchmark (base = 10)\n";
    sort(10);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"\nRadix_Sort: Could not sort.";
    }
    else {
        std::cout<<"\nRadix_Sort: Sorting finished in " << elapsedTime << " seconds.";
    }




    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"\nRadix_Sort: Begin benchmark (base = 2^16)\n";
    sort(65536);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"\nRadix_Sort: Could not sort\n";
    }
    else {
        std::cout<<"\nRadix_Sort: Sorting finished in " << elapsedTime << " seconds.\n";
    }

}
