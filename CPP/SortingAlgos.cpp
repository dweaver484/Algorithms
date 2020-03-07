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


