#include <chrono>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

#include "SortingAlgos.h"

using namespace std;

void PrintVector( string msg, vector<int> v ) {
    cout << msg;
    for( auto & i : v ) cout << i << " ";
    cout << endl;
}

void VerifySort( vector<int> v ) {
    for( int i = 1; i < v.size(); ++i ) {
        if( v[i-1] > v[i] ) {
            cout << "FAILED" << endl;
            return;
        }
    }
    cout << "PASSED" << endl;
}

vector<int> GenerateTestData( int num ) {
    vector<int> v(num);
    int sampleSize = num;
    while( num-- ) {
        v[num] = rand() / (RAND_MAX / sampleSize);
    }
    return v;
}

int main()
{
    cout << endl;
    vector<shared_ptr<SortBase>> vSA { make_shared<SelectSort>(), make_shared<InsertSort>(), make_shared<ShellSort>() };
    //vector<int> v = {20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10};
    vector<int> v = GenerateTestData(100);
    vector<int> test;
    for( auto pSA : vSA ) {
        test = v; // Make a copy
        PrintVector( "\nIN: ", test );
        auto ts = chrono::high_resolution_clock::now();
        pSA->Sort( test );
        auto te = chrono::high_resolution_clock::now();
        PrintVector( "OUT: ", test );
        VerifySort( test );
        auto duration = chrono::duration_cast<chrono::nanoseconds>(te - ts);
        cout << pSA->GetName() << "execution time: " << duration.count() << " nS" << endl;
    }
    return 0;
}


