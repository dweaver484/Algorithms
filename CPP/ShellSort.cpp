#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void ShellSort( vector<int> & v ) {
    int h = 1;
    while( h < v.size() / 3 ) h = 3 * h + 1;
    while( h > 0 ) {
        for( int i = h; i < v.size(); ++i ) {
            for( int j = i; j >= h && v[j-h] > v[j]; j-=h) {
                int tmp = v[j-h];
                v[j-h] = v[j];
                v[j] = tmp;
            }
        }
        h /= 3;
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
    ShellSort(v);
    auto te = chrono::high_resolution_clock::now();
    PrintVector(v);
    auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
    cout << "ShellSort execution time: " << duration.count() << " nS" << endl;

    return 0;
}

