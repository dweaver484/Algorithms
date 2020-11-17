#pragma once

//#include <typeinfo>
#include <algorithm>
#include <cstdlib>
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

class HeapSort : public SortBase {
public:
    HeapSort() : SortBase("HeapSort") {}
    virtual void Sort( vector<long> & v );
    virtual void Prep( vector<long> & v ) { v.insert(v.begin(),0); }
    virtual void Finish( vector<long> & v ) { v.erase(v.begin()); }
    inline void Sink( vector<long> &pq, size_t i, size_t n ) {
        size_t j = 2*i;
        while( j < n ) {
            if( j + 1 < n && pq[j] < pq[j+1] ) {
                ++j;
            }
            if( pq[i] < pq[j] ) {
                swap(pq[i], pq[j]);
                i=j;
                j=2*i;
            }
            else {
                break;
            }
        }
    }
};

class HeapSort2 : public SortBase {
public:
    HeapSort2() : SortBase("HeapSort2") {}
    virtual void Sort( vector<long> & v );
    virtual void Prep( vector<long> & v ) { v.insert(v.begin(),0); }
    virtual void Finish( vector<long> & v ) { v.erase(v.begin()); }
    inline void Swim( vector<long> &pq, size_t i ) {
        size_t j = i/2;
        while( i > 1 && pq[i] > pq[j] ) {
            swap(pq[i], pq[j]);
            i = j;
            j = i/2;
        }
    }
    inline void Sink( vector<long> &pq, size_t i, size_t n ) {
        size_t j = 2*i;
        while( j < n ) {
            if( j + 1 < n && pq[j] < pq[j+1] ) {
                ++j;
            }
            if( pq[i] < pq[j] ) {
                swap(pq[i], pq[j]);
                i=j;
                j=2*i;
            }
            else {
                break;
            }
        }
    }
};

class MergeSort : public SortBase {
public:
    MergeSort() : SortBase("MergeSort") {}
    virtual void Sort( vector<long> & v ) { MSort(v); }
private:
    void MSort( vector<long> &v );
};

class MergeSort2 : public SortBase {
public:
    MergeSort2() : SortBase("MergeSort2") {}
    virtual void Sort( vector<long> & v ); 
};

class QuickSort : public SortBase {
public:
    QuickSort() : SortBase("QuickSort") {}
    virtual void Sort( vector<long> & v ) { 
        //random_shuffle(v.begin(), v.end()/*, rand*/);
        Qsort( v, 0, static_cast<long>(v.size()-1));
    } 
private:
    void Qsort( vector<long> & v, long begin, long end);
};

class QuickSortS : public SortBase {
public:
    QuickSortS() : SortBase("QuickSortS") {}
    virtual void Sort( vector<long> & v ) { Qsort( v, 0, static_cast<long>(v.size()-1)); } 
private:
    void Qsort( vector<long> & v, long begin, long end);
};

class QuickSortH : public SortBase {
public:
    QuickSortH() : SortBase("QuickSortH") {}
    virtual void Sort( vector<long> & v ) { Qsort( v, 0, static_cast<long>(v.size()-1)); } 
private:
    void Qsort( vector<long> & v, long begin, long end);
};

class QuickSortP : public SortBase {
public:
    QuickSortP() : SortBase("QuickSortP") {}
    virtual void Sort( vector<long> & v ) { Qsort<std::vector<long int>::iterator>(v.begin(),v.end()); } 
private:
    template<class CIter>
    void Qsort( CIter first, CIter last) {
        if( first == last ) return;
        auto p = *next(first, distance(first, last)/2);
        auto mid = partition(first, last, [p] (auto & em) { return em < p; });
        auto mid2 = partition(mid, last, [p] (auto & em) { return em == p; });
        Qsort(first, mid);
        Qsort(mid2, last);
    }
};

class QuickSort3Way : public SortBase {
public:
    QuickSort3Way() : SortBase("QuickSort3Way") {}
    virtual void Sort( vector<long> & v ) { Qsort( v, 0, static_cast<long>(v.size()-1)); } 
private:
    void Qsort( vector<long> & v, long begin, long end);
};

class QuickSort3Way2 : public SortBase {
public:
    QuickSort3Way2() : SortBase("QuickSort3Way2") {}
    virtual void Sort( vector<long> & v ) { Qsort( v, 0, static_cast<long>(v.size()-1)); } 
private:
    void Qsort( vector<long> & v, long begin, long end);
};


