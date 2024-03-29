//
// Created by eciuc on 3/29/2024.
//

#include "TimSort.h"
#include "utilities.h"


void TimSort::InsertionSort(unsigned long long left, unsigned long long right)
{
    for (unsigned long long i = left + 1; i <= right; i++) {
        long long int temp = m_numsToSort[i];
        unsigned long long j = i - 1;
        while (j >= left && m_numsToSort[j] > temp) {
            m_numsToSort[j+1] = m_numsToSort[j];
            j--;
        }
        m_numsToSort[j+1] = temp;
    }
}


void TimSort::merge(unsigned long long st, unsigned long long mij, unsigned long long dr)
{
    unsigned long long s=st;
    unsigned long long m=mij + 1;
    unsigned long long i=st;
    while(s<=mij && m <=dr)
    {
        if(Utilities::isTle(startTime)) {
            return;
        }
        if(m_numsToSort[s]>m_numsToSort[m])
        {
            m_Numscopy[i++]=m_numsToSort[m];
            m++;
        }
        else
        {
            m_Numscopy[i++]=m_numsToSort[s];
            s++;
        }
    }
    while(s<=mij)
    {
        m_Numscopy[i++]=m_numsToSort[s];
        s++;
    }
    while(m<=dr)
    {
        m_Numscopy[i++]=m_numsToSort[m];
        m++;
    }
    for(s=st;s<=dr;s++)
    {
        m_numsToSort[s]=m_Numscopy[s];
    }
}

void TimSort::sort(unsigned long long n) {
    const int runsize = 32;
    for (unsigned long long i = 0; i < n; i += runsize)
        InsertionSort( i, std::min((i + runsize - 1), (n - 1)));

    for (unsigned long long size = runsize; size < n; size = 2 * size) {
        if(Utilities::isTle(startTime)) {
            return;
        }
        for (unsigned long long st = 0; st < n; st += 2 * size) {

            unsigned long long mij = st + size - 1;
            unsigned long long dr = std::min((st + 2 * size - 1), (n - 1));

            if (mij < dr)
                merge( st, mij, dr);
        }
    }
}

void TimSort::begin_benchmark() {
    std::cout<<'\n';
    startTime = std::chrono::system_clock::now();
    std::cout<<"TimSort: Begin benchmark\n";
    sort(m_numsToSort.size());
    endTime = std::chrono::system_clock::now();
    elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    bool wasSorted = verifySort();
    if(!wasSorted) {
        std::cout<<"TimSort: Could not sort.";
    }
    else {
        std::cout<<"TimSort: Sorting finished in " << elapsedTime << " seconds.";
    }
    std::cout<<'\n';
}

bool TimSort::verifySort() {
    for(int i = 1; i < m_numsToSort.size(); i++) {
        if(m_numsToSort[i] < m_numsToSort[i-1]) {
            return false;
        }
    }
    return true;
}
