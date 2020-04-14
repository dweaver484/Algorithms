#pragma once

#include <vector>
#include "SortBase.h"

class SelectSort : public SortBase {
public:
    SelectSort() : SortBase("SelectSort") {}
    virtual void Sort( vector<long> & v );
};

class InsertSort : public SortBase {
public:
    InsertSort() : SortBase("InsertSort") {}
    virtual void Sort( vector<long> & v );
};

class ShellSort : public SortBase {
public:
    ShellSort() : SortBase("ShellSort") {}
    virtual void Sort( vector<long> & v ); 
};

class MergeSort : public SortBase {
public:
    MergeSort() : SortBase("MergeSort") {}
    virtual void Sort( vector<long> & v ); 
};

class QuickSort : public SortBase {
public:
    QuickSort() : SortBase("QuickSort") {}
    virtual void Sort( vector<long> & v ) { Qsort( v, 0, v.size()-1); } 
private:
    void Qsort( vector<long> & v, size_t begin, size_t end);
};

