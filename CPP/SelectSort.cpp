#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

void SelectSort( vector<int> & v )
{
    for( int i=0; i < v.size(); ++i ) {
        int minIdx = i;
        for( int j=i+1; j < v.size(); ++j ) {
            if( v[j] < v[minIdx] ) {
                minIdx = j;
            }
        }
        if( minIdx != i ) {
            int tmp = v[i];
            v[i] = v[minIdx];
            v[minIdx] = tmp;
        }
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
    SelectSort(v);
    auto te = chrono::high_resolution_clock::now();
    PrintVector(v);
    auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
    cout << "SelectionSort execution time: " << duration.count() << " nS" << endl;

    return 0;
}
