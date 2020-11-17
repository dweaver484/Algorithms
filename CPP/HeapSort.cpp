#include <chrono>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

inline void Swim( vector<int> &pq, size_t i ) {
    size_t j = i/2;
    while( i > 1 && pq[i] > pq[j] ) {
        swap(pq[i], pq[j]);
        i = j;
        j = i/2;
    }
}

inline void Sink( vector<int> &pq, size_t i, size_t n ) {
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

void HeapSort( vector<int> &v ) {
    for(auto i=v.size()/2; i>0; --i) {
        Sink(v, i, v.size());
    }
    auto n = v.size();
    while(n > 2) {
        swap(v[1], v[--n]);
        Sink(v, 1, n);
    }
}

void HeapSort2( vector<int> &v ) {
    for(size_t i=1; i<v.size(); ++i) {
        Swim(v, i);
    }
    auto n = v.size();
    while(n > 2) {
        swap(v[1], v[--n]);
        Sink(v, 1, n);
    }
}

void PrintVector( vector<int> v ) {
    cout << endl;
    for( auto & i : v ) cout << i << " ";
    cout << endl;
}

void Test(void (*sf)(vector<int> &)) {
    //vector<int> v = {0, 20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10};
    vector<int> v = {0, 6, 12, 5, 6, 14, 8, 7, 1, 10, 8, 4, 14, 7, 9, 3};
    PrintVector(v);
    auto ts = chrono::high_resolution_clock::now();
    sf(v);
    auto te = chrono::high_resolution_clock::now();
    PrintVector(v);
    auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
    cout << "HeapSort execution time: " << duration.count() << " nS" << endl;
}

int main() {
    Test(HeapSort);
    Test(HeapSort2);
    return 0;
}

