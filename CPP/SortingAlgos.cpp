#include "SortingAlgos.h"

using namespace std;

void SelectSort::Sort( vector<int> & v )
{
    for( int i=0; i < v.size(); ++i ) {
        int minIdx = i;
        for( int j=i+1; j < v.size(); ++j ) {
            if( LessThan(v[j], v[minIdx]) ) {
                minIdx = j;
            }
        }
        if( minIdx != i ) {
            Exchange(v[i], v[minIdx]);
        }
    }
}

void InsertSort::Sort( vector<int> & v ) {

    for( int i = 1; i < v.size(); ++i ) {
        if( LessThan(v[i], v[i-1]) ) {
            Exchange(v[i], v[i-1]);
            for( int j = i-1; j > 0 && LessThan(v[j], v[j-1]); --j) {
                Exchange(v[j], v[j-1]);
            }
        }
    }
}

void ShellSort::Sort( vector<int> & v ) {
    int h = 1;
    while( h < v.size() / 3 ) h = 3 * h + 1;
    while( h > 0 ) {
        for( int i = h; i < v.size(); ++i ) {
            for( int j = i; j >= h && LessThan(v[j], v[j-h]); j-=h) {
                Exchange(v[j], v[j-h]);
            }
        }
        h /= 3;
    }
}

void MergeSort::Sort( vector<int> & v ) {
    if( v.size() < 2 ) return;
    auto mid = v.size()/2;
    vector<int> v1(v.begin(), v.begin() + mid);
    vector<int> v2(v.begin() + mid, v.end());
    Sort(v1);
    Sort(v2);
    // merge the arrays
    // This is actually FASTER than using std::merge() (only tested with small array): merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
    // Using array indexing is also a little FASTER than using iterators (again only tested for small array [20]).
    int i = 0;
    int j = 0;
    int k = 0;
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


