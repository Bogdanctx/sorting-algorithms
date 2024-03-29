#include <iostream>
#include <vector>

#include "QuickSort.h"
#include "NativeSort.h"
#include "ShellSort.h"
#include "RadixSort.h"
#include "HeapSort.h"
#include "RadixIntSort.h"
#include "MergeSort.h"
#include "TimSort.h"
#include "MergeSortMirror.h"

#include "random.hpp"

int main() {
    // (size, nr_minim, nr_maxim)
    const std::vector<std::vector<long long int>> tests = {
            {100000000, 0, 100000000}, // N=10^8, min = 0, max=10^8 0)
            {100000000, 0, 1000}, // N=10^8, min = 0, max=10^3 1)
            {1000, 0, 1000000}, // N=10^3, min = 0, max=10^6 2)
            {100000000, -100000, 100000}, // N=10^8, min=-10^5, max=10^5 3)
            {100000000, 0, 1000000000000}, // N=10^8, min=0, max=10^12 4)
            {100000000, 0, 10000000000000000}, // N=10^8, min=0, max=10^16 5)
            {100000000, -1000000000000, 1000000000000}, // N=10^8, min=-10^12, max=10^12 6)
            {1000000000000, 0, 1000000} // N=10^12, min=0, max=10^6
    };
    const std::vector<std::string> testInfo = {
        "N=10^8, max=10^8",
        "N=10^8, max=10^3",
        "N=10^3, max=10^6",
        "N=10^8, max=10^5, min=-10^5",
        "N=10^8, max=10^12",
        "N=10^8, min=0, max=10^16",
        "N=10^8, min=-10^12, max=10^12"
    };

    int numberOfTests = (int) tests.size();
    const int specialTest = numberOfTests - 1; // testul cu id-ul cel mai mare va fi cel cu float-uri

    for(int test = 0; test < numberOfTests; test++) {
        long long int n = tests[test][0];
        long long int lowerBound = tests[test][1];
        long long int upperBound = tests[test][2];

        std::vector<long long int>nums(n);

        std::cout<<"Creating test #" << test << " input\n";

        for(long long int p = 0; p < n; p++) {
            nums[p] = effolkronium::random_static::get(lowerBound, upperBound);
        }

        std::cout<<"Done.\n\n";

        std::cout<<"############################################\n";
        std::cout<<"Test #"<<test<< " (" << testInfo[test] << ") benchmarks:\n";

        // Aici punem algoritmii de sortare

        QuickSort quickSort{nums};
        quickSort.begin_benchmark();

        std::cout<<'\n';


        NativeSort nativeSort{nums};
        nativeSort.begin_benchmark();

        std::cout<<'\n';

        ShellSort shellSort{nums};
        shellSort.begin_benchmark();

        ///////////////

        std::cout<<'\n';

        HeapSort heapsort{nums};
        heapsort.begin_benchmark();

        std::cout<<'\n';
        Radix_Int_Sort radixintsort{nums};
        radixintsort.begin_benchmark();

        std::cout<<"\n";

        Radix_Sort radixSort{nums};
        radixSort.begin_benchmark();

        ////////////////

        MergeSort mergesort{nums};
        mergesort.begin_benchmark();

        MergeSortMirror mergesortmirror{nums};
        mergesortmirror.begin_benchmark();

        TimSort timsort{nums};
        timsort.begin_benchmark();

        std::cout<<"############################################";
        std::cout<<"\n\n";
    }

    return 0;
}
