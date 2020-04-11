#pragma once

#include <vector>
#include "SortBase.h"

class SelectSort : public SortBase {
public:
    SelectSort() : SortBase("SelectSort") {}
    virtual void Sort( vector<int> & v );
};

class InsertSort : public SortBase {
public:
    InsertSort() : SortBase("InsertSort") {}
    virtual void Sort( vector<int> & v );
};

class ShellSort : public SortBase {
public:
    ShellSort() : SortBase("ShellSort") {}
    virtual void Sort( vector<int> & v ); 
};

class MergeSort : public SortBase {
public:
    MergeSort() : SortBase("MergeSort") {}
    virtual void Sort( vector<int> & v ); 
};


