#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void MergeSort( vector<int> & v ) {
    // split array
    // call MergeSort on each half
    if( v.size() < 2 ) return;
    auto mid = v.size()/2;
    vector<int> v1(v.begin(), v.begin() + mid);
    vector<int> v2(v.begin() + mid, v.end());
    MergeSort(v1);
    MergeSort(v2);
    // merge the arrays
    // This is actually SLOWER (only tested with small array): merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] <= v2[j])
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

void PrintVector( vector<int> v ) {
    cout << endl;
    for( auto & i : v ) cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10};
    PrintVector(v);
    auto ts = chrono::high_resolution_clock::now();
    MergeSort(v);
    auto te = chrono::high_resolution_clock::now();
    PrintVector(v);
    auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
    cout << "ShellSort execution time: " << duration.count() << " nS" << endl;

    return 0;
}

