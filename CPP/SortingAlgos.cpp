#include "SortingAlgos.h"
#include <iostream>
#include <iterator>

using namespace std;

void SelectSort::Sort( vector<long> & v )
{
    for( long i=0; i < v.size(); ++i ) {
        long minIdx = i;
        for( long j=i+1; j < v.size(); ++j ) {
            if( LessThan(v[j], v[minIdx]) ) {
                minIdx = j;
            }
        }
        if( minIdx != i ) {
            Exchange(v[i], v[minIdx]);
        }
    }
}

void InsertSort::Sort( vector<long> & v ) {

    for( long i = 1; i < v.size(); ++i ) {
        if( LessThan(v[i], v[i-1]) ) {
            Exchange(v[i], v[i-1]);
            for( long j = i-1; j > 0 && LessThan(v[j], v[j-1]); --j) {
                Exchange(v[j], v[j-1]);
            }
        }
    }
}

void ShellSort::Sort( vector<long> & v ) {
    long h = 1;
    while( h < v.size() / 3 ) h = 3 * h + 1;
    while( h > 0 ) {
        for( long i = h; i < v.size(); ++i ) {
            for( long j = i; j >= h && LessThan(v[j], v[j-h]); j-=h) {
                Exchange(v[j], v[j-h]);
            }
        }
        h /= 3;
    }
}

void HeapSort::Sort( vector<long> & v ) {
    for(auto i=v.size()/2; i>0; --i) {
        Sink(v, i, v.size());
    }
    auto n = v.size();
    while(n > 2) {
        swap(v[1], v[--n]);
        Sink(v, 1, n);
    }
}
    
void HeapSort2::Sort( vector<long> & v ) {
    for(auto i=1; i<v.size(); ++i) {
        Swim(v, i);
    }
    auto n = v.size();
    while(n > 2) {
        swap(v[1], v[--n]);
        Sink(v, 1, n);
    }
}

void MergeSort::MSort( vector<long> & v ) {
    if( v.size() < 2 ) return;
    auto mid = v.size()/2;
    vector<long> v1(v.begin(), v.begin() + mid);
    vector<long> v2(v.begin() + mid, v.end());
    MSort(v1);
    MSort(v2);
    // merge the arrays
    // This is actually FASTER than using std::merge() (only tested with small array): merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
    // Using array indexing is also a little FASTER than using iterators (again only tested for small array [20]).
    long i = 0;
    long j = 0;
    long k = 0;
    while(i < v1.size() && j < v2.size()) {
        if (!LessThan(v2[j], v1[i])) // v1[i] <= v2[j])
            v[k++]=v1[i++];
        else
            v[k++]=v2[j++];
    }
    if(i < v1.size()) {
        while(i < v1.size())
            v[k++]=v1[i++];
    }
    else {
        while(j < v2.size())
            v[k++]=v2[j++];
    }
}

void MergeSort2::Sort( vector<long> & v ) {
    if( v.size() < 2 ) return;
    auto mid = v.size()/2;
    vector<long> v1(v.begin(), v.begin() + mid);
    vector<long> v2(v.begin() + mid, v.end());
    Sort(v1);
    Sort(v2);
    // merge the arrays
    // This is actually FASTER than using std::merge() (only tested with small array): merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
    // Using array indexing is also a little FASTER than using iterators (again only tested for small array [20]).
    long i = 0;
    long j = 0;
    long k = 0;
    while(i < v1.size() && j < v2.size()) {
        if (!LessThan(v2[j], v1[i])) // v1[i] <= v2[j])
            v[k++]=v1[i++];
        else
            v[k++]=v2[j++];
    }
    if(i < v1.size()) {
        while(i < v1.size())
            v[k++]=v1[i++];
    }
    else {
        while(j < v2.size())
            v[k++]=v2[j++];
    }
}

void QuickSort::Qsort( vector<long> & v, long start, long end ) {
    if( start >= end ) return;
    long i = start;
    long j = end + 1;
    long piv = v[start];
    long tmp;
    while(true) {
        while(v[++i] < piv)  if( i >= end ) break;
        while(v[--j] > piv)  if( j <= start ) break;
        if( j <= i ) break;
        tmp = v[i]; v[i] = v[j]; v[j] = tmp;
    }
    tmp = v[j]; v[j] = v[start]; v[start] = tmp;
    Qsort( v, start, j-1);
    Qsort( v, j+1, end);
}

// Uses swap instead of tmp variable. Using swap is a little slower than using tmp variable.
void QuickSortS::Qsort( vector<long> & v, long start, long end ) {
    if( start >= end ) return;
    long i = start;
    long j = end + 1;
    long piv = v[start];
    while(true) {
        while(v[++i] < piv)  if( i >= end ) break;
        while(v[--j] > piv)  if( j <= start ) break;
        if( j <= i ) break;
        swap(v[i], v[j]);
    }
    swap(v[start], v[j]);
    Qsort( v, start, j-1);
    Qsort( v, j+1, end);
}

// HackerRank : Handles already sorted data better. Takes pivot from middle 
// element (data doesn't need to be shuffled before starting).
void QuickSortH::Qsort( vector<long> & v, long start, long end ) {
    if( start >= end ) return;
    long left = start;
    long right = end;
    long piv = v[(start+end)/2];
    long tmp;
    while(left <= right) {
        while(v[left] < piv) ++left;
        while(v[right] > piv) --right;
        if(left <= right) {
            tmp = v[left]; v[left++] = v[right]; v[right--] = tmp;
        }
    }
    Qsort( v, start, left - 1);
    Qsort( v, left, end);
}

// Use std::partition : Handles already sorted data better. Takes pivot from middle 
// element (data doesn't need to be shuffled before starting).
/*
template<class CIter>
void QuickSortP::Qsort( CIter first, CIter last ) {
    if( first == last ) return;
    auto p = *next(first, distance(first, last)/2);
    auto mid = partition(first, last, [p] (auto & em) { return em < p; });
    auto mid2 = partition(mid, last, [p] (auto & em) { return em == p; });
    Qsort(first, mid);
    Qsort(mid2, last);
}
*/

void QuickSort3Way::Qsort( vector<long> & v, long start, long end ) {
    if( start >= end ) return;
    long lt = start;
    long i = start + 1;
    long gt = end;
    long piv = v[start];
    long tmp;
    while(i <= gt) {
        if(v[i] < piv) {
            tmp=v[i]; v[i++]=v[lt]; v[lt++]=tmp;
        }
        else if(v[i] > piv) {
            tmp=v[i]; v[i]=v[gt]; v[gt--]=tmp;
        }
        else ++i;
    } // v[start..lt-1] < piv = v[lt..gt] < v[i..end]
    Qsort( v, start, lt - 1);
    Qsort( v, i, end);
}

void QuickSort3Way2::Qsort( vector<long> & v, long start, long end ) {
    if( start >= end ) return;
    long lt = start;
    long i = start + 1;
    long gt = end;
    long piv = v[start];
    while(i <= gt) {
        if(v[i] < piv) Exchange(v[i++], v[lt++]);
        else if(v[i] > piv) Exchange(v[i], v[gt--]);
        else ++i;
    } // v[start..lt-1] < piv = v[lt..gt] < v[i..end]
    Qsort( v, start, lt - 1);
    Qsort( v, i, end);
}


