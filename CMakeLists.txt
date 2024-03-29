cmake_minimum_required(VERSION 3.26)
project(sorting-algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(sorting-algorithms main.cpp
        MergeSort.h
        MergeSort.cpp
        QuickSort.h
        QuickSort.cpp
        NativeSort.h
        NativeSort.cpp
        ShellSort.h
        ShellSort.cpp
        RadixSort.h
        RadixSort.cpp
        HeapSort.h
        HeapSort.cpp
        RadixIntSort.h
        RadixIntSort.cpp
        TimSort.h
        TimSort.cpp
        MergeSortMirror.cpp
        MergeSortMirror.h
        MergeSortIfState.cpp
        MergeSortIfState.h
        utilities.h)
