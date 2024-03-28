#include <iostream>
#include <fstream>
#include <vector>

#include "QuickSort.h"
#include "NativeSort.h"
#include "ShellSort.h"
#include "RadixSort.h"
#include "random.hpp"
int main() {
    const std::vector<std::string> tests = {
        "../test0.txt",
        "../test1.txt",
        "../test2.txt",
        "../test3.txt",
        "../test4.txt",
        "../test5.txt"
    };
    const std::vector<std::string> testInfo = {
        "N=10^8 | max=10^8",
        "N=10^8 | max=10^3",
        "N=10^3 | max=10^6",
        "N=10^8 | max=10^5, min=-10^5",
        "N=10^8 | max=10^12",
        "TO DO"
    };

    /*std::ofstream fout(tests[4]);
    int p = 100000000;
    fout<<p<<'\n';
    for(int i = 0; i < p; i++) {
        fout<<effolkronium::random_static::get((long long int)0, (long long int)1000000000000)<<' ';
    }
    return 0;*/

    int numberOfTests = (int) tests.size();
    const int specialTest = numberOfTests - 1; // testul cu id-ul cel mai mare va fi cel cu float-uri

    for(int test = 0; test < numberOfTests; test++) {
        if(test==3) continue;
        std::ifstream fin(tests[test]);
        int n;

        std::cout<<"Reading " << tests[test] << " input.\n";

        fin>>n;
        std::vector<long long int>nums(n);

        if(test == specialTest) {
            for(int i = 0; i < n; i++) {
                double nr;
                fin>>nr;
                nums[i] = *reinterpret_cast<long long int*>(&nr);
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                fin>>nums[i];
            }
        }

        fin.close();

        std::cout<<"Done.\n\n";

        std::cout<<"############################################\n";
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

        std::cout<<"############################################";
        std::cout<<"\n\n";
    }

    return 0;
}
