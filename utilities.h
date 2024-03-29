//
// Created by bgd on 29.03.2024.
//

#ifndef SORTING_ALGORITHMS_UTILITIES_H
#define SORTING_ALGORITHMS_UTILITIES_H

#include <chrono>

class Utilities {
public:
    enum Constants {
        tleLimit = 80
    };


    static bool isTle(std::chrono::system_clock::time_point start_time) {
        std::chrono::system_clock::time_point crtTime = std::chrono::system_clock::now();
        int elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(crtTime - start_time).count();

        return elapsedTime > Constants::tleLimit;
    }

    static int getElapsedSeconds(std::chrono::system_clock::time_point start_time) {
        std::chrono::system_clock::time_point crtTime = std::chrono::system_clock::now();
        int elapsedTime = (int) std::chrono::duration_cast<std::chrono::seconds>(crtTime - start_time).count();

        return elapsedTime;
    }

};

#endif //SORTING_ALGORITHMS_UTILITIES_H
