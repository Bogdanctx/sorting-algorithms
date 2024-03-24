#include <iostream>
#include <fstream>
#include <vector>

#include "QuickSort.h"
#include "NativeSort.h"
#include "ShellSort.h"
#include "RadixSort.h"

int main() {
    const std::vector<std::string> tests = {
        "../test0.txt",
        "../test1.txt",
        "../test2.txt"
    };
    const std::vector<std::string> testInfo = {
        "N=10^8 | max=10^8",
        "N=10^8 | max=10^3",
        "N=10^3 | max=10^6"
    };

    int numberOfTests = (int) tests.size();

    for(int test = 0; test < numberOfTests; test++) {

        std::ifstream fin(tests[test]);
        int n;

        std::cout<<"Reading " << tests[test] << " input.\n";

        fin>>n;
        std::vector<int>nums(n);

        for(int i = 0; i < n; i++) {
            fin>>nums[i];
        }

        fin.close();

        std::cout<<"Done.\n\n";

        std::cout<<"Test #"<<test<< " (" << testInfo[test] << ") benchmarks:\n";

        // Aici punem algoritmii de sortare

        Radix_Sort radixSort{nums};
        radixSort.begin_benchmark();

        NativeSort nativeSort{nums};
        nativeSort.begin_benchmark();

        std::cout<<'\n';

        ShellSort shellSort{nums};
        shellSort.begin_benchmark();

        std::cout<<'\n';

        QuickSort quickSort{nums};
        quickSort.begin_benchmark();


        ///////////////

        std::cout<<"\n\n";
    }

    return 0;
}
