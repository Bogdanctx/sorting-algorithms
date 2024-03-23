#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "random.hpp"

class QuickSort {
public:
    explicit QuickSort(const std::vector<int> nums) : m_Nums(nums), m_numsToSort(nums) {};

    int partition(int left, int right, std::vector<int> &nums);

    void begin_benchmark();

private:
    enum pivotTypes {
        pt_Random = 1,
        pt_Rightest = 2,
        pt_Mediana3 = 3
    };

    bool verifySort();
    void sort(const int left, const int right, pivotTypes pt);
    const std::vector<int> m_Nums;
    std::vector<int> m_numsToSort;
};

bool QuickSort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}

int QuickSort::partition(int left, int right, std::vector<int> &nums) {
    int i = left - 1;
    int pivot = nums[right];

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


void QuickSort::sort(const int left, const int right, QuickSort::pivotTypes pt) {
    if(left < right) {
        int pivotIndex;

        switch (pt) {
            case pivotTypes::pt_Random:
            {
                pivotIndex = left + effolkronium::random_static::get(0, right-left);
                std::swap(m_numsToSort[right], m_numsToSort[pivotIndex]);
                break;
            }
            case pivotTypes::pt_Mediana3:
            {
                int a = m_numsToSort[left];
                int b = m_numsToSort[(left+right)/2];
                int c = m_numsToSort[right];

                int mediana = std::max(std::min(a,b), std::min(std::max(a,b),c));

                if(mediana == a) pivotIndex = left;
                if(mediana == b) pivotIndex = (left+right)/2;
                if(mediana == c) pivotIndex = right;

                std::swap(m_numsToSort[right], m_numsToSort[pivotIndex]);
                break;

                break;
            }
        }

        int part = partition(left, right, m_numsToSort);

        sort(left, part - 1, pt);
        sort(part + 1, right, pt);
    }
}

void QuickSort::begin_benchmark() {
    std::chrono::system_clock::time_point startTime, endTime;
    int elapsedTime;
    bool wasSorted = true;


    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = random)\n";
    sort(0, m_numsToSort.size() - 1, pivotTypes::pt_Random);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Quicksort: Could not sort\n";
    }
    else {
        std::cout<<"Quicksort: Sorting finished in " << elapsedTime << " seconds.\n";
    }




    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = mediana din 3)\n";
    sort(0, m_numsToSort.size() - 1, pivotTypes::pt_Mediana3);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Quicksort: Could not sort\n";
    }
    else {
        std::cout<<"Quicksort: Sorting finished in " << elapsedTime << " seconds.\n";
    }


    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = element din partea dreapta)\n";
    sort(0, m_numsToSort.size() - 1, pivotTypes::pt_Rightest);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"Quicksort: Could not sort\n";
    }
    else {
        std::cout<<"Quicksort: Sorting finished in " << elapsedTime << " seconds.\n";
    }
}

int main() {
    std::ifstream fin("../test1.txt");

    int n, nr;
    std::vector<int> nums;

    fin>>n;
    for(int i = 0; i < n; i++) {
        fin>>nr;
        nums.push_back(nr);
    }

    std::cout<<"Am citit input-ul\n";

    QuickSort quickSort(nums);

    quickSort.begin_benchmark();

    fin.close();
    return 0;
}
