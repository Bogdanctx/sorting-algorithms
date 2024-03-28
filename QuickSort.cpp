//
// Created by Bogdan on 3/24/2024.
//

#include "QuickSort.h"


bool QuickSort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}

int QuickSort::partition(const int left, const int right, std::vector<long long int> &nums) {
    int i = left - 1;
    long long int pivot = nums[right];

    for(int j = left; j <= right - 1; j++) {
        if(nums[j] <= pivot) {
            ++i;
            std::swap(nums[i], nums[j]);
        }
    }

    ++i;
    std::swap(nums[i], nums[right]);
    return i;
}

void QuickSort::sort(int left, int right, const QuickSort::pivotTypes pt) {
    std::stack<std::pair<int, int>> st;

    st.emplace(left, right);

    while(!st.empty()) {
        endTime = std::chrono::system_clock::now();
        elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();

        if(elapsedTime >= 65) {
            return;
        }

        const std::pair<int, int> stackTop = st.top();
        st.pop();
        left = stackTop.first;
        right = stackTop.second;

        if(left >= right) {
            continue;
        }

        long long int pivotIndex;

        switch (pt) {
            case pivotTypes::pt_Random:
            {
                pivotIndex = left + effolkronium::random_static::get(0, right-left);
                std::swap(m_numsToSort[right], m_numsToSort[pivotIndex]);
                break;
            }
            case pivotTypes::pt_Mediana3:
            {
                const long long int a = m_numsToSort[left];
                const long long int b = m_numsToSort[(left+right)/2];
                const long long int c = m_numsToSort[right];

                const long long int mediana = std::max(std::min(a,b), std::min(std::max(a,b),c));

                if(mediana == a) pivotIndex = left;
                if(mediana == b) pivotIndex = (left+right)/2;
                if(mediana == c) pivotIndex = right;

                std::swap(m_numsToSort[right], m_numsToSort[pivotIndex]);

                break;
            }
            default:
                break;
        }

        int part = partition(left, right, m_numsToSort);

        st.emplace(left, part - 1);
        st.emplace(part + 1, right);
    }
}

void QuickSort::begin_benchmark() {
    bool wasSorted;

    std::cout<<'\n';
    m_numsToSort = std::vector<long long int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = random)\n";
    sort(0, (int) m_numsToSort.size() - 1, pivotTypes::pt_Random);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Quicksort: Could not sort.\n";
    }
    else {
        std::cout<<"Quicksort: Sorting finished in " << elapsedTime << " seconds.\n";
    }
    std::cout<<'\n';

    std::cout<<'\n';
    m_numsToSort = std::vector<long long int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = mediana din 3)\n";
    sort(0, (int) m_numsToSort.size() - 1, pivotTypes::pt_Mediana3);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Quicksort: Could not sort\n";
    }
    else {
        std::cout<<"Quicksort: Sorting finished in " << elapsedTime << " seconds.\n";
    }
    std::cout<<'\n';

    std::cout<<'\n';
    m_numsToSort = std::vector<long long int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = elementul din dreapta)\n";
    sort(0, (int) m_numsToSort.size() - 1, pivotTypes::pt_Rightest);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Quicksort: Could not sort\n";
    }
    else {
        std::cout<<"Quicksort: Sorting finished in " << elapsedTime << " seconds.\n";
    }
    std::cout<<'\n';

}
