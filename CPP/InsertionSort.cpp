#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void InsertionSort( vector<int> & v ) {

    for( int i = 1; i < v.size(); ++i ) {
        if( v[i-1] > v[i] ) {
            int tmp = v[i-1];
            v[i-1] = v[i];
            v[i] = tmp;
            for( int j = i-1; j > 0 && v[j-1] > v[j]; --j) {
                tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
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
    InsertionSort(v);
    auto te = chrono::high_resolution_clock::now();
    PrintVector(v);
    auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
    cout << "InsertionSort execution time: " << duration.count() << " nS" << endl;

    return 0;
}

