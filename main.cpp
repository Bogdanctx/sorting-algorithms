#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "random.hpp"
#include <random>

class QuickSort {
public:
    explicit QuickSort(const std::vector<int> nums) : m_Nums(nums), m_numsToSort(nums) {};

    static int pivotMediana(int left, int right, std::vector<int> &nums);
    static int pivotRandom(int left, int right, std::vector<int> &nums);
    static int pivotRightest(int left, int right, std::vector<int> &nums);

    void begin_benchmark();

private:
    enum pivotTypes {
        pt_Mediana = 0,
        pt_Random = 1,
        pt_Rightest = 2
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

int QuickSort::pivotMediana(int left, int right, std::vector<int> &nums) {
    int a = nums[left], b = nums[(left+right)/2], c = nums[right];
    int index = std::max(std::min(a,b), std::min(std::max(a,b), c));
    int pivot = nums[index];
    int temp = left - 1;

    for(int j = left; j <= right - 1; j++) {
        if(nums[j] <= pivot) {
            ++temp;
            std::swap(nums[temp], nums[j]);
        }
    }

    ++temp;
    std::swap(nums[temp], nums[right]);
    return temp;
}

int QuickSort::pivotRightest(int left, int right, std::vector<int> &nums) {
    int pivot = nums[right];
    int temp = left - 1;

    for(int j = left; j <= right - 1; j++) {
        if(nums[j] <= pivot) {
            ++temp;
            std::swap(nums[temp], nums[j]);
        }
    }

    ++temp;
    std::swap(nums[temp], nums[right]);
    return temp;
}

int QuickSort::pivotRandom(int left, int right, std::vector<int> &nums) {
    int index = left + rand() % (right-left+1);
    int pivot = nums[index];
    int temp = left - 1;

    for(int j = left; j <= right - 1; j++) {
        if(nums[j] <= pivot) {
            ++temp;
            std::swap(nums[temp], nums[j]);
        }
    }

    ++temp;
    std::swap(nums[temp], nums[right]);
    return temp;
}


void QuickSort::sort(const int left, const int right, QuickSort::pivotTypes pt) {
    if(left >= right) {
        return;
    }
    else {
        int pivot;

        switch (pt) {
            case pivotTypes::pt_Rightest:
            {
                pivot = pivotRightest(left, right, m_numsToSort);
                break;
            }
            case pivotTypes::pt_Random:
            {
                pivot = pivotRandom(left, right, m_numsToSort);
                break;
            }
            case pivotTypes::pt_Mediana:
            {
                pivot = pivotMediana(left, right, m_numsToSort);
                break;
            }
            default:
                break;
        }

        sort(left, pivot - 1, pt);
        sort(pivot + 1, right, pt);
    }
}

void QuickSort::begin_benchmark() {
    std::chrono::system_clock::time_point startTime, endTime;
    int elapsedTime;

    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = numarul cel mai din dreapta)\n";
    sort(0, m_numsToSort.size() - 1, pivotTypes::pt_Rightest);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    for(int i: m_numsToSort) {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';

    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();

    std::cout<<"Quicksort: Begin benchmark (pivot = random)\n";
    sort(0, m_numsToSort.size() - 1, pivotTypes::pt_Random);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();

    for(int i: m_numsToSort) {
        std::cout<<i<<' ';
    }

    std::cout<<"\n";

    m_numsToSort = std::vector<int>(m_Nums);
    startTime = std::chrono::system_clock::now();
    std::cout<<"Quicksort: Begin benchmark (pivot = mediana din 3)\n";
    sort(0, m_numsToSort.size() - 1, pivotTypes::pt_Mediana);
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    for(int i: m_numsToSort) {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';


}

int main() {
    srand(time(nullptr));
    std::ifstream fin("../input.txt");

    int n, nr;
    std::vector<int> nums;

    fin>>n;
    for(int i = 0; i < n; i++) {
        fin>>nr;
        nums.push_back(nr);
    }

    QuickSort quickSort(nums);

    quickSort.begin_benchmark();

    fin.close();
    return 0;
}